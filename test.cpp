#include <iostream>
#include <stdlib.h>

using namespace std;

class Date; // 前置声明
class Time
{
	// 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量	
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	void fun(Date& d)
	{
		cout << d._year << d._month << d._day << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	//友元类中的所有函数变成另一个类的友元函数
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

void test()
{

}


//class Date
//{
//public:
//	//友元函数的声明：此函数可以访问当前类的私有成员
//	//此函数是一个普通函数，不属于类的成员函数
//	//友元的声明可以放在类的任何地方，不影响使用
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	Date(int y = 1, int m = 2, int d = 3)
//		:_y(y)
//		,_m(m)
//		,_d(d)
//	{}
//	//void operator<<(ostream& _cout)
//	//{
//	//	_cout << _y << "-" << _m << "-" << _d << endl;
//	//}
//private:
//	int _y;
//	int _m;
//	int _d;
//};
//
////返回值为ostream，支持连续输出
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._y << "-" << d._m << "-" << d._d << endl;
//	return _cout;
//}
//
//void test()
//{
//	Date d(2021, 7, 28);
//	//d.operator<<(cout);
//	//d << cout;
//	cout << d;
//	//错误
//	//d.operator<<(cout, d);
//	//连续输出
//	cout << d << endl;
//}

//class A
//{
//public:
//	A()
//	{
//		++_count;
//	}
//	A(const A& a)
//	{
//		++_count;
//	}
//	int getCount()
//	{
//		return _count;
//	}
////private:
//	//static成员是所有对象共享
//	//static成员变量，必须在类外初始化
//	static int _count;
//};
//
//int A::_count = 0;
//A funA(A a)
//{
//	return a;
//}
//
//void test()
//{
//	A a1;
//	A a2;
//	A a3 = funA(a1);
//	cout << a1.getCount() << endl;
//	cout << a2.getCount() << endl;
//	cout << a3.getCount() << endl;
//	//static成员访问形式
//	//1.对象.static成员
//	cout << a1._count << endl;
//	//2.类型 + :: + static成员
//	cout << A::_count << endl;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& aobj)
//	{
//		_a = aobj._a;
//	}
//private:
//	int _a;
//};
//
//void test()
//{
//	A aobj(10); //构造
//	A aobj2 = aobj; //拷贝构造
//	A aobj3 = 20;
//	aobj3 = 40;
//}

//class A
//{
//public:
//	//初始化列表中初始化顺序：按照声明顺序，并不是初始化列表中的书写顺序
//	A(int a)
//		:_a2(a)
//		, _a1(_a2)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//void test()
//{
//	A aa(1);
//	aa.Print();
//}

//class Time
//{
//public:
//	Time(int hour, int minute, int second)
//		:_hour(hour)
//		,_minute(minute)
//		,_second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		//初始化列表: 真正初始化的位置
//		//引用成员必须在初始化列表中进行初始化
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _hour(12)
//		, _time(12, 50, 34)
//	{
//		//并不是初始化
//	/*	_year = year;
//		_month = month;
//		_day = day;*/
//	}
//private:
//	int& _year;
//	int& _month;
//	int& _day;
//	const int _hour;
//	Time _time;
//};
//
//void test()
//{
//	Date d(2021, 7, 28);
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		//初始化列表: 真正初始化的位置
//		:_year(year)
//		, _month(month)
//		,_day(day)
//	{
//		//并不是初始化
//	/*	_year = year;
//		_month = month;
//		_day = day;*/
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void test()
//{
//	Date d(2021, 7, 28);
//}

int main()
{
	test();
	system("pause");
	return 0;
}