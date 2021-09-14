#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		cout << "String(const String&)" << endl;
	}

	//�ƶ����죺ʹ���ƶ����壬�Ѷ����е���Դ�ƶ�����һ��������ȥ
	//�������������߿���Ч��
	String(String&& s) noexcept
		:_str(s._str)
	{
		s._str = nullptr;
		cout << "String(String&&)" << endl;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		cout << "String& operator=(const String&)" << endl;
		return *this;
	}

	String& operator=(String&& s) noexcept
	{
		if (this != &s)
		{
			delete[] _str;
			_str = s._str;
			s._str = nullptr;
		}
		cout << "String& operator=(String&&)" << endl;
		return *this;
	}

	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};
void test()
{
	String s1("hello");
	String s2("world");
	cout << "copy" << endl;
	String s3(s1 + s2);
	String s4(s2);
	s4 = s1 + s2;
}

int fun(int a)
{
	return a;
}

//void test()
//{
//	//��ֵ����&������������ֵ��Ҳ����������ֵ
//	int a = 10;
//	int& ra = a;
//	const int& ri = 10;
//	const int& ri2 = fun(a);
//
//	//��ֵ����&&��ֻ��������ֵ
//	//��ֵ���ò���������ֵ
//	//int&& ra = a;
//	int&& ri = 10;
//	int&& ri2 = fun(a);
//}

//void test()
//{
//	//��ֵ�����Գ����� "=" ������;
//	//��ֵ��ֻ�ܳ����� "=" ���ұ�;
//
//	//��ֵ������ȡ��ַ
//	//��ֵ������ȡ��ַ
//
//	//�������������ַ��඼������ȫ��ȷ
//
//	int a = 10;
//	int b = a;
//
//	//10 = b;
//	int* pa = &a;
//	//int* pi = &10;
//
//	//C++�е����ַ�ʽ��
//	//��ֵ����������ʱ����/��������������ֵ
//	//��ֵ�������Ķ�Ϊ��ֵ
//	b = fun(a);
//	//fun(a) = a;
//	//int* pa = &fun(a);
//}

//class A
//{
//public:
//	A(int a)
//	{}
//
//	//default�ñ�������ʾ����һ��Ĭ�Ϲ��캯��
//	A() = default;
//
//	A(const A&) = default;
//
//	A& operator=(const A&) = default;
//
//};
//
//class B
//{
//public:
//	B()
//	{}
//
//	//��Ա�����������Ϊɾ����������ʾ�������ܱ�ʹ��
//	//���������ѿ�������͸�ֵ����������ɾ������
//	B(const B&) = delete;
//
//	B& operator=(const B&) = delete;
//};
//
//void test()
//{
//	B b;
//
//	//B copy(b);
//	//b = copy;
//}

//int fun(int a)
//{
//	return a;
//}
//
//void test()
//{
//	auto a = 10;
//	int b = 1;
//	int c = 2;
//	decltype(b + c) d;
//	cout << typeid(d).name() << endl;
//	cout << typeid(decltype(fun(a))).name() << endl;
//	cout << typeid(decltype(fun)).name() << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}