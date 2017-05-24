#include<iostream>
#include<vector>
#include<string>
#include"TextQuery.h"
#include"QueryResult.h"
#include<fstream>
using namespace std;
/*
构建文本查询程序，根据给定文件查询单词
返回的结果是单词出现的次数和所在行

任务：
程序读取输入文件时，必须记住每一行
程序生成输出时：
	提取每个单词所关联的行号
	行号按升序出现且无重复
	打印出给定行号的文本
*/
//在设计一个类时，可以首先使用这个类，这样可以更好地理解这个类需要的功能
ostream& print(ostream &os, const QueryResult&qr) {
	
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "time(s):" << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
void runQueries(ifstream &infile) {
	//infile指向要处理的文件：
	TextQuery tq(infile);
	//提示用户输入要查询的单词：
	while (true) {
		cout << "enter word to look for,or q to quit:";
		string s;
		if (!(cin >> s) || s == "q") break;
		QueryResult qr = tq.query(s);
		print(cout, qr) << endl;
	}
}
int main() {
	ifstream f("F:/CODE/CPP/TextQuery/test.txt");
	if (f) {
		runQueries(f);
	}
}