#include"Folder.h"
void Folder::addMsg(Message& m) {
	ms.insert(&m);
}
void Folder::remMsg(Message& m) {
	ms.erase(&m);
}