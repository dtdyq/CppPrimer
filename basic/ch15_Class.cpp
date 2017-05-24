#include<iostream>
#include<string>
using namespace std;
/*
非虚函数在编译时解析
派生类可以访问基类的public和protected的成员，和java类似
如果想将某个类用作基类，则该类必须已经定义而不是仅仅声明
在类声明后面加final关键字表示该类不能被继承
申明为final的方法不能在派生类中被覆盖
基类前的访问控制符用于声明基类成员在派生类中的访问权限

友元关系既不能继承，也不能传递，即在基类中声明的友元，只能访问基类的成员
而不能访问派生类的成员

可以使用using来改变在基类中的成员的访问权限

派生类可以定义相同的成员名字覆盖掉基类的成员，如果要使用基类的成员，需要
明确的声明：Base：value
对于成员函数，即使参数列表不同，只要函数名称相同，则基类函数一样会被覆盖
*/
class Quote {
public:
	Quote() = default;
	Quote(const string&book, double sales_price)
		:bookNo(book),price(sales_price) {}

	string isbn() const {
		return bookNo;
	}
	virtual double net_price(size_t n) const {
		return n*price;
	}
	//基类通常应该定义虚析构函数
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price;
};
//派生类必须对所有重新定义的虚函数进行声明
//派生类不能直接初始化从基类继承而来的成员，必须使用基类的构造函数
class Bulk_quote final:public Quote{
public:
	Bulk_quote() = default;
	Bulk_quote(string& book, double p, size_t n, double disc):
		Quote(book, p), min_qty(n), discount(disc) {};
	double net_price(size_t n) const override {
		if (n > min_qty) {
			return n*discount*price;
		}
		else {
			return n*price;
		}
	}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};
//动态绑定
void print_total(ostream &os, const Quote &item, size_t n) {
	double res = item.net_price(n);
	string isbn = item.isbn();
	os << "ISBN: " << isbn <<
		" #sold: " << n << " total price:" << res;
}
//定义抽象基类：
class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(string& isbn, double price, size_t n, double disc) :
		Quote(isbn, price), qty(n), disc(disc) {}
	double net_price(size_t n) const = 0;
private:
	size_t qty = 0;
	double disc = 0.0;
};
int TestClass() {
	Quote& q = Bulk_quote(string("sw"),10.0,size_t(12),0.8);
	double p = q.net_price(20);
	cout << "test" << p << "  ";
	return 0;
}