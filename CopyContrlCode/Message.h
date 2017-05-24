#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string&s="") :context(s) {}
	Message(const Message&);
	//在最后放置引用限定符
	Message& operator=(const Message&)&;
	~Message();
	//移动构造函数和移动赋值运算符：
	Message(Message&&);
	Message& operator=(Message&&);
	//从给定Folder集合中添加或删除本Message：
	void save(Folder&);
	void remove(Folder&);
	
private:
	string context;//本消息的文本
	set<Folder*> folders;//包含本消息的folder
	//拷贝构造函数、拷贝赋值运算符和析构函数使用的工具函数：
	//将消息添加到指定参数的folder中：
	void add_to_Folder(const Message&);
	//从folders中的每个folder删除本消息
	void remove_from_Folders();
	//从本message移动folders指针，该函数在移动构造函数和移动赋值运算符中使用
	void move_Folders(Message *m);
};