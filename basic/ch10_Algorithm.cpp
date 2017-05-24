#include<algorithm>
#include<numeric>
#include<vector>
#include<iostream>
#include<string>
#include<iterator>
//泛型算法的一般操作
using namespace std;
bool isShoter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}
int testAlgorithm() {
	vector<int> test{ 3,6,9,4,5,69,2,43,734,423,47,3456,576,44 };

	//find:找到元素的话会返回指向元素位置的迭代器，否则返回尾后迭代器
	int val = 43;
	auto locat = find(test.begin(), test.end(), val);
	if (locat != test.end()) {
		cout << *(locat + 1) << endl;
	}

	//accumulate:求和：
	int sum = accumulate(test.begin(), test.begin() + 4,0);
	cout << sum << endl;
	//也可用于拼接字符串：
	vector<string> vec{ "a","b","c" };
	string me = accumulate(vec.begin(), vec.end(), string(""));
	cout << me << endl;

	//fill/fill_n:
	fill(test.begin(), test.begin() + 5, -1);
	fill_n(test.end() - 5, 5, -99);
	for (auto i = test.begin(); i != test.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	//插入迭代器：允许向容器中添加元素
	vector<int> bi;
	auto it = back_inserter(bi);
	*it = 12;//向容器中添加了一个元素
	it++;
	*it = 21;
	//通过back_inserter使用fill_n向容器中添加元素
	fill_n(it, 10, 99);
	for (auto i = bi.begin(); i != bi.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	//replace:将指定范围内的指定元素替换为给定元素
	replace(bi.begin(), bi.end(),99, 11);
	for (auto i = bi.begin(); i != bi.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	//copy:
	int arr[10];
	copy(bi.begin(), bi.begin() + 10, arr);
	for (auto i = begin(arr); i != end(arr); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//replace_copy：保留原序列不变，将替换后的序列复制到指定容器中
	vector<int> tmp;
	replace_copy(bi.begin(), bi.end(), back_inserter(tmp), 11, -99);
	for (auto i = tmp.begin(); i != tmp.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "===================================================" << endl;
	//删除容器中重复的元素：
	vector<string> uniq
	{ "java","cpp","scala","lisp","haskell","python","cpp","scala" };
	//先进行排序：
	sort(uniq.begin(), uniq.end());
	//对容器进行unique操作，由于泛型算法，不会添加或删除容器的元素，所有
	//只会将重复的元素移动到最后，并返回执行第一个重复元素的指针
	auto point = unique(uniq.begin(), uniq.end());
	//删除指定位置元素：
	uniq.erase(point, uniq.end());
	for (auto i = uniq.begin(); i != uniq.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << "==================================================" <<endl;
	
	//自己定制实现排序：
	sort(uniq.begin(), uniq.end(), isShoter);
	for (auto i = uniq.begin(); i != uniq.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}