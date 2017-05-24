#include"StrBlob.h"
#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace std;
void StrBlob::check(size_type i, const string &msg) const{
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}
string& StrBlob::front() {
	check(0, "front on empty blob");
	return data->front();
}
string& StrBlob::back() {
	check(0, "kack on empty blob");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop back on empty blob");
	data->pop_back();
}
const string& StrBlob::back() const {
	return data->back();
}
const string& StrBlob::front() const {
	return data->front();
}