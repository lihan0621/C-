#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;
void test()
{
	//��Χfor�����Է��ʷ�Χȷ��������
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
//	//���������
//	string str = "12345";
//	//���һ��Ԫ�ص�λ��
//	string::reverse_iterator it = str.rbegin();
//	while (it != str.rend())
//	{
//		cout << *it << " ";
//		//�����ƶ�
//		++it;
//	}
//	string::const_reverse_iterator cit = str.crbegin();
//	while (cit != str.crend())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//	//ֻ���ķ��������
//	const string str2 = "abcde";
//	string::const_reverse_iterator it2 = str2.rbegin();
//	while (it2 != str2.rend())
//	{
//		cout << *it2 << " ";
//		//ֻ����������֧���޸�
//		//*it2 =  'a';
//		++it2;
//	}
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
//		cout << *it << " " ;
//		//����ͨ���������������ݵ��޸�
//		*it = 'a';
//	}
//	const string str2 = "abcde";
//		//ֻ��������
//		string::const_iterator it2= str2.begin();
//	while (it2 != str2.end())
//	{
//		cout << *it2 << " ";
//		//ֻ�������������޸�����
//		//*it2 = 'a';
//		++it2;
//	}
//}


//void test()
//{
//	const string str = "12345";
//	string str2 = "12345";
//	//const���󣬵��ýӿڣ�const char& operator[](size_t pos)const
//	char ch = str[3];
//	const char& ref = str[3];
//	//��const���󣬵��ýӿڣ�char& operator[](size_t pos)
//	char& ref2 = str2[3];
//	str2[3] = 'a';
//	str2.at(3) = 'b';
//}


//void test()
//{
//	/*default (1)
//		string();*/
//	//�����յ�string����
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
//	string str5 = "abcde";//���ι������ʽ����ת��
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