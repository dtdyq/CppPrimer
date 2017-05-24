#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
int main() {
	//IO对象无拷贝和赋值：
	ofstream o1, o2;
	//o1 = o2;    !!!error
	//刷新输出缓冲区：
	string str = "outbuf";
	cout << str << ends;//输出一个空格
	cout << str << flush;
	//设置任何输出都立即刷新缓冲区：
	cout << unitbuf;
	cout << nounitbuf;//取消设置

	//将输入关联到输出：
	cin.tie(&cout);

	//文件输入输出：
	ofstream fo("test.txt");
	fo << "hello io" << endl;
	ifstream fi("test.txt");
	fi >> str;
	cout << str << endl;

	//文件模式：
	ofstream out("test.txt", ofstream::app);//追加
	ofstream out2("test.txt", ofstream::ate);//定位到文件末尾
	ofstream out3("test.txt", ofstream::binary);//以二进制形式打开文件
	
	//string流：
	stringstream sio;
	sio << "hello";
	//获取流中的字符串
	cout << sio.str() << endl;
}