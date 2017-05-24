#pragma once
#include<iostream>
#include<string>
using namespace std;
class Sales_data {
	//友元函数：
	//在这些函数中可以访问该类的私有成员
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream& print(ostream&, const Sales_data&);
	friend istream& read(istream&, Sales_data&);
public:
	//构造器：总应该为类添加构造器：
	Sales_data() = default;//默认构造器，相当于相同合成构造器
	//构造函数初始值列表
	Sales_data(const string& s) :bookNo(s) {}
	Sales_data(const string& s, unsigned u, double re) :
		bookNo(s), units_sold(u), revenue(u*re) {}
	explicit Sales_data(istream&);
	//成员函数通过名为this的额外的隐式参数来访问调用它的那个对象
	//紧跟函数后面的const的意思是this是一个指向常量的指针，这样的成员函数
	//称为常量成员函数
	//常量对象、常量对象的引用或指针都只能调用常量成员函数
	string isbn() const { return this->bookNo;}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//非成员接口函数：
Sales_data add(const Sales_data&, const Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);