#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<array>
#include<deque>
#include"src.h"
using namespace std;
int main() {
	//顺序容器
	testSeq();
	//泛型算法：
	test_find();
	test_accu();
	test_fill();
	test_insert();
	test_copy();
	test_sort();
	test_lambda();
	test_bind();
}