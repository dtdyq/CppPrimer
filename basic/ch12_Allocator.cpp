#include<iostream>
#include<memory>
#include<string>
using namespace std;
//动态内存分配和智能指针相关
void testAllocator() {
	int v1 = 11, v2 = 99;
	//智能指针：当动态对象不再使用时，智能指针会自动释放所指向对象的内存
	shared_ptr<int> sp1 = make_shared<int>(11);
	shared_ptr<int> sp2 = make_shared<int>(99);
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	//交换两个指针：
	swap(sp1, sp2);
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	auto sp3(sp1);//将sp3指向sp1指向的对象，
	cout << *sp3 << endl;

	//初始化方式：
	//shared_ptr<int> sp4 = new int(33);   错误
	shared_ptr<int> sp4(new int(33));
	sp4.reset(new int(1024));   //指向新的对象

	//unique_ptr：某个时刻只能有一个指针指向对象：
	unique_ptr<int> uniq(new int(1234));
	//unique_ptr<int> uniq2 = uniq;  error
	//shared_ptr<int> sp5 = uniq;    error

	//weak_ptr:相当于弱指针，当最后一个指向该弱指针指向的对象的指针销毁时，该对象
	//被回收

	//使用alloctor分配内存：
	allocator<string> alloc;
	auto const str = alloc.allocate(100);//分配100个未初始化的string
	//使用alloc初始化对象：
	auto p = str;
	alloc.construct(p, "first");
	alloc.construct(++p, "second");
	alloc.construct(++p, "third");
	cout << *str << endl;
}
/*
int main() {
	testAllocator();
}
*/