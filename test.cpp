#include <iostream>
#include <stdlib.h>

using namespace std;

class Date; // ǰ������
class Time
{
	// ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����	
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
	//��Ԫ���е����к��������һ�������Ԫ����
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//	//��Ԫ�������������˺������Է��ʵ�ǰ���˽�г�Ա
//	//�˺�����һ����ͨ��������������ĳ�Ա����
//	//��Ԫ���������Է�������κεط�����Ӱ��ʹ��
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
////����ֵΪostream��֧���������
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
//	//����
//	//d.operator<<(cout, d);
//	//�������
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
//	//static��Ա�����ж�����
//	//static��Ա�����������������ʼ��
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
//	//static��Ա������ʽ
//	//1.����.static��Ա
//	cout << a1._count << endl;
//	//2.���� + :: + static��Ա
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
//	A aobj(10); //����
//	A aobj2 = aobj; //��������
//	A aobj3 = 20;
//	aobj3 = 40;
//}

//class A
//{
//public:
//	//��ʼ���б��г�ʼ��˳�򣺰�������˳�򣬲����ǳ�ʼ���б��е���д˳��
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
//		//��ʼ���б�: ������ʼ����λ��
//		//���ó�Ա�����ڳ�ʼ���б��н��г�ʼ��
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _hour(12)
//		, _time(12, 50, 34)
//	{
//		//�����ǳ�ʼ��
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
//		//��ʼ���б�: ������ʼ����λ��
//		:_year(year)
//		, _month(month)
//		,_day(day)
//	{
//		//�����ǳ�ʼ��
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