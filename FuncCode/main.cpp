#include<iostream>
#include<string>
#include<vector>
#include<cstddef>
#include"src.h"
using namespace std;
int main() {
	//局部静态对象在调用完函数后，该值仍然有效：
	for (int i = 0; i < 10; i++) {
		cout << func_calls() << endl;
	}
	//对于数组：不能进行拷贝，使用数组时需要将其转换为指针
	//如果传递给一个函数的是一个数组，则会转换为指向第一个元素的指针
	print("wfonwe");
	char ch[] = "dwoenw";
	print(begin(ch), end(ch));
	print(ch, 6);

	//数组引用形参：
	char *ch1 = "dwhie";
	print(ch1);

	//使用可变长参数的函数：
	print_index(1, { "idew","wect","qonqtwxq","qxw" });

	//使用尾置返回类型：
	auto fun(int i)->int(*)[10];//!!!!!!!无法理解

	//使用默认实参：
	string sg = get_Str(12);
	cout << sg << endl;

	//函数指针:
	//函数仅由参数类型和返回类型决定，和函数名无关：
	//定义一个函数指针，参数为两个string，返回类型为bool
	bool (*fp)(const string& s1, const string& s2);
	fp = cmp_str;
	fp = &cmp_str;//和上面的等价
	bool cp = fp(string("dwef"), string("qwxin"));
	bool cpp = (*fp)(string("dwef"), string("qwxin"));//等价于上一条
	cout << cp << endl;

	//将函数作为形参：
	string (*getstr)(const string&s1, const string&s2,
		bool(*fp)(const string&s1, const string&s2));
	getstr = get_one;

	string sget = getstr(string("dercbqu"), string("exonqw"), fp);
	cout << sget << endl;
}