#include <iostream>
#include <stdlib.h>

using namespace std;

void fun(int a)
{
	cout << "fun(int)" << endl;
}

void fun(int* a)
{
	cout << "fun(int*)" << endl;
}

void test()
{
	int* p = NULL;//Ԥ�������滻��int* p = 0;
	int* p2 = 0;//������û������
	fun(NULL);
	fun((int*)NULL);
	fun(nullptr);
}

//void test()
//{
//	//֮ǰ����д��forѭ��
//	int arr[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	//��Χfor�� ��ǰ������ : ѭ���ķ�Χ
//	for (int& e : arr)
//	{
//		cout << e << " ";
//		e = 10;
//	}
//	cout << endl;
//	for (int& e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test()
//{
//	//auto: �Զ������Ƶ�
//	auto a = 10;
//	auto b = 2.0;
//	auto c = 'a';
//	auto d = 'a' + b;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//}

//inline int add(int a, int b)
//{
//	return a + b;
//}
//
//void test()
//{
//	//ʵ�ʱ���ʱ��int a = 10 + 20
//	int a = add(10, 20);
//}

//void test()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 100;
//	int a1 = 10;
//	int* ra1 = &a1;
//	*ra1 = 100;
//}

//struct A
//{
//	int a;
//	int b;
//	int c;
//	int d;
//	int e;
//};
//
////����������ֵ������ֵ������������Ҫ���ں�������������
//int& add(int& a, int& b)
//{
//	int c = a + b;
//	return c;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int& ra = add(a, b);
//	add(a, b);
//	cout << a << b << endl;
//	cout << ra << endl;
//}

//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//}

//void test()
//{
//	//�����ã�����ָ���ʵ�岻���޸�
//	//const ����&
//	const int a = 10;
//	//����д���ǲ������
//	//int& ra = a;
//	//����������const����
//	const int& ra = a;
//	const int& ra2 = 100;
//	double d = 2.5;
//	int c = 10;
//	c = d;
//	const int& ra3 = d;
//}

//void test()
//{
//	//����д�ǲ��Եģ����ö�������ʼ��
//	//int& ra;
//	int a = 10;
//	int& ra = a;
//	int& ra1 = a;
//	int& ra2 = a;
//	//�������ַ��������Ըı�a������
//	a = 5;
//	ra = 4;
//	ra1 = 3;
//	ra2 = 2;
//
//	int b = 100;
//	//���ﲻ��һ�������޸�ָ��Ĳ�����������һ����ֵ�Ĳ���
//	//��ʱa�����ݾͱ����100
//	ra1 = b;
//}

//void test()
//{
//	int a = 10;
//	//ra��һ�����ã���a�ı�����ָ���a��ͬ��ʵ��
//	int& ra = a;
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//	sa.e = 1;
//	//rsa��saָ��ͬ��ʵ�壬rsa�����ݷ����ı䣬sa������Ҳ�ᷢ���ı�
//	//���ﲻ��һ���������������µĿռ�
//	A& rsa = sa;
//	//�����һ�������������µĿռ�
//	A copy = sa;
//	copy.a = 100;
//	rsa.a = 5;
//}

int main()
{
	test();
	system("pause");
	return 0;
}