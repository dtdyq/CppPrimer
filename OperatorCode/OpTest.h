#pragma once
#include<iostream>
#include<string>
using namespace std;
class OpTest {
public:
	OpTest() = default;
	OpTest(const string& s) :ops(s) {}
	OpTest& operator=(const OpTest& o) {
		ops = o.ops;
		return *this;
	}
	//使用另一种初始化方式：
	OpTest& operator=(initializer_list<string> li);
	OpTest& operator+=(const OpTest& o) {
		ops += o.ops;
		return *this;
	}
	//定义下标运算符：通常应该重载：返回普通引用和常量引用：
	char& operator[](size_t n) {
		return ops[n];
	}
	const char& operator[](size_t n) const {
		return ops[n];
	}
	//递增递减运算符通常也应该定义为成员函数：
	//这里仅是示例，实际运用中应该定义的具有意义
	void operator--() {
		ops.substr(0, ops.size() - 1);
	}
	void operator++() {
		ops.substr(1, ops.size() - 1);
	}
	//为了区分前置和后置运算符，后置版本传入一个没有意义的int参数作为区分：
	void operator--(int);
	void operator++(int);
	//成员访问运算符：通常应该是类的成员
	const string& operator*()const {
		return ops;
	}
	const string& operator->()const {
		return ops;
	}
	string ops;
};
OpTest& OpTest::operator=(initializer_list<string> li) {
	for (auto it = li.begin(); it != li.end(); ++it) {
		ops += *it;
	}
	return *this;
}

//重载运算符<<:输入输出运算符必须是非成员函数(成员函数的第一个参数隐式地
//绑定该对象本身，而输入输出操作左侧运算对象是istream或ostream)
ostream& operator<<(ostream& os, const OpTest& op) {
	//执行输出...
	os << op.ops;
	//输出运算符应尽量减少格式化操作
	return os;
}
istream& operator>>(istream& is, OpTest& op) {
	//...
	//当读取操作方式错误时，输入运输符应该负责从错误中恢复
	is >> op.ops;
	if (!is) {
		op = OpTest();
	}
	return is;
}
//通常将算术和关系运算也定义为非成员函数，以允许对左侧和右侧的运算对象进行转换
OpTest& operator+(const OpTest& o1, const OpTest& o2) {
	OpTest op = o1;
	op += o2;
	return op;
}
bool operator==(const OpTest& o1, const OpTest& o2) {
	return o1.ops == o2.ops;
}
//定义了==，通常也应该定义！=
bool operator!=(const OpTest& o1, const OpTest& o2) {
	return o1.ops != o2.ops;
}

