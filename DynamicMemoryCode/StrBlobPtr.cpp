#include"StrBlob.h"
#include"StrBlobPtr.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
StrBlobPtr::StrBlobPtr(StrBlob& a,size_t sz) :wptr(a.data), curr(sz) {};
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg)const {
	auto ret = wptr.lock();
	if (!ret) {
		throw runtime_error(msg);
	}
	if (i > ret->size()) {
		throw out_of_range(msg);
	}
	return ret;
}
string& StrBlobPtr::deref() const{
	auto p = check(curr, "deference pass end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}