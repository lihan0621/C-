#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//namespace + �����ռ����� { ���������� }
namespace N1
{
	int a = 0;
	void fun1()
	{
		printf("N1��fun1()\n");//�����ռ��µ�fun1����
	}
	//�����ռ����Ƕ��
	namespace N2
	{
		int a = 1;
		void fun1()
		{
			//Ƕ���µ�fun1����
			printf("N1:N2:fun1()\n");
		}
	}
}
//�����ռ䲻������Ƕ�׶��壬�����Էֶζ���
namespace N1
{
	//��������ռ�������������ռ�����ͬһ��������
	//int a;//����ı����ͻ���һ���ض���
	int b = 20;
	void fun2()
	{
		printf("N1:fun2\n");
	}
}
//ȫ���������µı����뺯�����������ռ��еĲ�����ͻ
int a = 10;
void fun1()
{
	printf("fun1()\n");//ȫ���������µ�fun1����
}

//void test()
//{
//	//�����ӡ����ȫ�ֵ�a
//	printf("a: %d\n", a);
//	//�����ռ��г�Ա�ķ�����ʽ
//	//1. �����ռ� + ::(�������޶���) + ��Ա
//	printf("N1::a = %d\n", N1::a);
//	//2. using �����ռ�::��Ա
//	using N1::b;
//	printf("N1::b = %d\n", b);
//	//3. չ�������ռ䣺using namespace �����ռ�
//	using namespace N1;
//	//�������д��N1�����ռ��µ����г�Ա���ܿ���
//	//printf("N1::a = %d\n", a);
//	//�����a�ǲ���ȷ�ģ�������չ�������ռ�֮��
//	//�����ռ��еı�������ȫ���еı���������ͻ
//	fun2();
//}

using namespace std;
void fun2(int a)
{
	cout << a << endl;
}

void fun3(int a = 10)
{
	cout << a << endl;
}

//ȫȱʡ�����в�������Ĭ��ֵ
void fun4(int a = 1, int b = 2, int c = 3, int d = 4, int e = 5)
{
	cout << a <<" " << b <<" " << c << " " << d << " " << e << endl;
}

//��ȱʡ�����ֲ�������Ĭ��ֵ
//����Ĭ��ֵ�����������������ֵ���м䲻���м��
void fun5(int a, int b = 1, int c = 2)
{
	cout << a << " " << b << " " << c << endl;
}
//������Щ����ǲ��������
//void fun6(int a = 1, int b, int c = 2);
//void fun7(int a, int b = 1, int c, int d = 2);
//void fun8(int a = 1, int b = 2, int c);
//��������
void fun6(int a = 10);
//��������
void fun6(int a = 20)
{
	cout << a << endl;
	//�������Ҳ�ǲ�������ģ��ض���Ĭ�ϲ��� 
}

char add(char a, char b)
{
	return a + b;
}

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

void test()
{
	//fun2(); �������������������ǵ��ò��˵�
	fun2(100);
	fun3();//����������ǿ��Ե��õģ���Ȼû�и�ֵ���������б���ֵ
	fun3(50);//��Ȼ���������һ��ֵ�Ļ����Ͳ����ñ���ֵ��
	fun4();
	fun4(10, 20, 30);
	//���ȫ����ֵ�Ļ�����������������ν���
	fun4(10, 20, 30, 40, 50);
}

//void test()
//{
//	int a;
//	//C++ͷ�ļ��ж�������г�Ա������std�����ռ�
//	cin >> a;
//	cout << a; 
//	std::cin >> a;
//	std::cout << a; 
//}

int main()
{
	test();
	system("pause");
	return 0;
}