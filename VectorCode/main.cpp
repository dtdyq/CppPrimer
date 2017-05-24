#include<iostream>
#include<vector>
#include<cstddef>
#include"src.h"
using std::vector;
//标准库类型vector的学习和使用：
int main() {
	//vector的初始化：
	initTest();
	//vector中的其他操作：
	//operatTest();
	//cpp中的数组的初始化和操作：
	int score[5];
	int tmp=0;
	while (tmp < 5 && cin >> score[tmp++]);
	//使用for循环遍历数组：
	for (int i : score) {
		cout << i << endl;
	}
	//使用begin和end函数操作数组：
	auto ib = begin(score);
	int *ie = end(score);
	while (ib != ie) {
		cout << *(ib++) << endl;
	}
	//获得数组长度：
	auto len = end(score) - begin(score);

	//使用数组来初始化vector对象：
	vector<int> ivr(begin(score), end(score));
	vector<int> ivr2(score + 1, score + 3);

}
