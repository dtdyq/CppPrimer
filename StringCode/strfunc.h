#pragma once
#include<iostream>
#include<string>
#include<cctype>
using namespace std;
//读取未知数量的string：
int reads() {
	string tmp;
	while (cin >> tmp)
		cout << tmp << endl;
	return 0;
}
//使用getline读取一行，遇到换行符结束
int readLine() {
	string tmp;
	while (getline(cin, tmp)) {
		cout << tmp << endl;//读取到的字符串不包含换行符
	}
	return 0;
}
void cctypeTest() {
	//cctype中提供的函数：
	/*
	isalnum(a)   数字或字母
	isalpha(a)   字母
	iscntrl(a)   控制字符
	isdigit(a)   数字
	isgraph(a)   不是空格但可打印
	islower(a)
	isupper(a)
	isprint(a)   可打印，包括空格
	ispunct(a)   是标点符号
	isspace(a)   空白字符
	isxdigit(a)  十六进制
	tolower(a)   转为小写
	toupper(a)   转为大写
	*/
	//使用增强for循环遍历
	string str("traverse");
	for (auto c : str) {
		cout << c << " ";
	}
	cout << endl;
	//判断字符串中标点符号的数量：
	string str1("hello,ery!");
	decltype(str1.size()) count = 0;
	for (auto c : str1) {
		if (ispunct(c))
			++count;
	}
	cout << count << endl;

	//如果要改变字符串的内容则要使用引用类型
	string str2("this is a cpp code");
	for (auto &c : str2) {
		c = toupper(c);
	}
	cout << str2 << endl;

	//只处理字符串中的一部分字符
	//使用下标：
	string str4("some word!");
	str4[0] = toupper(str4[0]);//将首字母转换为大写
	cout << str4 << endl;
	//将第一个字符串转换为大写：
	for (decltype(str4.size()) it = 0;
		it != str4.size() && !isspace(str4[it]); ++it) {
		str4[it] = toupper(str4[it]);
	}
	cout << str4 << endl;
}