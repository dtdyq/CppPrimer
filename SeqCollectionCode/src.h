#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<array>
#include<deque>
#include<algorithm>
#include<numeric>
#include<functional>
using namespace std;
using namespace std::placeholders;
void testSeq() {
	list<string> lt = { "cpp","java","python" };
	//顺序容器的反向迭代
	auto beg = lt.rbegin();
	auto end = lt.rend();
	while (beg != end) {
		cout << *beg++ << endl;
	}
	//容器拷贝：容器类型和元素类型都要相同，在使用迭代器时不要求前者
	list<string> lp(lt);

	//array:具有固定的大小：
	array<int, 10> arr;
	arr[1] = -12;
	cout << arr[1] << endl;

	//swap和assign：
	list<string> lr = { "akka","spring","spark" };
	swap(lt, lr);
	for (auto it = lt.cbegin(); it != lt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = lr.cbegin(); it != lr.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	lp.assign(lr.begin(), lr.end());
	for (auto it = lp.cbegin(); it != lp.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	lp.assign(12, "repeat");
	for (auto it = lp.cbegin(); it != lp.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
//查找算法：
void test_find() {
	vector<int> vec = { 2,7,3,8,2,6 };
	//在指定范围内查找值，找到则返回指向该元素的迭代器，否则返回尾置迭代器
	auto result = find(vec.begin(), vec.end(), 2);
	while (result != vec.end()) {
		cout << *result++ << " ";
	}
	cout << endl;
}
//求和算法：（只读算法）
void test_accu() {
	vector<int> vec = { 2,7,3,8,2,6 };
	auto res = accumulate(vec.begin(), vec.end() - 3, 0);
	cout << res << endl;
	vector<string> vs = { "java","scala","kotlin" };
	auto ress = accumulate(vs.begin(), vs.end(), string(""));
	cout <<ress<< endl;
}
//填充算法：
void test_fill() {
	vector<int> vec(10,1);
	fill(vec.begin(), vec.end() - 5, -1);
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	//等价：
	fill_n(vec.begin(), 5, -1);
}
//使用插入迭代器：
void test_insert() {
	vector<int> vec;
	auto in = back_inserter(vec);
	*in = 12;//现在容器中有一个元素12
	in++;
	*in = 21;
	cout << vec.at(0) << " " << vec.at(1) << endl;
}
//使用copy：
void test_copy() {
	int from[5] = { 1,3,5,7,9 };
	int to[5];
	auto res = copy(begin(from), end(from), to);
	for (int i = 0; i < 5; i++) {
		cout << to[i] << " ";
	}
	cout << endl;
}
//使用排序函数：
//自定义排序比较函数
bool isShotter(const string& s1, const string& s2) {
	return s1.size() > s2.size();
}
void test_sort() {
	vector<string> lt = { "cpp","java","python","scala","c" };
	sort(lt.begin(), lt.end(), isShotter);
	for (auto it = lt.cbegin(); it != lt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
void test_lambda() {
	auto f = [] {return 12; };
	cout << f() << endl;
	//向lambda中传递参数：
	auto bger = [](const string&s1, const string&s2) {
		return s1.size() < s2.size();
	};
	vector<string> lt = { "cpp","java","python","scala","c" };
	sort(lt.begin(), lt.end(), bger);
	for (auto it = lt.cbegin(); it != lt.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//使用捕获列表：
	int tmp = 4;
	auto leng = [tmp](const string& s) {
		return s.size() > tmp;
	};
	auto pointer = find_if(lt.cbegin(), lt.cend(), leng);
	while (pointer != lt.end()) {
		cout << *pointer++ << " ";
	}
	cout << endl;
	//另一例：
	for_each(lt.begin(), lt.end(),
		[](const string& s) {cout << s << " "; });
	cout << endl;

	//值捕获和引用捕获：
	int ref = 12;
	auto vl = [ref]() {return ref; };
	int vr = vl();
	vr = 22;
	cout << ref << endl;
	auto rl = [&ref]() {return ref; };
	ref = 2;
	int rr = rl();
	cout << rr << endl;

	//隐式捕获：
	auto yf = [=]() {return ref; };
	cout << yf() << endl;

	//可变lambda：用于在lambda中改变参数：
	auto mf = [ref]()mutable {return ++ref; };
	cout << mf() << endl;

	//指定lambda的返回类型：
	auto gf = [ref, rr]()->int {
		if (ref > rr) {
			return ref;
		}
		else {
			return rr;
		}
	};
	cout << gf() << endl;
}
//参数绑定：
//功能函数：用于测试字符串长度是否大于指定值：
bool check_size(const string& s, string::size_type len) {
	return s.size() > len;
}
void test_bind() {
	//绑定check_size的len参数：
	auto check5 = bind(check_size, _1, 5);
	//使用bind改变字符串排序规则：
	vector<string> lt = { "cpp","java","python","scala","c" };
	//更改参数顺序
	sort(lt.begin(), lt.end(), bind(isShotter, _2, _1));

}