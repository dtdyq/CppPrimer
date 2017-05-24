#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void initTest() {
	//vector的初始化：
	//初始化空的vector对象：
	vector<int> ivec;
	vector<int> ivec2 = ivec;//拷贝初始化
	vector<int> ivec3(ivec);//拷贝初始化
	//使用列表初始化
	vector<string> svec = { "e2dwqd","wegsw","qwxb" };
	//创建指定数量的元素：
	vector<int> ivec4(10, -1);
	//此时定义的是初始化的元素数量，值被默认初始化：
	vector<string> svec2(10);
}
void operatTest() {
	//向vector中添加元素：
	vector<string> vec;
	string tmp;
	while (cin >> tmp) {
		vec.push_back(tmp);
	}
	//!不能使用下标向vector中添加元素

	//使用迭代器访问vector中的元素
	vector<string>::iterator it = vec.begin();
	while (it != vec.end()) {
		cout << *it << endl;
	}
	//使用const_iterator时不能改变元素：
	vector<string>::const_iterator cit = vec.cbegin();
	auto cend = vec.cend();
}