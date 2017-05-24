#pragma once
#include<iostream>
#include<string>
#include"Quote.h"
#include"Disc_quote.h"
//将某个类用作基类时，该类必须已经被定义
class Bulk_quote : public Disc_quote{
public:
	Bulk_quote() = default;
	//使用直接基类的构造函数
	using Disc_quote::Disc_quote;
	double net_price(std::size_t)const override;
};

double Bulk_quote::net_price(std::size_t n)const {
	if (n >= quantity){
		return n*price*(1 - discount);
	}
	else {
		return n*price;
	}
}
