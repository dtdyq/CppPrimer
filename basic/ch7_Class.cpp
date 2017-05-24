#include<iostream>
#include<string>
//类：
/*
注意：
类内的const成员和引用成员必须被初始化


隐式的类类型转换：
在Sales_Data的构造器中，有接受string类型的构造器，这种情况可导致string类型向
Sales_Data类型的隐式转换，如：
string book="121-3231-3-233";
以下函数调用会临时构造一个Sales_Data对象，再作为函数的对应的函数的参数：
item.combine(book);

这种类型转换只允许一步类类型转换，例如以下调用则显示错误，因为需要先转换为string
再转换为Sales_Data:
item.combine("342-534634-23423-43");
可这样做：
item.combine(string("32-4534-56-45"));
item.combine(Sales_data("1324-355654-2432-53453"));

可以使用explicit抑制构造器的隐式类型转换
但explicit只能用在类内部的构造器


聚合类：
所有的成员都是public的
没有定义任何的构造函数
没有类内初始值
没有基类，也没有virtual函数


字面值常量类：
数据成员都必须是字面值类型
类必须至少含有一个constexpr构造器
类必须使用析构函数的默认定义
*/
using namespace std;
//销售单类，描述了商品编号，商品数量，总共的价格
class Sales_Data{
public:
	//构造函数：
	//默认构造器：
	Sales_Data() {};
	//使用默认实参定义的构造器
	explicit Sales_Data(const string& sid="") :bookNo(sid) {}
	//委托构造函数：
	Sales_Data(unsigned n, double p) :Sales_Data("", n, p) {}

	Sales_Data(const string& sid, unsigned n, double p) :
		bookNo(sid), units_sold(n), revenue(p) {}
	//抑制构造函数的隐式类类型转换
	explicit Sales_Data(istream&);
	/*
	该函数后面的const关键字是为了修改隐式this指针的类型
	默认情况下的this指针类型为：Sales_Data *const，
	如果一个该类的实例申明为了const类型，则调用成员函数时可能修改该实例的
	属性值，然而又不能让const实例完全不能调用成员函数，所以可以将不修改成员变量
	的函数声明为const供const实例调用
	增加const后使得this是一个指向常量的指针，该成员函数称为常量成员函数
	在该函数内，不可以修改成员变量的值
	*/
	string isbn()const { return bookNo; }
	Sales_Data& combine(const Sales_Data&);
	double avg_price()const;
	//声明友元函数，在该函数中可访问该类的私有属性：
	friend ostream &print(ostream& os, const Sales_Data& sd);
	friend istream &read(istream&, Sales_Data&);
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//在类的外部定义构造函数：
Sales_Data::Sales_Data(istream& is) {
	read(is, *this);
}
double Sales_Data::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
	}
	return 0;
}
//定义返回this对象的函数：
Sales_Data& Sales_Data::combine(const Sales_Data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;//返回调用该函数的对象
}
//非成员接口函数：
Sales_Data add(const Sales_Data& s1, const Sales_Data& s2) {
	Sales_Data sd = s1;
	sd.combine(s2);
	return sd;
}
ostream &print(ostream& os , const Sales_Data& sd) {
	os << sd.isbn() << " " << sd.units_sold << " "
		<< sd.revenue << " " << sd.avg_price();
	return os;
}
istream &read(istream& is, Sales_Data& sd) {
	double price;
	is >> sd.bookNo >> sd.units_sold >> price;
	sd.revenue = sd.units_sold*price;
	return is;
}
int testClass() {
	const Sales_Data s("dewf");
	string tmp = s.isbn();
	cout << tmp << endl;
	return 0;
}