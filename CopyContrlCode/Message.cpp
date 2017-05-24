#include"Message.h"
#include"Folder.h"
void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(*this);
}
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(*this);
}
void Message::add_to_Folder(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(*this);
	}
}
Message::Message(const Message& m)
	:context(m.context),folders(m.folders) {
	add_to_Folder(m);
}
void Message::remove_from_Folders() {
	for (auto f : folders) {
		f->remMsg(*this);
	}
}
Message::~Message() {
	remove_from_Folders();
}
Message& Message::operator=(const Message& m) &{
	remove_from_Folders();
	context = m.context;

	folders = m.folders;
	add_to_Folder(m);
	return *this;
}
void swap(Message& lhs, Message& rhs) {
	using std::swap;//!!!!!!!这个有什么用？
	//将每个Message从它原来的folder中删除：
	for (auto f : lhs.folders) {
		f->remMsg(lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(rhs);
	}
	swap(lhs.context, rhs.context);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders) {
		f->addMsg(lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(rhs);
	}
}
void Message::move_Folders(Message*s) {
	folders = std::move((*s).folders);
	for (auto f : folders) {
		f->remMsg(*s);
		f->addMsg(*this);
	}
	s->folders.clear();
}
Message::Message(Message&& m):context(std::move(m.context)){
	move_Folders(&m);
}
Message& Message::operator=(Message&& m) {
	if (this != &m) {
		remove_from_Folders();
		context = std::move(m.context);
		move_Folders(&m);
	}
	return *this;
}