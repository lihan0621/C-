//#include<iostream>
//using namespace std;
//class Test
//{
//public:
//	int a;
//	int b;
//	virtual void fun(){ }
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//
//int main()
//{
//	Test obj(5, 10);
//	int* pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << "a = " << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void fun(const char** m)
//{
//	++m;
//	cout << *m << endl;
//}
//int main()
//{
//	 const char* a[] = { "morning","afternoon","evening" };
//	const char** p;
//	p = a;
//	fun(p);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int fun(int a)
//{
//	a ^= (1 << 5) - 1;
//	return a;
//}
//int main()
//{
//	int ret = fun(21);
//	cout << ret << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class MyClass
//{
//public:
//	MyClass(int i = 0) { cout << 1; }
//	MyClass(const MyClass& x) { cout << 2; }
//	MyClass& operator=(const MyClass& x) { cout << 3; }
//	~MyClass() { cout << 4; }
//};
//int main()
//{
//	MyClass obj1(1), obj2(2), obj3(obj1);
//	return 0;
//}