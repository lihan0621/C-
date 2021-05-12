//#include<iostream>
//using namespace std;
//static int a = 1;
//void fun1(void) { a = 2; }
//void fun2(void) { int a = 3; }
//void fun3(void) { static int a = 4; }
//int main()
//{
//	cout << a << endl;
//	fun1();	
//	cout << a << endl;
//	fun2();	
//	cout << a << endl;
//	fun3();
//	cout << a << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void f()
//	{
//		cout << "A" << endl;
//	}
//};
//class B : public A
//{
//public:
//	virtual void f()
//	{
//		cout << "B" << endl;
//	}
//};
//int main()
//{
//	A* a = new B;
//	a->f();
//	delete a;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "A" << endl;
//	}
//	~A()
//	{
//		cout << "deA" << endl;
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		cout << "B" << endl;
//	}
//	~B()
//	{
//		cout << "deB" << endl;
//	}
//};
//class C :public A, public B
//{
//	C()
//	{
//		cout << "C" << endl;
//	}
//	~C()
//	{
//		cout << "deC" << endl;
//	}
//};
//int main()
//{
//	A* a = new C;
//	delete a;
//	return 0;
//}