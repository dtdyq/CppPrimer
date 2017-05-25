#pragma once
#include<iostream>
#include<memory>
#include<vector>
template <typename T> class BlobPtr {
public:
	BlobPtr() :curr(0) {};
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	T& operator*()const {
		auto cp = check(curr, "deference past end");
		return (*cp)[curr];
	}
	//递增运算符；
	BlobPtr& operator++();//前置运算符
	BlobPtr& operator--();
	BlobPtr& operator++(int);//后置运算符
	BlobPtr& operator--(int);

private:
	//检查成功，则返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&)const;
	//保存weak_ptr，表明底层vector可能被销毁
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;//数组中的当前位置
};

//前置运算符效率比较高
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--() {
	--curr;
	check(curr, "decrement past end of BlobPtr");
	return *this;
}
//后置运算符，即++在后面，需要先将原值拷贝，再递增最后返回原值的拷贝，效率低
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	//在一个模板的作用域内，可以直接使用模板名而不用指定模板实参
	BlobPtr ret = *this;//保存当前值
	++*this;
	return ret;//返回保存的状态
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	//在一个模板的作用域内，可以直接使用模板名而不用指定模板实参
	BlobPtr ret = *this;//保存当前值
	--*this;
	return ret;//返回保存的状态
}