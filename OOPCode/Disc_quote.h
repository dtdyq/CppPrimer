#pragma once
#include<iostream>
#include<string>
#include"Quote.h"
//含有纯虚函数的类是抽象基类
class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price
		, std::size_t qty, double disc) :
		Quote(book, price), quantity(qty), discount(disc) {}
	//定义纯虚函数：
	double net_price(std::size_t n)const = 0;
protected:
	std::size_t quantity=0;//折扣适用的购买量
	double discount = 0.0;
};