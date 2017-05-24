#pragma once
#include<iostream>
#include<string>
class SmallInt {
public:
	SmallInt(int i = 0) :val(i) {}
	//定义类型转换运算符：没有返回类型，没有参数
	operator int()const {
		return val;
	}
	//显式的类型转换运算符，编译器不会自动执行这一类型转换：
	//这个时候需要使用static_cast<long>(args)进行显示转换
	explicit operator long()const {
		return val;
	}
private:
	size_t val;
};
/*
SmallInt si;
si=4;    将4隐式转换为smallint，然后调用构造函数
si+4;    将si隐式转换为int
*/