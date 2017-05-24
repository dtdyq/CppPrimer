#pragma once
#include<iostream>
#include<string>
using namespace std;
//定义行为像指针的类
//如果没有使用shared_ptr来自动管理内存，则应该使用类似引用计数的方式
//管理类中的指针
class HasPtrs {
public:
	HasPtrs(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtrs(const HasPtrs& hp):
		ps(hp.ps), i(hp.i), use(hp.use) {
		++*use;
	}
	HasPtrs& operator=(const HasPtrs& hp);
	void chgStr() {
		ps->append("---");
	}
	string get() {
		return *ps;
	}
private:
	string *ps;
	int i;
	size_t *use;//引用计数
};
//递增左侧运算对象的计数值
//递减右侧对象的计数值
HasPtrs& HasPtrs::operator=(const HasPtrs& hp) {
	++*use;//递增右侧
	if (--*use == 0) {//递减左侧，如果为0，删除指针
		delete ps;
		delete use;
	}
	ps = hp.ps;
	use = hp.use;
	i = hp.i;
	return *this;
}