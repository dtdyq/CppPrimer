#include<iostream>
#include<string>
#include"strfunc.h"
using namespace std;
int main() {
	//string的初始化：
	//使用等于号时实际执行的是拷贝初始化：
	string s1 = "copy";
	//不使用等号时使用的是直接初始化：
	string s2("direct");
	string s3(12, 'i');
	//将上一条语句转化为拷贝初始化：
	string s4 = string(12, 'i');
	//相当于：
	string tmp(12, 'i');
	string s5 = tmp;
	//===================================================
	//string对象上的操作：
	//读写string对象
	string s="dqdwe";
	//cin >> s;//!遇到空格停止，并忽略前面的空格
	//cout << s << endl;
	//重复读取字符串
	//reads();
	//使用getline读取一行
	//readLine();
	//判断字符串长度，和是否为空：
	//size()函数返回的是string::size_type类型的数字，可使用auto
	auto len = s.size();
	if(!s.empty())
		cout << s.size() << endl;

	//两个string对象相加，注意不能两个字面量直接相加：
	string s6 = s1 + s2;
	//string s7 = "dwd" + 'wesds';   error!
	//字符串字面值和string是两种不同的对象

	//对string对象中的单个字符进行操作:
	cctypeTest();
	//c风格字符串的操作：
	char *ch1 = "aonqw";
	char *ch2 = "doneef";
	//比较字符串大小：
	cout << strcmp(ch1, ch2) << endl;
	//获取字符串长度：
	cout << strlen(ch1) << endl;
	//拼接两个字符串：
	//strcat(ch1, ch2);
	//strcpy(ch2, ch1);//将ch2拷贝给ch1

	//string和c风格字符串的转换：
	string str("hello");
	printf("%s\n", str.c_str());
}
