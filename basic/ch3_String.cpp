#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
//标准库类型string的使用：
using namespace std;
int testString() {
	//定义和初始化方法：
	string s1;//默认初始化
	string s2();//空字符串
	string s3(s1);//s3是s1的拷贝
	string s3p = s1;//同上
	string s4(12, 'c');//使用指定的连续值初始化
	string s5{ "string_type" };//推荐这样写
	string s6("direct");   //直接初始化
	string s7 = "copy";   //拷贝初始化

	//使用string读取控制台输入
	string sin = "this is a string.";
	//cin >> sin;       //遇到空白停止
	//cout << sin << endl;
	//getline(cin, sin);    //读取一整行，包括空白
	//cout << sin << endl;
	//string的长度：size_type类型：
	auto len = sin.size();
	decltype(sin.size()) le = sin.size();
	cout << len << " " << le << endl;

	//string对象可直接相加：
	string sap1 = "red";
	string sap2 = "blue " + sap1;
	cout << sap2 << endl;
	//两个字符串不能直接相加
	//string sap3 = "black" + "white";

	//cctype头文件中的函数：
	char c = 'c';
	isalnum(c);//判断是否是数字或字母
	isalpha(c);//判断是否是字母
	iscntrl(c);//是否是控制字符
	isdigit(c);//是否是数字
	isgraph(c);//不是空格但可打印时为真
	islower(c);//是否是小写字母
	isupper(c);//是否是大写字母
	isprint(c);//是否是可打印字符
	isspace(c);//是否是空白
	ispunct(c);//是否是标点符号
	isxdigit(c);//是否是十六进制数字
	tolower(c);//转化为小写
	toupper(c);//转化为大写
	
	//迭代方式：
	//使用for循环迭代
	for(auto& r:sin){
		if (islower(r)) {
			r=toupper(r);
		}
		if (ispunct(r)) {
			r = '-';
		}
    } 
	cout << sin << endl;
	//使用下标迭代：
	for (decltype(sin.size()) index = 0; 
	    index < sin.size() && sin[index] != ' '; ++index) {
		sin[index] = tolower(sin[index]);
	}
	cout << sin << endl;

	//string的其他类型函数：
	sin.assign("newstring");//指定新的字符串，替换原有字符串
	sin.append("append");
	string::size_type s=sin.capacity();//获取当前string的容量大小
	cout << s << endl;
	cout << sin << endl;
	//太简单懒得写了。。。

	//string和c标准的字符串进行转换：
	const char *ch = sin.c_str();
	printf("%s\n", sin.c_str());
	return 0;
}