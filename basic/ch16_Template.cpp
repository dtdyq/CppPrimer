#include<iostream>
using namespace std;
/*
c++模板：
*/
//非类型模板参数
template<unsigned N,unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]) {
	return strcmp(p1, p2);
}
//默认模板实参：
template<class T=int>
class Numeric {
	T val; 
};