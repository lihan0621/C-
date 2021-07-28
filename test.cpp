#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>

using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
void test()
{
	String s1("hello");
	String s2("world");
	s1 = s2;
}



//class Date
//{
//public:
//	Date(int y = 1, int m = 1, int d = 1)
//	{
//		_y = y;
//		_m = m;
//		_d = d;
//	}
//	bool isEqual(const Date d)
//	{
//		return _y == d._y
//			&& _m == d._m
//			&& _d == d._d;
//	}
//
//	Date(const Date& d)
//	{
//		_y = d._y;
//		_m = d._m;
//		_d = d._d;
//		cout << "Date(const Date&)"<< endl;
//	}
//
//	//成员函数都会有一个隐含的this指针
//	//运算符重载函数作为成员函数时，参数列表中显式定义的参数个数
//	//需要比实际参数少一个
//	bool operator==(const Date& d)
//	{
//		return _y == d._y
//			&& _m == d._m
//			&& _d == d._d;
//	}
//	//如果需要进行连续赋值，则返回值类型不能为空
//	//返回值类型为当前类类型
//	Date& operator=(const Date& d)
//	{
//		//判断对象是否是同一个对象：通过指针判断
//		if (this != &d)
//		{
//			_y = d._y;
//			_m = d._m;
//			_d = d._d;
//			cout << "operator=" << endl;
//		}
//		return *this;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _y;
//	int _m;
//	int _d;
//};
//
////==运算符重载：
////函数名：operator==
////bool operator==(const Date& d1, const Date& d2)
////{}
//
////内置类型的逻辑不能修改---->运算符的所有参数都为内置类型
////bool operator+(int a, int b)
////{
////	return a * b;
////}
//
//void test()
//{
//	Date d1(2021, 7, 25);
//	Date d2(2021, 8, 25);
//	Date d3(2021, 9, 25);
//	//连续赋值
//	//完整形式
//	d1.operator=(d2.operator=(d3));
//	//简写形式
//	d1 = d2 = d3;
//
//	//不是赋值
//	//这里是一个拷贝构造，利用已有的对象创建一个新的对象
//	Date d4 = d1;
//}

//void test()
//{
//	Date d1(2021, 7, 25);
//	Date d2(2021, 8, 25);
//	Date d3(2021, 9, 25);
//	//赋值：调用赋值运算符重载函数：修改已经存在的对象内容
//	d1 = d2;
//	d2.operator=(d3);
//	//判断日期对象是否相等
//	//调用运算符重载函数的完整形式
//	//if (d1.operator==(d2))
//	//如果运算符重载函数不是成员函数
//	//if (operator==(d1, d2))
//	//简写形式：可读性高
//	if(d1 == d2)
//	{
//		cout << "==" << endl;
//	}
//	else
//	{
//		cout << "!=" << endl;
//	}
//	//if (d1.isEqual(d2))
//	//{}
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int, int, int)" << endl;
//	}
//	//如果不显式定义拷贝构造，编译器会自动生成拷贝构造
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test()
//{
//	Date date(2021, 7, 25);
//	//调用拷贝构造，创建copy对象，内容和data完全相同
//	Date copy(date);
//}

//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	//对象销毁的时候，编译器自动调用析构，完成资源清理
//	//不显式定义析构，编译器会自动生成默认的析构函数
//	//析构函数自动调用自定义成员的析构函数，完成自定义成员资源的清理
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData); // 释放堆上的空间
//			_pData = NULL; // 将指针置为空
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//
//void test()
//{
//	//动态开辟了一个空间，可以存放10个元素
//	//空间的首地址_pData保存
//	SeqList sq(1000);
//	cout << sizeof(sq) << endl;
//}

//class A
//{
//public:
//	int _a;
//	A(int a = 10)
//	{
//		_a = a;
//		cout << "A()" << endl;
//	}
//};
//
//class Date
//{
//public:
//	//构造函数可以重载
//	//无参：默认构造
//	//编译器自动生成的构造函数也为无参的构造函数，它也是默认构造
//	//没有显式定义任何一个构造函数，编译器才会自动生成无参构造
//	//Date()
//	//{
//	//	cout << "Date()" << endl;
//	//}
//	//任何一个构造函数（包括编译器自动生成的）都会自动调用自定义成员的默认构造
//	//如果没有默认构造，编译器会报错
//	//默认构造只能有一个
//	//全缺省的构造函数，也是一种默认构造
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int, int, int)" << endl;
//	}
//	Date(int year, int month, int day, int num)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << "Date(int, int, int, int)" << endl;
//	}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	A _a;
//};
//
//void test()
//{
//	//编译器在创建对象时，自动调用构造函数
//	//完成对象内容的初始化，并不是创建对象
//	//调用无参构造
//	Date d;
//	//调用带参的构造函数
//	Date d2(2021, 7, 25);
//	//调用带四个参数的构造函数
//	Date d3(2021, 7, 1, 1000);
//	//不能显示调用构造函数
//	//d.Data(2021, 7, 25);
//	//不是调用无参构造，而是声明一个函数
//	//函数名：d4
//	//参数列表：空
//	//返回值：Date
//	Date d4();
//	 
//	 
//	 
//}

int main()
{
	test();
	system("pause");
	return 0;
}