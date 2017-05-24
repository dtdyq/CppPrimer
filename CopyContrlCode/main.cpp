#include<iostream>
#include<vector>
#include<string>
#include"HasPtrs.h"
using namespace std;
/*
定义类时，显示或隐式地在此类型上的拷贝、移动、赋值、销毁。
有五类特殊的成员函数来控制这些操作：
	拷贝控制函数
	拷贝赋值运算符
	移动构造函数
	移动赋值函数
	析构函数

---》：需要析构函数的类也需要拷贝和赋值操作
	合成析构函数不会delete一个指针数据成员
	拷贝操作和赋值操作往往同生同死

管理资源的类通常还需要定义名为swap的函数
*/
class Foo {
public:
	Foo()=default;//默认构造函数
    //拷贝构造函数：第一个参数是自身类型的引用，其余参数都有默认值
	//通常不应该时explicit的

	//拷贝初始化依靠拷贝构造函数或移动构造函数进行初始化
	//:将一个对象作为实参传递给非引用类型的形参、从一个返回类型为
	//非引用类型的函数返回一个对象、用花括号初始化一个数组中的元素或一个聚合类
	//的成员、使用等于号定义变量时，都会发生拷贝初始化
	Foo(const Foo&)=default;
	//赋值运算符通常应该返回一个指向其左侧运算对象的引用
	Foo& operator=(const Foo&)=default;//赋值运算符
	~Foo() {};//析构函数
};
//阻止拷贝：
//析构函数不能是删除的成员
class NoCopy {
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;//阻止拷贝
	NoCopy& operator=(const NoCopy&) = delete;//阻止赋值运算
};
int main() {
	vector<int> v1(10);//直接初始化
	//vector<int> v2 = 10;//错误，接受整形参数的构造器是explicit的
	HasPtrs ps("hahaha");
	HasPtrs ps2 = ps;
	ps.chgStr();
	
	cout << ps2.get() << endl;

	HasPtrs ps3("ooo");
	ps2 = ps3;
	cout << ps2.get() << endl;

	//右值引用：右值引用往往是临时的：
	int i = 12;
	int &&r = i*12;
	//使用标准库函数获得右值引用：
	int &&r2 = move(r);
}