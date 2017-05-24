#pragma once
#include<iostream>
#include<string>
//定义基类：
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}

	std::string isbn()const { return bookNo; };
	virtual double net_price(std::size_t n) const {
		return n*price;
	}
	//基类通常都应该定义虚析构函数
	virtual ~Quote() = default;
	//静态成员是唯一的：
	static void staticmem();
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

