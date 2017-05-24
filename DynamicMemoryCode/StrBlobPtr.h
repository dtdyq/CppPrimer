#pragma once
#include"StrBlob.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//StrBlob的伴随指针类：
class StrBlob;
class StrBlobPtr {
public:
	StrBlobPtr() :curr(0) {};
	StrBlobPtr(StrBlob &a, size_t sz = 0);
	string& deref() const;
	StrBlobPtr& incr();//前缀递增
private:
	//如果检查成功，返回一个指向vector的shared_ptr
	shared_ptr<vector<string>>
		check(std::size_t, const std::string&) const;
	//保存weak_ptr，意味着底层vector可能会被销毁
	weak_ptr<vector<string>> wptr;
	size_t curr;//在数组中的当前位置
};