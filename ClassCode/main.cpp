#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace std;
int main() {
	//隐式的类类型转换：
	Sales_data item = { "iso1221", 12, 10.0 };
	string null_book = "isk9121";
	//编译器会自动用给定的string构造一个Sales_data
	item.combine(null_book);
	//不过编译器只会进行一次类类型转换，以下的语句是错误的：
	//item.combine("dwdiw");
	//可以使用以下调用方式：
	item.combine(string("iiw2301"));
	item.combine(Sales_data("udw3212"));
	//!!!可以通过使用explicit关键字在构造器上来阻止隐式转换
	//以下的方法调用是错误的：
	//item.combine(cin);
	//不过explicit关键字只允许出现在类内的构造函数声明处，而且
	//explicit构造器只能使用直接初始化：
	Sales_data data(cin);
	//Sales_data date = cin;
	print(cout, item);
}