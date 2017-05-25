#pragma once
#include<iostream>
//类模板使用默认实参
template <typename T = int> class Numeric {
public:
	Numeric(T& t) :val(t) {}
private:
	T val;
};
/*
声明方式：
Numeric<> v;//默认为int
*/