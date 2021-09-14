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

	//移动构造：使用移动语义，把对象中的资源移动到另一个对象中去
	//不进行深拷贝，提高拷贝效率
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
//	//左值引用&：可以引用左值，也可以引用右值
//	int a = 10;
//	int& ra = a;
//	const int& ri = 10;
//	const int& ri2 = fun(a);
//
//	//右值引用&&：只能引用右值
//	//右值引用不能引用左值
//	//int&& ra = a;
//	int&& ri = 10;
//	int&& ri2 = fun(a);
//}

//void test()
//{
//	//左值：可以出现在 "=" 的两边;
//	//右值：只能出现在 "=" 的右边;
//
//	//左值：可以取地址
//	//右值：不能取地址
//
//	//但是上面这两种分类都不是完全正确
//
//	int a = 10;
//	int b = a;
//
//	//10 = b;
//	int* pa = &a;
//	//int* pi = &10;
//
//	//C++中的区分方式：
//	//右值：常量，临时变量/匿名变量，将亡值
//	//左值：其他的都为左值
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
//	//default让编译器显示生成一个默认构造函数
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
//	//成员函数如果定义为删除函数，表示函数不能被使用
//	//防拷贝：把拷贝构造和赋值运算符定义成删除函数
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