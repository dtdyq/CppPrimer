#include<iostream>
#include<string>
using namespace std;
//拷贝控制：
/*
1、拷贝构造函数 拷贝赋值运算符 移动构造函数 移动复制运算符 析构函数
*/
class Foo {
public:
	string val;
	//只能对具有合成版本的类成员函数使用default运算符
	Foo()=default;//默认构造函数
	/*
	第一个参数是自身类型的引用，且额外的参数都有默认值，则此构造函数是拷贝构造
	函数，一般应该是const的，且不应该是explicit的，合成的拷贝构造函数会依次拷贝
	被复制的对象的每个成员
	*/
	Foo(const Foo& f) {
		val = "copyInit";
	}//拷贝构造函数
	//拷贝赋值运算符：
	Foo& operator=(const Foo& f) {
		val = "=copy";
	}
	Foo(string& str) :val(str) {};
	//析构函数：函数体为空时等价于合成析构函数
	//合成析构函数不会delete对象的指针数据成员
	//**当一个类需要自定义析构函数时，那它也应该需要自定义拷贝赋值运算符和拷贝构造函数
	//一个类中拷贝赋值运算符和拷贝构造函数 往往要同时存在

	~Foo() {//成员按成员初始化顺序逆序销毁
		cout << "deconstructor" << endl;
	}
	/*
	调用析构函数的时机：
	变量离开其作用域
	对象被销毁时
	容器被销毁时，其元素被销毁
	对于动态分配的对象，使用delete时被销毁
	*/
};
//阻止拷贝：
struct Nocopy {
	Nocopy() = default;
	//阻止拷贝和赋值：
	//Nocopy() = delete;
	Nocopy& operator=(const Nocopy& cp) = delete;
	//析构函数不能是删除的函数成员：
	//~Nocopy() = delete;  error
};
void copy(string& str) {
	string& res=str;
	res="copy";
}
int TestCopyControl() {
	//直接初始化，是要求编译器使用普通的函数匹配，而拷贝初始化，要求编译器
	//将右侧运算对象拷贝到正在创建的对象中，甚至需要类型转换，拷贝初始化通常使用
	//拷贝构造函数完成，但有时也会使用移动构造函数进行拷贝初始化
	//拷贝初始化不仅在=运算中使用，还会在下列情况发生：
	//将一个对象作为实参传递给一个非引用类型的形参
	//从一个返回类型为非引用的函数返回一个对象
	//使用花括号对数组进行初始化等

	//直接初始化：
	string dot(12, 'd');
	string s(dot);
	//拷贝初始化：
	string s2 = dot;
	string s3 = "diqoifw";
	string s4 = string(12, 'd');
	//eg:
	Foo f1(string("init"));
	Foo f2 = f1;
	cout << f2.val << endl;
	string cop = "str";
	copy(cop);
	cout << cop << endl;
	
	{
		int k = 12;
	}//离开作用域时被销毁
	return 0;
}












