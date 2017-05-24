#pragma once
#include<iostream>
#include<set>
#include<memory>
#include"Quote.h"
using namespace std;
double print_total(ostream &os, const Quote &item, size_t n);
//cpp面向对象编程时，往往需要使用指针和引用
class Basket {
public:
	void add_item(const shared_ptr<Quote> &sale) {
		items.insert(sale);
	}
	double total_receipt(ostream&)const;
private:
	static bool compare(const shared_ptr<Quote>&lhs,
		const shared_ptr<Quote>&rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};
double Basket::total_receipt(ostream& os)const {
	double sum = 0.0;
	for (auto iter = items.cbegin();
	iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "total sale: " << sum << endl;
	return sum;
}