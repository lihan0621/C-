#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//void test()
//{
//	string str = "123";
//	string str2 = "abc";
//	/*string(1)
//		string& insert(size_t pos, const string & str);*/
//	str.insert(0, str2);  //abc123
//	/*substring(2)
//		string& insert(size_t pos, const string & str, size_t subpos, size_t sublen);*/
//	str.insert(4, str2, 1, 2);  //abc1bc23
//	/*c - string(3)
//		string & insert(size_t pos, const char* s);*/
//	str.insert(str.size(), "abc");
//	/*buffer(4)
//		string& insert(size_t pos, const char* s, size_t n);*/
//	str.insert(5, "12345", 4);  //abc1b 1234 c23abc
//	/*fill(5)
//		string& insert(size_t pos, size_t n, char c);
//	void insert(iterator p, size_t n, char c);*/
//	str.insert(str.begin(), 2, '0');  //00 abc1b 1234 c23abc
//	/*single character(6)
//		iterator insert(iterator p, char c);*/
//	/*range(7)
//		template <class InputIterator>
//	void insert(iterator p, InputIterator first, InputIterator last);*/
//	str.insert(str.end(), str2.begin(), str2.end());  //00 abc1b 1234 c23abc
//
//}

//void test()
//{
//	string str;
//	string str2 = "123";
//	str += str2; //123
//	str += "abc"; //123abc
//	str += '4'; //123abc4
//	str.operator+=('5'); //123abc45
//}

//void test()
//{
//	string str = "123";
//	int sz = str.size();
//	//capacity：当前string中最多可以存放的元素个数
//	int cap = str.capacity();
//	str.resize(10);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(1);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(20);
//	//resize：当调整之后的size大于容量时，容量也会发生变化
//	sz = str.size();
//	cap = str.capacity();
//	//reserve：修改容量：只能增加容量
//	//不影响size
//	str.reserve(60);
//	sz = str.size();
//	cap = str.capacity();
//	str.reserve(10);
//	sz = str.size();
//	cap = str.capacity();
//	//clear：清空有效字符：只影响size
//	str.clear();
//	sz = str.size();
//	cap = str.capacity();
//}

//void test()
//{
//	string str;
//	cout << str.size() << endl;
//	//resize：修改有效字符的个数
//	//resize(n)：如果有效字符个数增加，则新增的位置填充'\0'
//	//resize(n, ch)：如果有效字符个数增加，则新增的位置填充ch
//	//如果size减小，不会进行填充
//	str.resize(10);
//	cout << str.size() << endl;
//	string str2 = "123";
//	cout << str2.size() << endl;
//	str2.resize(10);
//	cout << str2.size() << endl;
//	str2.resize(2);
//	cout << str2.size() << endl;
//	str2.resize(5, 'a'); //"12aaa"
//}

//string的访问方式
//1.for循环 + operator[]
//2.迭代器
//3.范围for
//这三种方式都可以修改内容

//void test()
//{
//	string str = "12345";
//	//范围for：实际上是通过迭代器实现的
//	//支持迭代器访问的自定义类型都可以支持范围for
//	for (const auto& ch : str)
//	{
//		cout << ch << " ";
//	}
//}

//void test()
//{
//	//反向迭代器
//	string str = "12345";
//	//最后一个元素的位置
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend())
//	{
//		cout << *it << " "; //54321
//		//反向移动
//		++it;
//	}
//	//只读的反向迭代器
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
//		cout << *it << " ";
//		//通过解引用操作也可以进行内容的修改
//		*it = 'a';
//	}
//	cout << endl;
//
//	//const对象只能用const迭代器
//	const string str2 = "abcde";
//	//只读迭代器
//	string::const_iterator it2 = str2.begin();
//	while (it2 != str2.end())
//	{
//		cout << *it2 << " ";
//		//只读迭代器不能修改内容
//		//*it2 = '1';
//		++it2;
//	}
//}

//void test()
//{
//	const string str = "12345";
//	string str2 = "12345";
//	char ch = str[3];
//	//const对象返回的是const引用，不能被修改
//	//str[3] = 'a';
//	//非const对象调用非const接口，可以被修改
//	str2[3] = 'a';
//	str2.at(3) = 'b';
//	//[]操作，位置不能越界
//}

//void test()
//{
//	/*default (1)
//		string();*/
//	//创建空的string对象
//	string str;
//	/*copy(2)
//		string(const string & str);*/
//	string copy(str);
//
//	/*from c - string(4)
//		string(const char* s);*/
//	//以C风格的方式创建string对象
//	string str2("abc");
//	/*substring(3)
//		string(const string & str, size_t pos, size_t len = npos);*/
//	//截取字符串的字串
//	string substr(str2, 1, 2);//"bc"
//	/*from sequence(5)
//		string(const char* s, size_t n);*/
//	//获取字符串的前n个字符
//	string str3("12345678", 5);//"12345"
//	/*fill(6)
//		string(size_t n, char c);*/
//	//创建具有n个相同字符的字符串
//	string str4(10, 'a');//"aaaaaaaaaa"
//	string str5 = "abcde"; //单参构造的隐式类型转换
//
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