#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using namespace std;

class A
{
public:
	void PrintA()
	{
		//��ָ�벻�ܽ��н�����
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
//	//ÿһ���Ǿ�̬��Ա�����У�����һ��thisָ��
//	//��Ϊ�����ĵ�һ���β�
//	//ֻ�����ڳ�Ա������
//	//thisָ��ǰ���ô˺����Ķ���
//	//this���ͣ�������* const this
//	//this��ָ���ǲ��ܷ����ı��
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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

//��Ķ��壺����ռ�����пռ�
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
//	//����һ�������͵ı�������Ϊ���ʵ����
//	//ʵ�����ı�����Ϊ��Ķ���
//	A oa;//oa����Aʵ������һ������
//}

//�������Ϊ����һ���ṹ�壬Ҳ������Ϊ����һ����
//struct Student
//{
//	//��Ա����
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
//	//��Ա������������
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
////C++�г��õ���Ķ��巽ʽ��class ���� { ���г�Ա }��
//class Student
//{
//public:
//	//��Ա����
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
//	//��Ա������������
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//void test()
//{
//	Student stu;
//	stu.SetStudentInfo("abc", "��", 20);
//	stu.PrintStudentInfo();
//	cout << stu._gender << endl;
//}

//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}