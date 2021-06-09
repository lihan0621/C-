#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
void test()
{
	//范围for：可以访问范围确定的序列
	int arr[] = { 1, 2, 3, 4, 5 };
	for (const auto& e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto& e : arr)
	{
		e = 10;
		cout << e << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}



//void test()
//{
//	//反向迭代器
//	string str = "12345";
//	//最后一个元素的位置
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend())
//	{
//		cout << *it << " ";
//		//反向移动
//		++it;
//	}
//	string::const_reverse_iterator cit = str.crbegin();
//	while (cit != str.crend())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	//只读的反向迭代器
//	const string str2 = "abcde";
//	string::const_reverse_iterator it2 = str2.rbegin();
//	while (it2 != str2.rend())
//	{
//		cout << *it2 << " ";
//		//只读迭代器不支持修改
//		//*it2 =  'a';
//		++it2;
//	}
//}



//void test()
//{
//	//正向迭代器
//	string str = "12345";
//	//起始位置的迭代器
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it)
//	{
//		//迭代器的解引用
//		cout << *it << " " ;
//		//可以通过迭代器进行内容的修改
//		*it = 'a';
//	}
//	const string str2 = "abcde";
//		//只读迭代器
//		string::const_iterator it2= str2.begin();
//	while (it2 != str2.end())
//	{
//		cout << *it2 << " ";
//		//只读迭代器不能修改内容
//		//*it2 = 'a';
//		++it2;
//	}
//}


//void test()
//{
//	const string str = "12345";
//	string str2 = "12345";
//	//const对象，调用接口：const char& operator[](size_t pos)const
//	char ch = str[3];
//	const char& ref = str[3];
//	//非const对象，调用接口：char& operator[](size_t pos)
//	char& ref2 = str2[3];
//	str2[3] = 'a';
//	str2.at(3) = 'b';
//}


//void test()
//{
//	/*default (1)
//		string();*/
//	//创建空的string对象
//	string str;
//	/*copy(2)
//	string(const string& str);*/
//	string copy(str);
//	/*from c - string(4)
//		string(const char* s);*/
//	string str2("abc");
//	/*substring(3)
//		string(const string& str, size_t pos, size_t len = npos);*/
//	string substr(str2, 1, 2);//bc
//	/*from sequence(5)
//		string(const char* s, size_t n);*/
//	string str3("12345678", 5);//12345
//	/*fill(6)
//		string(size_t n, char c);*/
//	string str4(10, 'a');//"aaaaaaaaaa"
//	string str5 = "abcde";//单参构造的隐式类型转换
//	str5 = str4;
//	str5 = "123";
//	str5 = 'b';
//}



int main()
{
	test();
	system("pause");
	return 0;
}