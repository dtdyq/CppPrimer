#include<iostream>
#include<string>
#include"Sales_data.h"
//在类的外部定义构造函数：
Sales_data::Sales_data(istream& is) {
	read(is, *this);
}
//在类的外部定义成员函数
double Sales_data::avg_price()const {
	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;//返回对自身的引用
}
istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
ostream& print(ostream& os, const Sales_data& item) {
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}
Sales_data add(const Sales_data& s1, const Sales_data& s2) {
	Sales_data s = s1;
	s.combine(s2);
	return s;
}