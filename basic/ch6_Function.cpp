#include<iostream>
#include<string>
#include<cstdbool>
//函数的特殊用法
using namespace std;
//使用initializer_list传递任意参数；
void print(initializer_list<string> list) {
	cout << list.size() << endl;
	for (auto i = list.begin(); i != list.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}
//函数指针：
bool cmp(const string& s1, const string& s2) {
	return s1.size() > s2.size();
}
//使用函数指针作为参数传递
const string& getBigger(const string& s1, const string& s2,
	                    bool fp(const string& s1,const string& s2)) {
	if (fp(s1, s2) == 1) {
		return s1;
	}
	return s2;
}
int testFunction() {
	print({ "str","fwegfw","ifnqx" });
	//声明函数指针：
	bool (*fp)(const string& s1, const string& s2);
	/*
	最开头声明了函数的返回类型，第一个圆括号说明了fp是一个指向函数的指针
	圆括号不能去掉，否则会被解释为普通函数，返回bool*类型
	最后面申明了函数的参数类型
	*/
	//两种等价的函数指针赋值方式：返回类型和参数必须匹配
	fp = cmp;
	fp = &cmp;
	//两种等价的调用：
	bool b1 = fp("defew", "4wwe");
	bool b2 = (*fp)("dqo2xn", "qonxwetewe");
	cout << b1 << " " << b2 << endl;

	//将函数指针作为参数传递
	const string res = getBigger("efef", "qwdcwe", fp);
	cout << res << endl;
	return 0;
}