#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//打印引用：
template <typename T> string debug_rep(const T &t) {
	ostringstream ret;
	ret << t;
	return ret.str();
}
//打印指针：
template <typename T> string debug_rep(T* t) {
	ostringstream ret;
	ret <<  "pointer: " << t;
	if (t) {
		ret << " " << debug_rep(*t);
	}
	else {
		ret << "null pointer";
	}
	return ret.str();
}
//打印双引号包围的string：
string debug_rep(const string &s) {
	return "\"" + s + '"';
}
//可变参数模板：
template <typename T,typename ... Args>
void foo(const T &t, const Args&...rest) {
	//计算参数个数
	cout << sizeof...(rest) << endl;
}
//===============================================================
//用递归的方式打印出每一个元素：
template <typename T>ostream &print(ostream &os, const T &t) {
	return os << t;
}
template <typename T,typename ... Args>
ostream &print(ostream &os,const T& t, const Args&...args) {
	os << t << ",";
	return print(os, args...);//包扩展
}