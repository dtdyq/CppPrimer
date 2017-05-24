#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<array>
#include<string>
using namespace std;
//cpp顺序容器：
/*
vector:可变大小数组
deque：双端队列
list ：双向链表
forward_list:单向链表
array：固定大小数组
string：可变长字符数组
-------------------------------------------------------------
容器选择策略：
尽量使用vector
如果程序有很多小的元素，且空间的额外开销很重要，则不要使用list
-------------------------------------------------------------
容器相关类型：
iterator:迭代器
const_iterator：只读迭代器
size_type：无符号整数，表示元素数量
difference_type:带符号整数类型，表示两个迭代器之间的距离
value_type：元素类型
reference：相当于value_type&
const_reference：显而易见
--------------------------------------------------------------
容器操作可能使迭代器失效
向容器添加元素时：
对于vector和string，如果存储空间被重新分配过，则迭代器失效
指向容器的指针和引用也都会失效
对于list，迭代器指针和引用仍然有效
从容器删除元素也是差不多的，只要看它的内部元素位置是否会被移动
*/
int testCollection() {
	vector<int> vec{ 1,2,3,4,5 };
	deque<int> deq(vec.begin(), vec.end());
	list<int> li(deq.begin(), deq.end());

	forward_list<int> fl(12, 10);

	//array:
	array<int, 5> arr;//表示arr存储5个int类型的元素
	arr[2] = 22;
	//array支持复制，而不同于int[] 因此对于定长数组，使用array还是可以的
	array<int, 5> cp = arr;

	//swap:可在常数时间内完成
	vector<string> v1{ "aa","bb","cc" };
	vector<string> v2{ "zz","kk","qq","ss" };
	swap(v1, v2);//v1.swap(v2)
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	for (auto i = v2.begin(); i != v2.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//assign:
	v1.assign({ "java","cpp" });
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//insert:返回第一个新加入的元素的迭代器
	v1.insert(v1.begin(),"insert");
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	v1.insert(v1.end(),10,"java");
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//emplace:构造而不是拷贝元素
	v1.emplace(v1.begin(),"emplace");
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;

	//访问元素的方式：
	v1.back();  //返回尾元素的引用
	v1.front();  //返回首元素的引用
	v1[2];     //使用下标操作
	v1.at(12);   //获取指定位置元素

	//删除元素：
	v1.pop_back();
	v1._Pop_back_n(10);
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	v1.erase(v1.begin(), v1.begin() + 2);
	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	v1.clear();   //清空元素

	return 0;
}