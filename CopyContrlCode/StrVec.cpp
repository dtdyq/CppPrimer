#include"StrVec.h"
#include<utility>

void StrVec::push_back(const string&s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(string* b, string* e) {
	//分配空间保存给定范围的元素
	auto data = alloc.allocate(e - b);
	return{ data,uninitialized_copy(b,e,data) };
}
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec& sv) {
	auto newdata = alloc_n_copy(sv.elements, sv.first_free);
	elements = newdata.first;
	first_free = newdata.second;
}
StrVec::~StrVec() {
	free();
}
StrVec& StrVec::operator=(const StrVec&s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}
//对内存进行重新分配时，需要在底层拷贝string可以使用cpp中新
//引入的移动构造函数和std::move来避免string的拷贝
void StrVec::reallocate() {
	auto newcap = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(dest++, move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}
//声明移动构造函数：移动构造函数不应该抛出异常
StrVec::StrVec(StrVec&&s)noexcept:
	elements(s.elements), first_free(s.first_free), cap(s.cap) {
	//保证销毁s的内存时不会影响到该对象 
	s.elements = s.first_free = s.cap = nullptr;
}
//移动赋值运算符：
StrVec& StrVec::operator=(StrVec&& s)noexcept {
	//直接检测自赋值：
	if (this != &s) {
		free();//释放已有元素
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		//将s置于可析构状态：
		s.elements = s.first_free = s.cap = nullptr;
	}
}