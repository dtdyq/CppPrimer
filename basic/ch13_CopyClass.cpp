#include<iostream>
using namespace std;
//拷贝控制中的技巧
//定义行为像值的类：
class HasPtr {
private:
	string *ps;
	int val;
public:
	HasPtr(string &s = string()) :ps(new string(s)), val(0){};
	HasPtr(const HasPtr& p) :ps(new string(*p.ps)),val(0) {};
	HasPtr& operator=(const HasPtr& p);
	~HasPtr() {};
	friend void swap(HasPtr&, HasPtr&);
};
HasPtr& HasPtr::operator=(const HasPtr& p) {
	//注意要在销毁左侧运算对象的资源之前应该先拷贝右侧运算对象
	//以防止两者是同一个对象
	auto tmp = new string(*p.ps);//拷贝底层string
	delete ps;//释放旧内存
	ps = tmp;
	val = p.val;
	return *this;
}

//定义行为像指针的类：
//需要使用引用计数，以防止析构函数多次delete同一个指针成员：
class HasPtrP {
private:
	size_t *use;//指示多少个对象共享ps成员
	string *ps;
	int val;
public:
	HasPtrP(string &s = string()) :ps(new string(s)), val(0)
	            ,use(new size_t(1)){};
	HasPtrP(const HasPtrP& p) :ps(new string(*p.ps)), val(0)
		, use(p.use) {
		*use++;
	};//增加引用计数
	HasPtrP& operator=(const HasPtrP& p);
	~HasPtrP();
};
HasPtrP::~HasPtrP() {
	//引用计数器如果为0，则释放指针成员
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}
HasPtrP& HasPtrP::operator=(const HasPtrP& p) {
	++*p.use;//增加右侧对象的引用计数
	if (--*use == 0) {//递减本对象的引用计数，如果为0，则表示没有对象引用，直接删除
		delete ps;
		delete use;
	}
	ps = p.ps;
	val = p.val;
	use = p.use;
	return *this;
}
//一般管理资源的类都需要定义swap函数用于交换两个对象
inline void swap(HasPtr& p1, HasPtr& p2) {
	using std::swap;//需要添加此申明，以防止使用std中的swap函数
	swap(p1.ps, p2.ps);
	swap(p1.val, p2.val);
}
//使用swap来实现拷贝赋值运算符
/*
HasPtr& HasPtr::operator=(HasPtr p){
	swap(*this,p);
	return *this;

}
*/