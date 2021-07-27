#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using namespace std;

class A
{
public:
	void PrintA()
	{
		//空指针不能进行解引用
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->PrintA();
	p->Show();
}

//class Date
//{
//public:
//	//每一个非静态成员函数中，都有一个this指针
//	//作为函数的第一个形参
//	//只存在于成员函数中
//	//this指向当前调用此函数的对象
//	//this类型：类类型* const this
//	//this的指向是不能发生改变的
//	void Display()  //void Display(this);
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//void SetDate(this, int year, int month, int day);
//	void SetDate(int year, int month, int day) 
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display();
//	d2.Display();
//	return 0;
//}

//类的定义：本身不占用运行空间
//class A
//{
//public:
//	int _a;
//};
//
//class B
//{
//public:
//	int fun(int a, int b)
//	{
//		return a + b;
//	}
//public:
//	int _a;
//};
//
//class C
//{
//public:
//	int fun(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class D
//{};
//
//void test()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//}

//void test()
//{
//	//定义一个类类型的变量：称为类的实例化
//	//实例化的变量称为类的对象
//	A oa;//oa是类A实例化的一个对象
//}

//你可以认为它是一个结构体，也可以认为它是一个类
//struct Student
//{
//	//成员函数
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	//成员变量或者属性
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
////C++中常用的类的定义方式：class 类名 { 所有成员 }；
//class Student
//{
//public:
//	//成员函数
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//	//成员变量或者属性
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//void test()
//{
//	Student stu;
//	stu.SetStudentInfo("abc", "男", 20);
//	stu.PrintStudentInfo();
//	cout << stu._gender << endl;
//}

//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}