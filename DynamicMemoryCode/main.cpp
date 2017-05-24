#include<iostream>
#include<vector>
#include<string>
#include<new>
#include<cstdio>
#include<memory>
using namespace std;
//cpp中的动态内存管理
int main() {
	vector<string> v1;
	{//在新的作用域中定义v2，并拷贝给v1，各自具有不同的底层数据结构
		vector<string> v2 = { "dlwe","wqxw","qxx" };
		v1 = v2;
	}
	for (auto it = v1.begin(); it != v1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	//动态分配内存：
	string* str = new string("qoeudwa");
	//指向const的指针：
	const string* sp = new const string("wqxqw");

	auto ps = new auto("xqowi");

	//指定分配失败时禁止抛出异常：
	int* pi = new (nothrow) int();
	//释放内存空间：
	delete pi;
	//delete总是可以释放一个空指针，但是对于指向同一个内存的
	//两个指针分别进行释放，则结果时未定义的
	//由内置指针管理的动态内存在被显式释放前都会一直存在

	//使用shared_ptr和new：
	shared_ptr<int> sip(new int());
	shared_ptr<string> spr(new string("shared"));
	//unique_ptr:只能有一个指针指向动态分配的对象：
	unique_ptr<string> usp(new string("unique"));
	usp.release();//释放对指针的控制权

	//weak_ptr：指向shared_ptr所管理的对象，一旦最后一个shared_ptr
	//释放，则对象被释放：
	weak_ptr<string> wp = spr;
	//使用之前应该先判断：
	spr = nullptr;
	if (shared_ptr<string> tp = wp.lock()) {
		cout << *tp << endl;
	}
	

	//动态分配数组：
	int *pia = new int[20]();//分配20个元素的数组，并初始化为0
	string *psa = new string[10]{"wufw","ndhw","dqi"};
	//释放动态数组
	delete[] psa;
	//使用智能指针来创建管理数组：
	unique_ptr<int[]> uap(new int[10]);
	//可直接对其使用下标操作：
	for (int i = 0; i < 10; i++) {
		uap[i] = -i;
	}
	uap.release();
	//使用shared_ptr时需要自己定义删除器，访问也不能使用普通的方式：
	shared_ptr<int> sap(new int[10], [](int *p) {delete[] p; });
	for (int i = 0; i < 10; i++) {
		*(sap.get() + i) = i;
	}
	sap.reset();
	//使用allocator类来更灵活地管理内存
	allocator<string> alloc;//可以分配string的allocator对象
	auto const ap = alloc.allocate(2);//分配十个未初始化的string对象
	//在分配的内存上构造对象：
	auto q = ap;
	alloc.construct(q++, "fwifoe");
	alloc.construct(q++, 10, 'a');
	cout << (*ap) << endl;
	//用完对象后进行回收：
	while (q != ap) {
		alloc.destroy(--q);
	}
	//回收对象后可以重新利用内存构建新的对象，也可以将内存还给系统：
	alloc.deallocate(ap, 2);
}