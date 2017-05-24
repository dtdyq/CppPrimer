#pragma once
#include<iostream>
#include<string>
using namespace std;
class Screen {
	//类友元：在Window_ngr中可以访问Screen中的私有成员
	friend class Window_mgr;
public:
	//typedef string::size_type pos;等价于：
	using pos = string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd,char c) 
		:height(ht), width(wd), contents(ht*wd, c) {};
	//读取光标处字符：
	char get() const{//隐式内联
		return contents[cursor];
	}
	inline char get(pos ht, pos wd)const;//显式内联
	Screen& move(pos r, pos c);
	void some_member()const;//统计计数
	//设置光标所在或任意位置字符：
	Screen& set(char);
	Screen& set(pos, pos, char);

	//定义打印函数：根据对象是否是const重载了display函数
	Screen& display(ostream& os) {
		do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const {
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr = 0;//声明为mutable，在const的对象中也可以修改
	void do_display(ostream& os) const{
		os << contents;
	}
};
inline Screen& Screen::move(pos r, pos c) {
	pos row = r*width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c)const {
	pos row = r*width;
	return contents[row + c];
}
void Screen::some_member()const {
	++access_ctr;
}
Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
Screen& Screen::set(pos r, pos c, char cc) {
	contents[r*width + c] = cc;
	return *this;
}