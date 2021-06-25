#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			_str = temp;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	void strShow()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};
int main()
{
	String s1;
	String s2("Hello");
	String s3(s2);
	String s4("aaaaaaaaaaaa");
	s1.strShow();   //空串
	s1 = s2;
	s2.strShow();	//s2创建
	s3.strShow();	//拷贝构造
	s2 = s4;		//赋值
	s2.strShow();
	system("pause");
	return 0;
}
