#pragma once
#include<iostream>
//成员模板之普通类的成员模板：
class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) :os(s) {}
	//成员模板
	template <typename T> void operator()(T* p) const{
		os << "deleting unique ptr: " << endl;
		delete p;
	}
private:
	std::ostream &os;
};
//成员模板之模板类使用成员模板
template <typename T> class Blobs {
public:
	template <typename It>
	Blobs(It b, It e):data(std::make_shared<std::vector<T>>(b,e)){

	}
private:
	std::shared_ptr<std::vector<T>> data;
};