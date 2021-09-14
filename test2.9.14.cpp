#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{}

	//default让编译器显示生成一个默认构造函数
	A() = default;

	A(const A&) = default;

	A& operator=(const A&) = default;

};

class B
{
public:
	B()
	{}

	//成员函数如果定义为删除函数，表示函数不能被使用
	//防拷贝：把拷贝构造和赋值运算符定义成删除函数
	B(const B&) = delete;

	B& operator=(const B&) = delete;
};

void test()
{
	B b;

	//B copy(b);
	//b = copy;
}

//int fun(int a)
//{
//	return a;
//}
//
//void test()
//{
//	auto a = 10;
//	int b = 1;
//	int c = 2;
//	decltype(b + c) d;
//	cout << typeid(d).name() << endl;
//	cout << typeid(decltype(fun(a))).name() << endl;
//	cout << typeid(decltype(fun)).name() << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}