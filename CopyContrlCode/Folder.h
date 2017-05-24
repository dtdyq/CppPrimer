#pragma once
#include"Message.h"
class Folder {
public:
	Folder() = default;
	Folder(const Folder& f)=default;
	Folder& operator=(const Folder& f)=default;
	void addMsg(Message&);
	void remMsg(Message&);
	~Folder() = default;
private:
	set<Message*> ms;
};