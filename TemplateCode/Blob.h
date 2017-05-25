#pragma once
#include<iostream>
#include<vector>
#include<initializer_list>
#include<memory>
#include<utility>
template <typename> class BlobPtr;
template <typename T> class Blob {
	//相同类型的实例化参数为友元
	friend class BlobPtr<T>;
	//所有实例都是Blob的友元（使用不同的模版参数）
	template <typename X> friend class Fen;
	//令模板自己的类型参数成为友元
	friend T;
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T> li);
	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	//添加和删除元素
	void push_back(const T &t) {
		data->push_back(t);
	}
	//移动版本
	void push_back(T &&t) {
		data->push_back(std::move(t));
	}
	void pop_back();
	//元素访问：
	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	//若data[i]无效，则抛出msg
	void check(size_type i, const std::string& msg);
};
template <typename T>
T& Blob<T>::operator[](size_type i) {
	check(i, "subscript out of range.");
	return (*data)[i];
}
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) {
	if (i<0 || i >= data->size()) {
		throw std::out_of_range(msg);
	}
}
template <typename T>
T& Blob<T>::back() {
	check(0, "there has no elements.");
	return data->back();
}
template <typename T>
void Blob<T>::pop_back() {
	check(0, "empty in blob.");
	data->pop_back();
}
template <typename T>
Blob<T>::Blob() :data(std::make_shared<std::vector<T>>()) {}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) :
	data(std::make_shared<std::vector<T>>(li)) {}
