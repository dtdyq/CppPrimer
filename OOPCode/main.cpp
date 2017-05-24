#include<iostream>
#include<string>
#include"Quote.h"
#include"Bulk_quote.h"
using namespace std;
//动态绑定：
double print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() <<
		" #sold: " << n << " total price: " << ret << endl;
	return ret;
}
//使用final阻止类的继承：
class Foo final {

};
/*
派生类到基类之间的转换只对指针或引用类型有效
基类到派生类不存在隐式类型转换

受保护的类成员只能被类本身和其派生类使用，派生类的成员或友元只能通过
派生类对象来访问基类的受保护成员

派生访问说明符的目的是控制派生类用户对基类成员的访问权限，即基类的成员在
以派生类的形式访问时，其访问权限即是派生访问说明符

使用struct的派生类默认继承是public的
而使用class的派生类默认是private的

可以使用using来改变基类成员在派生类中的访问权限

派生类可以隐藏基类的成员
如果要使用被隐藏了的基类成员，要使用作用域运算符：Base::mem

对于成员函数，派生类中只要定义了名称相同的函数，则隐藏基类的函数，而不管
参数是否相同
*/
class Base {
protected:
	int prot_mem = 0;
};
class Sneaky :public Base {
	friend void clobber(Sneaky&);
	friend void clobber(Base&);
	int j;
};
//正确：
void clobber(Sneaky& s) {
	s.j = s.prot_mem = -1;
}
//错误：要想访问Base的受保护成员，只能在Base中声明友元函数
//这种设计很容易理解：如果可以访问，则用户可以继承任何类，并声明友元
//从而访问基类的protected成员，这样就违反了protected成员不能被用户
//访问的原则
void clobber(Base& b) {
	//b.prot_mem = -2;不能访问
}
int main() {
	//使用作用于运算符强制回避虚函数：
	Quote*q = &Bulk_quote("ieqew",12,10,0.2);
	double pr = q->Quote::net_price(10);
	cout << pr << endl;
} 