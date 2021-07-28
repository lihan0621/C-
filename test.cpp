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
//	//��Ա����������һ��������thisָ��
//	//��������غ�����Ϊ��Ա����ʱ�������б�����ʽ����Ĳ�������
//	//��Ҫ��ʵ�ʲ�����һ��
//	bool operator==(const Date& d)
//	{
//		return _y == d._y
//			&& _m == d._m
//			&& _d == d._d;
//	}
//	//�����Ҫ����������ֵ���򷵻�ֵ���Ͳ���Ϊ��
//	//����ֵ����Ϊ��ǰ������
//	Date& operator=(const Date& d)
//	{
//		//�ж϶����Ƿ���ͬһ������ͨ��ָ���ж�
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
////==��������أ�
////��������operator==
////bool operator==(const Date& d1, const Date& d2)
////{}
//
////�������͵��߼������޸�---->����������в�����Ϊ��������
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
//	//������ֵ
//	//������ʽ
//	d1.operator=(d2.operator=(d3));
//	//��д��ʽ
//	d1 = d2 = d3;
//
//	//���Ǹ�ֵ
//	//������һ���������죬�������еĶ��󴴽�һ���µĶ���
//	Date d4 = d1;
//}

//void test()
//{
//	Date d1(2021, 7, 25);
//	Date d2(2021, 8, 25);
//	Date d3(2021, 9, 25);
//	//��ֵ�����ø�ֵ��������غ������޸��Ѿ����ڵĶ�������
//	d1 = d2;
//	d2.operator=(d3);
//	//�ж����ڶ����Ƿ����
//	//������������غ�����������ʽ
//	//if (d1.operator==(d2))
//	//�����������غ������ǳ�Ա����
//	//if (operator==(d1, d2))
//	//��д��ʽ���ɶ��Ը�
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
//	//�������ʽ���忽�����죬���������Զ����ɿ�������
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
//	//���ÿ������죬����copy�������ݺ�data��ȫ��ͬ
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
//	//�������ٵ�ʱ�򣬱������Զ����������������Դ����
//	//����ʽ�������������������Զ�����Ĭ�ϵ���������
//	//���������Զ������Զ����Ա����������������Զ����Ա��Դ������
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData); // �ͷŶ��ϵĿռ�
//			_pData = NULL; // ��ָ����Ϊ��
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
//	//��̬������һ���ռ䣬���Դ��10��Ԫ��
//	//�ռ���׵�ַ_pData����
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
//	//���캯����������
//	//�޲Σ�Ĭ�Ϲ���
//	//�������Զ����ɵĹ��캯��ҲΪ�޲εĹ��캯������Ҳ��Ĭ�Ϲ���
//	//û����ʽ�����κ�һ�����캯�����������Ż��Զ������޲ι���
//	//Date()
//	//{
//	//	cout << "Date()" << endl;
//	//}
//	//�κ�һ�����캯���������������Զ����ɵģ������Զ������Զ����Ա��Ĭ�Ϲ���
//	//���û��Ĭ�Ϲ��죬�������ᱨ��
//	//Ĭ�Ϲ���ֻ����һ��
//	//ȫȱʡ�Ĺ��캯����Ҳ��һ��Ĭ�Ϲ���
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
//	//�������ڴ�������ʱ���Զ����ù��캯��
//	//��ɶ������ݵĳ�ʼ���������Ǵ�������
//	//�����޲ι���
//	Date d;
//	//���ô��εĹ��캯��
//	Date d2(2021, 7, 25);
//	//���ô��ĸ������Ĺ��캯��
//	Date d3(2021, 7, 1, 1000);
//	//������ʾ���ù��캯��
//	//d.Data(2021, 7, 25);
//	//���ǵ����޲ι��죬��������һ������
//	//��������d4
//	//�����б���
//	//����ֵ��Date
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