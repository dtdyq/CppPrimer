#include<iostream>
#include<vector>
#include<cstddef>
using namespace std;
//vector的使用方法：
int testVector() {
	//定义和初始化方式：
	vector<int> v1;//默认初始化
	vector<int> v2(12);//v2中含有一个元素，为12；
	vector<int> v3(10, 12);//v3中包含10个值，都为12
	vector<int> v4{ 1,2,3,4,5 };//推荐这样使用
	vector<int> v5 = v2;//和v2初始化相同
	vector<int> v6 = { 1,2,3,4,5 };//同v4的初始化方式
	vector<int> v7(10);//10个元素，每个元素都默认初始化为0，一般不需要这样做

	//vector操作，不能用下标形式添加元素
	for (auto& r : v6) {
		r *= r;
	}
	for (const auto r : v6) {
		cout << r << " ";
	}
	cout << endl;
	//使用迭代器遍历,注意r != v6.end()判断方式，和java不同风格：
	for (auto r = v6.begin(); r != v6.end(); ++r) {
		*r *= *r;
	}
	//使用cbegin(),cend()只能迭代不能改变元素的值：
	for (auto r = v6.cbegin(); r != v6.cend(); r++) {
		cout << *r << " ";
	}
	cout << endl;
	//::iterator：读写容器中的元素
	//::const_iterator：只能读取容器中的元素
	//可以在迭代器上进行加减等运算操作，

	//数组,实际意义是指针，声明符指向了数组中第一个元素的地址
	//数字的长度为size_t类型，在cstddef中，可使用begin和end标准函数来对数组进行迭代操作
	int arr[5] = { 3,5,7,9,2 };
	for (auto r = begin(arr); r != end(arr); ++r) {
		cout << *r << " ";
	}
	cout << endl;
	auto arrlen =  end(arr)- begin(arr);
	cout << arrlen << endl;

	//使用数组初始化vector：
	vector<int> vrr(begin(arr),end(arr) - 1);
	vector<int>::const_iterator it = vrr.cbegin();
	while (it != vrr.cend()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
