#include<iostream>
#include<stdlib.h>
using namespace std;
class Date
{
public:
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
void test()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();
}
//void test()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p)
//		cout << "小端" << endl;
//	else
//	cout << "大端" << endl;
//}
//struct B
//{
//	int a;
//	int b;
//	double d;
//	int e;
//};
//struct A
//{
//	char a;
//	double b;
//	char d;
//	B objB;
//};
//
//void test()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(A) << endl;
//}
//class A
//{
//public:
//	int fun(int a,int b)
//	{
//		return a + b;
//	}
//private:
//	int a;
//	int b;
//};
//class B
//{
//private:
//	int a;
//	int b;
//};
//class C
//{
//public:
//	int fun(int a, int b)
//	{
//		return a + b;
//	}
//};
//class D
//{};
//void test()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//}
int main()
{
	test();
	system("pause");
	return 0;
}