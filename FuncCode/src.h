#pragma once
#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
//统计函数被调用次数
size_t func_calls() {
	static size_t count = 0;
	return ++count;
}
//管理指针形参的三种技术
//使用标记指定数组的长度：c风格的字符串
void print(char* c) {
	while (*c) {
		cout << *c++;
	}
	cout << endl;
}
//使用标准库规范：
void print(const char *beg, const char *end) {
	while (beg != end) {
		cout << *beg++;
	}
	cout << endl;
}
//显式传递代表数组大小的形参：
void print(const char * ch, int len) {
	int tmp = 0;
	while (tmp < len) {
		cout << ch[tmp++];
	}
	cout << endl;
}
//cpp中可以使用数组引用形参：
//注意以下差别：
//int *mx[10]     表示包含是个指向int型值的指针数组
//int (*mx)[10]   指向含有十个整数的数组的指针
void print(const char (&arr)[5]) {
	for (auto c : arr) {
		cout << c;
	}
	cout << endl;
}
//使用initializer_list实现可变长形参：
void print_index(int index, initializer_list<string> list) {
	if (index >= 0 && index < list.size()) {
		cout << *(list.begin() + index);
	}
}

//!不要返回局部对象的引用和指针：
//函数调用完后它所占用的空间也被释放
const string& manip() {
	string str;
	if (!str.empty()) {
		return str;//!error:返回对局部变量的引用
	}
	else {
		return "empty";//error:empty是一个局部变量
	}
}
//!!!!!!!!不太理解！！！！！！！！！！！！！！！！
//声明一个返回数组指针的函数：
int (*func(int i))[10]{
	int arr[10];
	for (int j = 0; j < 10; j++) {
		arr[j] = i;
	}
	return &arr;
}
//返回一个由count个c组成的string
string get_Str(int count=1, char c='-') {
	return string(count, c);
}
//比较两个string对象的长度
bool cmp_str(const string& s1, const string& s2) {
	return s1.size() == s2.size() ? 0 : 1;
}
//根据比较函数，获得值为真的一个字符串：
string get_one(const string&s1, const string&s2,
			bool (*fp)(const string&s1, const string&s2)) {
	if (fp(s1, s2)) {
		return s1;
	}
	return s2;
}