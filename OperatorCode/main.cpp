#include<iostream>
#include<string>
#include<vector>
#include<initializer_list>
#include<functional>
#include<algorithm>
#include<map>
#include"OpTest.h"
using namespace std;
/*
cpp重载运算符：
运算符函数可以被直接调用
通常情况下，不应该重载逗号、取地址、逻辑与和逻辑或运算符
使用与内置类型一致的含义
*/

//定义函数调用运算符，使得类可以像函数一样使用：
//定义了调用运算符的类的对象通常称为函数对象
//函数调用运算符必须是成员函数
struct absInt {
	int operator()(int val) {
		return val < 0 ? -val : val;
	}
};

//lambda是一种函数对象：
/*
sort(v.begin(),v.end(),[](const string& s1,const string& s2)
			{return s1.size()>s2.size();});
相当于：
*/
class StrCmp {
public:
	bool operator()(const string& s1, const string& s2)const {
		return s1.size()>s2.size();
	}
};
/*
因此上面的sort函数也可以写为：
sort(v.begin(),v.end(),StrCmp());
*/

/*
当lambda中包含捕获的参数时，实际上相当于临时的有成员属性的类：
auto point=find(c.begin(),c.end(),[sz](const string*s)
		{ return s.size()>sz; });
其中的lambda等价于：
*/
class StrFind {
public:
	StrFind(size_t n) :sz(n) {}
	bool operator()(const string& s) const{
		return s.size() > sz;
	}
private:
	size_t sz;
};
/*
同样，find可以写为：
auto point=find(c.begin(),c.end(),StrFind(sz));
*/

int add(int i, int j) { return i + j; }
struct divide {
	int operator()(int i, int j)const {
		return i / j;
	}
};

int main() {
	string s = "helloworld";
	//正确，等价于s.operator+(s):
	string t = s + " hi!";
	//只有string的+定义成了普通的非成员函数，才能使用一下运算：
	string u = "hi! " + s;

	OpTest op1;
	op1 = { "dowdw","xqowq" };
	OpTest op;
	cout << op1 << endl;

	absInt ai;
	int abs = ai(-12);
	cout << abs << endl;

	//定义在functional中的函数对象：
	plus<string> padd;
	string sa = padd("wone", "awon");
	vector<string> vec = { "xdw","wcnqc","la","xqwx" };
	sort(vec.begin(), vec.end(), greater<string>());

	for (auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	//cpp中可调用的对象：
	/*
		函数
		函数指针
		lambda表达式
		bind创建的对象
		重载了函数调用运算符的类
	*/
	
	//使用function：将不同的可调用对象转换为function
	auto mod = [](int i, int j) {return i%j; };
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = mod;
	function<int(int, int)> f3 = divide();

	//定义计算器操作类型：
	map<string,function<int (int,int)>> biops=
	{
		{"+",add},
		{"/",divide()},
		{"%",mod},
		{"*",[](int i,int j) { return i * j; }},
		{"-",std::minus<int>()}
	};
	cout << biops["+"](12, 32) << endl;
}