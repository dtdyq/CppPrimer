#include<iostream>
using namespace std;
class B {
public:
	B() {
		cout << "B" << endl;
	}
	virtual ~B() {
		cout << "~B" << endl;
	}
	void print() {};
};
class C :public B {
public:
	C():B() {
		cout << "C" << endl;
	}
	void print(){
		cout << "C's print" << endl;
	}
	~C() {
		cout << "~C" << endl;
	}
};
int main() {
	
	B*b = new C();
	b->print();
	delete b;
	return 0;
}