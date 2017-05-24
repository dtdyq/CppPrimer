#include<iostream>
#include<string>
using namespace std;
/*
类通常有三种：
	行为像指针一样的类，这种类进行拷贝时会使用相同的底层数据结构
	行为像值一样的类，这种类进行拷贝时会生成独立的副本
	行为既不像值，也不像指针
*/
//像值一样的版本的额HasPtr
class HasPtr {
	friend void swap(HasPtr&,HasPtr&);
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) :ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr&);
	~HasPtr() {
		delete ps;
	};
	
private:
	string *ps;
	int i;
};
//编写赋值运算符时需要注意：
//如果将一个对象赋予它自身，赋值运算符必须能正确工作
//大多数赋值运算符组合了构造函数和析构函数的工作
HasPtr& HasPtr::operator=(const HasPtr& hp) {
	//下面两条语句顺序不能颠倒
	auto newp = new string(*hp.ps);
	delete ps;
	ps = newp;
	i = hp.i;
	return *this;
}
inline void swap(HasPtr& h1, HasPtr& h2) {
	using std::swap;//这句话是什么意思
	swap(h1.ps, h2.ps);//交换指针，而不是string中的数据
	swap(h1.i, h2.i);
}