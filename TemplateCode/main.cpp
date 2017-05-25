#include<iostream>
#include<string>
#include"Blob.h"
#include<utility>
#include"DebugDelete.h"
#include<list>
#include<type_traits>
#include"Override.cpp"
using namespace std;
//为类模板定义类型别名：
template<typename T> using twin = pair<T, T>;
/*
cpp模板和泛型编程
函数模板可以声明为inline、constexpr
函数模板和类模板成员函数的定义通常放在头文件里
模板类的static成员，每种实例对象公用一个
一个特定文件所需要的所有模板的声明通常一起放在文件的开头位置
*/
//非类型模板参数：模板被实例化时，非类型参数被用户提供的值所代替
//这些值必须是常量表达式
template <typename T>
int compare(const T&, const T&);

//定义函数模板特例化：
//特例化版本本质上是一个实例，而不是重载
template <>
int compare(const char* const &p1, const char* const &p2) {
	strcmp(p1, p2);
}

template <unsigned N,unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]) {
	return strcmp(p1, p2);
}
//当希望通知编译器一个名字表示类型时，必须使用关键字typename
/*
此段代码有错
template <typename T>
template T::value_type top(const T& c) {
	if (!c.empty()) {
		return c.top();
	}
	else {
		return typename T::value_type();
	}
}
*/
//可以为函数或类提供模板默认实参：
template <typename T,typename V=less<T>>
int compare(const T& t1, const T& t2, V f = V()) {
	if (f(t1, t2)) {
		return -1;
	}
	if (f(t2, t1)) {
		return 1
	}
	return 0; 
}
//每个模板类或模板函数可能不止在一处实例化，为了减少不必要的实例化，可进行
//如下声明，告知编译器不需要实例化此版本，因为在程序的其他地方已经有实例对象
extern template class Blob<int>;
//extern template int compare(const int&, const int&);

//指定显示模板实参：
template <typename T1,typename T2,typename T3>
T1 sum(T2, T3);
//该函数的第一个参数无法推断出类型，所以需要在使用的时候显式指定
//auto rt = sum<long>(i,j);
//显示模板参数按由左至右的顺序与对应的模版参数匹配，只有最右边的参数可以忽略
//而且要保证编译器能够推断出类型：下面的函数设计显得很糟糕：
template <typename T1, typename T2, typename T3>
T3 map(T2, T1);//使用时必须显式指定所有的参数类型

//使用尾置返回类型：
/*
该函数无法确定返回类型
template<template T>
? ? ? &fcn(T b, T e) {
	return *b;
}
需要使用下面的声明方式：
*/
template <typename T>
auto fcn(T b, T e)->decltype(*b) {
	return *b;
}
//也可以使用标准库模板类进行类型转换
template <typename T>
auto fcn2(T b, T e)->typename remove_reference<decltype(*b)>::type {
	return *b;
}
//=================================================
//fun的重载版本，传入模板函数时需要指定具体的类型
void fun(int(*fp)(const int&,const int&));
void fun(int(*fp)(const string&, const string&));

//如果一个函数参数是指向模板类型参数的的右值引用，他对应的实参的const
//属性和左值/右值属性都得以保持：
template <typename F,typename T1,typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {

}
//使用forward保持类型信息：
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
	fun(std::forward<T1>(t2), std::forward<T1>(t1));
}
int main() {
	int p = compare("hello", "hi");
	//int k = compare(12, 32);
	cout << p << endl;
	Blob<string> blob;
	blob.push_back("yg");
	cout << blob.back() << endl;

	twin<string> ts;

	unique_ptr<int, DebugDelete> up(new int, DebugDelete());

	list<const char*> li = { "qxeq","Qwqi" };
	Blobs<string> b(li.begin(), li.end());

	//函数指针和实参推断：
//	int(*fp)(const int&, const int&) = compare;
//	fun(compare<int>);

	string s1 = "hello";
	string&& s2 = std::move(s1);//引用折叠
	s2 = "java";
	cout << s1 << endl;

	//=======模板函数重载================
	string s("hiiiii");
	//编译器优先选择非模板函数
	cout << debug_rep(s) << endl;
	cout << debug_rep(&s) << endl;
}
