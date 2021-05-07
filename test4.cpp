//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func(int val = 1) 
//	{
//		cout << "A->" << val << endl;
//	}
//	virtual void test()
//	{
//		func();
//	}
//};
//class B :public A
//{
//public:
//	void func(int val = 0)
//	{
//		cout << "B->" << val << endl;
//	}
//};
//int main()
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}
#include<iostream>
using namespace std;
class A
{
public:
	void foo()
	{
		printf("1");
	}
	void fun()
	{
		printf("2");
	}
};
class B :public A
{
public:
	void foo()
	{
		printf("3");
	}
	void fun()
	{
		printf("4");
	}
};
int main()
{
	A a;
	B b;
	A* p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A* ptr = (A*)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}