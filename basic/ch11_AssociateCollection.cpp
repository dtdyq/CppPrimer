#include<iostream>
#include<set>
#include<string>
#include<map>
#include<utility>
//关联容器
/*
tree结构的关联容器：
map
set
multimap  关键字可重复
multiset  关键字可重复
基于hash的关联容器
unordered_map
unordered_set
unordered_multimap
unordered_multiset
*/
using namespace std;
void testAssociateCollection() {
	//初始化set
	multiset<string> ms{ "and","with","or","other","and","but","so" };
	set<string> ss(ms.begin(),ms.end());
	cout << ms.size() << endl;
	cout << ms.max_size() << endl;
	cout << ss.size() << endl;
	cout << ss.max_size() << endl;
	map<int, string> is = {
		{12,"java"},
		{33,"cpp"},
		{65,"python"},
		{101,"scala"}
	};
	cout << is.size() << endl;
	cout << is.max_size() << endl;

	//pair:可以保存任意两个对象：
	pair<string, int> p{ "pair",2 };
	cout << p.first << " " << p.second << endl;
	p = make_pair("makepair", 4);
	cout << p.first << " " << p.second << endl;

	//关联容器上的操作
	//类型名：
	//key_type:关键字类型
	//mapped_type：每个关键字关联的类型：
	//value_type：对于set，与key_type相同
				//对于map，相当于pair<const key_type,mapped_type>

	//关联容器的迭代器
	for (auto it = ss.begin(); it != ss.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = is.begin(); it != is.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	//向set中添加元素：
	string str[2] = { "also","only" };
	ss.insert(begin(str), end(str));
	ss.insert({ "ecx","type" });
	for (auto it = ss.begin(); it != ss.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//向map中添加元素：
	is.insert({ 33, "tck" });
	auto in=is.insert(make_pair(1000, "wnasuvw"));
	//insert返回新插入的第一个元素的位置，和是否成功插入的标志，存储在pair中
	cout << in.first->first <<" "<<in.first->second <<" "<<in.second<< endl;
	for (auto it = is.begin(); it != is.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	//map的删除操作返回被删除元素的个数
	//map的下标操作会获取某个关键字的值，如果指定的关键字不再map中，则将其添加进去
	//map通过at来操作则不会创建新的key，如果不存在，则抛出异常
	//multimap其他有用方法：
	//find 返回一个迭代器，指向第一个指定关键字的迭代器
	//count（K） 返回关键字等于k的数量
	//lower_bound(k) 返回迭代器， 指向第一个关键字不小于k的元素
	//upper_bound(k) 返回第一个大于k元素的位置
	//equal_range(k) 返回迭代器pair，表示关键字等于k的范围 
}
/*
int main() {
	testAssociateCollection();
}
*/