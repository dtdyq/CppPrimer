#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//lambda简单使用：
void testLambda() {
	//简单形式
	auto l = [](int i) {return i * 10; };
	int k = l(12);
	cout << k << endl;

	//使用lambda实现定制排序：
	auto sot = [](const string& s1, const string& s2)
	                {return s1.size() < s2.size(); };
	vector<string> vec{ "cpp","java","scala","c","python" };
	stable_sort(vec.begin(), vec.end(), sot);
	for (auto i = vec.begin(); i != vec.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//使用lambda实现打印出超过指定长度的字符串
	int sz=4;
	auto print = [sz](const string& s) {
		return s.size() >= sz;
	};
	//获取迭代器找到满足size()>=sz的第一个位置：
	auto p = find_if(vec.begin(), vec.end(), print);
	while (p != vec.end()) {
		cout << *(p++) <<" ";
	}
	cout << endl;
	//直接使用foreach打印：
	p = find_if(vec.begin(), vec.end(), print);
	for_each(p, vec.end(), [](const string& s) {cout << s << " "; });
	cout << endl;

	//lanbda捕获和返回
	//值捕获：
	int v = 22;
	auto val = [v] {cout << v << endl; };
	v = 10;
	val();//输出22
	//通过使用mutable实现在lambda中改变值：
	auto mut = [v]()mutable {cout << (++v) << endl; };
	mut();
	//引用捕获：
	auto ref = [&v] {cout << v << endl; };
	v = 30;
	ref();//输出30
	//可以同时使用值捕获或引用捕获
	//隐式捕获：=表示隐式值捕获，&表示隐式引用捕获
	string li = "print ";
	for_each(vec.begin(), vec.end(), 
		        [=](string& s) {cout << li << s << endl; });
	for_each(vec.begin(), vec.end(),
		[&](string& s) {cout << li << s << endl; });

	//指定lambda的返回值：
	vector<int> test{ 12,-232,44,-54,-65,-87,-92,65,465 };
	transform(test.begin(), test.end(), test.begin(),
		[](int i)->int {if (i < 0) return -i; else return i; });
	for (auto i = test.begin(); i != test.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;


}