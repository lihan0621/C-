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
//	//capacity����ǰstring�������Դ�ŵ�Ԫ�ظ���
//	int cap = str.capacity();
//	str.resize(10);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(1);
//	sz = str.size();
//	cap = str.capacity();
//	str.resize(20);
//	//resize��������֮���size��������ʱ������Ҳ�ᷢ���仯
//	sz = str.size();
//	cap = str.capacity();
//	//reserve���޸�������ֻ����������
//	//��Ӱ��size
//	str.reserve(60);
//	sz = str.size();
//	cap = str.capacity();
//	str.reserve(10);
//	sz = str.size();
//	cap = str.capacity();
//	//clear�������Ч�ַ���ֻӰ��size
//	str.clear();
//	sz = str.size();
//	cap = str.capacity();
//}

//void test()
//{
//	string str;
//	cout << str.size() << endl;
//	//resize���޸���Ч�ַ��ĸ���
//	//resize(n)�������Ч�ַ��������ӣ���������λ�����'\0'
//	//resize(n, ch)�������Ч�ַ��������ӣ���������λ�����ch
//	//���size��С������������
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

//string�ķ��ʷ�ʽ
//1.forѭ�� + operator[]
//2.������
//3.��Χfor
//�����ַ�ʽ�������޸�����

//void test()
//{
//	string str = "12345";
//	//��Χfor��ʵ������ͨ��������ʵ�ֵ�
//	//֧�ֵ��������ʵ��Զ������Ͷ�����֧�ַ�Χfor
//	for (const auto& ch : str)
//	{
//		cout << ch << " ";
//	}
//}

//void test()
//{
//	//���������
//	string str = "12345";
//	//���һ��Ԫ�ص�λ��
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend())
//	{
//		cout << *it << " "; //54321
//		//�����ƶ�
//		++it;
//	}
//	//ֻ���ķ��������
//}

//void test()
//{
//	//���������
//	string str = "12345";
//	//��ʼλ�õĵ�����
//	string::iterator it = str.begin();
//	for (; it != str.end(); ++it)
//	{
//		//�������Ľ�����
//		cout << *it << " ";
//		//ͨ�������ò���Ҳ���Խ������ݵ��޸�
//		*it = 'a';
//	}
//	cout << endl;
//
//	//const����ֻ����const������
//	const string str2 = "abcde";
//	//ֻ��������
//	string::const_iterator it2 = str2.begin();
//	while (it2 != str2.end())
//	{
//		cout << *it2 << " ";
//		//ֻ�������������޸�����
//		//*it2 = '1';
//		++it2;
//	}
//}

//void test()
//{
//	const string str = "12345";
//	string str2 = "12345";
//	char ch = str[3];
//	//const���󷵻ص���const���ã����ܱ��޸�
//	//str[3] = 'a';
//	//��const������÷�const�ӿڣ����Ա��޸�
//	str2[3] = 'a';
//	str2.at(3) = 'b';
//	//[]������λ�ò���Խ��
//}

//void test()
//{
//	/*default (1)
//		string();*/
//	//�����յ�string����
//	string str;
//	/*copy(2)
//		string(const string & str);*/
//	string copy(str);
//
//	/*from c - string(4)
//		string(const char* s);*/
//	//��C���ķ�ʽ����string����
//	string str2("abc");
//	/*substring(3)
//		string(const string & str, size_t pos, size_t len = npos);*/
//	//��ȡ�ַ������ִ�
//	string substr(str2, 1, 2);//"bc"
//	/*from sequence(5)
//		string(const char* s, size_t n);*/
//	//��ȡ�ַ�����ǰn���ַ�
//	string str3("12345678", 5);//"12345"
//	/*fill(6)
//		string(size_t n, char c);*/
//	//��������n����ͬ�ַ����ַ���
//	string str4(10, 'a');//"aaaaaaaaaa"
//	string str5 = "abcde"; //���ι������ʽ����ת��
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