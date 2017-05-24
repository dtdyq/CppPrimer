#pragma once
#include<iostream>
#include<vector>
#include"Screen.h"
using namespace std;
class Window_mgr {
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = vector<Screen>::size_type;
	//将指定编号的屏幕重置为空白：
	void clear(ScreenIndex);
private:
	vector<Screen> screens{ Screen(24,80,' ') };
};
void Window_mgr::clear(ScreenIndex index) {  
	Screen& tmp = screens[index];
	tmp.contents = string(tmp.height*tmp.width, ' ');
}
