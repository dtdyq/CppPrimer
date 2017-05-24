#pragma once
#include<iostream>
#include<memory>
#include<string>
using namespace std;
//动态内存管理类:只用来保存string的vector
class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);//拷贝构造函数
	StrVec& operator=(const StrVec&);//拷贝赋值运算符
	//移动构造函数：
	StrVec(StrVec&&)noexcept;
	StrVec& operator=(StrVec&&)noexcept;
	~StrVec();

	void push_back(const string&);
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	string* begin() const { return elements; }
	string*end()const { return first_free; }
private:
	//分配元素：
	static allocator<string> alloc;
	//被添加元素的函数使用：
	void chk_n_alloc() {
		if (size() == capacity()) {
			reallocate();
		}
	}
	//工具函数，被拷贝构造函数、赋值运算符，析构函数使用
	pair<string*, string*> alloc_n_copy(string*, string*);
	void free();//销毁元素并是否内存
	void reallocate();//获得更多内存并拷贝已有元素

	//指向首个元素：
	string* elements;
	string* first_free;//指向数组中第一个空闲元素的指针
	string* cap;//指向数组尾后位置的指针
};