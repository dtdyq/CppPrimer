#include<set>
//IO:
//头文件：
#include<iostream>
#include<fstream>
#include<sstream>
/*
istream 输出流
ostream 输出流
iostream 读写流

ifstream 从文件读取数据
ofstream 向文件中写入数据
fstrean 读写文件数据

istringstream 从string读取数据
ostringstream 向string中写入数据
stringstream 读写string

io对象无拷贝或赋值：
ofstream out1,out2;
out1=out2   //error
ofstream print(ofstream)   //error
out1=print(out1)   //error

io操作的条件状态：
strm::badbit   流已崩溃
strm::failbit  一个io操作失败
      eofbit   流到达了文件结束
	  goodbit  指示流未处于错误状态

文件打开模式：
in   以读方式打开
out  以写方式打开
app  每次写操作前定位到文件末尾
ate  打开文件后立刻定位到文件末尾
trunc   截断文件
binary  以二进制方式读写IO
*/
using namespace std;
int testIO() {
	//刷新输出缓冲区：
	cout << "buff" << endl;  //换行
	cout << "buff" << ends;   //添加一个空字符
	cout << "buff" << flush;  //不添加如何字符
	cout << unitbuf;
	//在该区间内任何输出都会立刻刷新
	cout << nounitbuf;

	//输入和输出关联：
	string str;
	cin.tie(&cout);
	cin >> str;

	ifstream fin("test.txt");
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
	string word;
	set<string> sset;
	while (getline(cin, line)) {
		if (line != string("exit")) {
			istringstream sin(line);
			while (sin >> word) {
				sset.insert(word);
			}
		}
		else {
			break;
		}
	}
	cout << sset.size() << endl;
	for (auto it = sset.cbegin(); it != sset.cend(); ++it) {
		cout << *it+" ";
	}
	return 0;
}