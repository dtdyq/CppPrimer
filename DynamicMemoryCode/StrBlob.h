#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include"StrBlobPtr.h"
using namespace std;

class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> li) :data(make_shared<vector<string>>(li)) {};
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &msg) { data->push_back(msg); }
	void pop_back();
	//访问元素：
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
	StrBlobPtr begin() { return StrBlobPtr(*this); }
	StrBlobPtr end() { 
		auto ret = StrBlobPtr(*this, data->size());
		return ret;
	}
private:
	shared_ptr<vector<string>> data;
	//如果data[i]不合法则会抛出一个异常
	void check(size_type i, const string &msg)const;
};
