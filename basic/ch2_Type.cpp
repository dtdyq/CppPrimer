#include<iostream>
#include<vector>
using namespace std;

//复合类型：
int constexpr size() {//constexpr类型的函数
	return 12;
}
int testType() {
	int val = 1024;
	//引用：为对象起另外一个名字,引用必须被初始化
	int& rval = val;
	int& rl = rval;
	cout << rval <<" "<<rl<< endl;

	//指针：获取对象的地址，不能把对象直接赋值给指针
	int* pval = &val;
	cout << *pval << endl;//对指针进行解引用
	//不能直接操作void*指向的对象
	//指向指针的指针：
	int** pl = &pval;
	cout << **pl << endl;

	//const限定符：
	//const限定的值不能被改变：
	const int cval = 512;
	//除非声明extern关键字，否则const对象仅在文件内有效
	//const类型的值只能传给const类型的引用，理所当然
	const int& cr = cval;
	int nc = 512;
	//const int:不能通过该引用改变的对象的值
	const int& cr2 = nc;
	
	//const T*:指向常量的指针,不能通过指针修改常量的值
	const int* cp = &nc;
	//T *const:常量指针：该指针不能指向其他对象
	int* const cps = &nc;

	//constexpr:常量表达式：
	constexpr int xp = 23;
	//constexpr int sp = 23 * nc; 错误，必须是常量表达式
	constexpr int fp = size();

	//auto说明符：编译器自动推断值的类型：
	int aval = 33;
	auto ap = aval;//编译器自动将ap声明为int

	//decltype:类型指定符：可根据指定的表达式推断出其类型
	vector<int> vec{ 1,2,3,4,5 };
	decltype(vec.size()) size = vec.size();
	cout << size << endl;
	//使用两个括号的表达式永远是引用：
	decltype((aval)) ir = aval;
	ir = 99;
	cout << aval << endl;

	return 0;
}