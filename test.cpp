#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//namespace + 命名空间名称 { 变量，函数 }
namespace N1
{
	int a = 0;
	void fun1()
	{
		printf("N1：fun1()\n");//命名空间下的fun1函数
	}
	//命名空间可以嵌套
	namespace N2
	{
		int a = 1;
		void fun1()
		{
			//嵌套下的fun1函数
			printf("N1:N2:fun1()\n");
		}
	}
}
//命名空间不仅可以嵌套定义，还可以分段定义
namespace N1
{
	//这个命名空间与上面的命名空间属于同一个作用域
	//int a;//这里的变量就会是一个重定义
	int b = 20;
	void fun2()
	{
		printf("N1:fun2\n");
	}
}
//全局作用域下的变量与函数，与命名空间中的并不冲突
int a = 10;
void fun1()
{
	printf("fun1()\n");//全局作用域下的fun1函数
}

//void test()
//{
//	//这里打印的是全局的a
//	printf("a: %d\n", a);
//	//命名空间中成员的访问形式
//	//1. 命名空间 + ::(作用域限定符) + 成员
//	printf("N1::a = %d\n", N1::a);
//	//2. using 命名空间::成员
//	using N1::b;
//	printf("N1::b = %d\n", b);
//	//3. 展开命名空间：using namespace 命名空间
//	using namespace N1;
//	//如果这样写，N1命名空间下的所有成员都能看到
//	//printf("N1::a = %d\n", a);
//	//这里的a是不明确的，当我们展开命名空间之后，
//	//命名空间中的变量会与全局中的变量产生冲突
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

//全缺省：所有参数都有默认值
void fun4(int a = 1, int b = 2, int c = 3, int d = 4, int e = 5)
{
	cout << a <<" " << b <<" " << c << " " << d << " " << e << endl;
}

//半缺省：部分参数设置默认值
//设置默认值必须从右向左连续赋值，中间不能有间隔
void fun5(int a, int b = 1, int c = 2)
{
	cout << a << " " << b << " " << c << endl;
}
//但是这些情况是不被允许的
//void fun6(int a = 1, int b, int c = 2);
//void fun7(int a, int b = 1, int c, int d = 2);
//void fun8(int a = 1, int b = 2, int c);
//函数声明
void fun6(int a = 10);
//函数定义
void fun6(int a = 20)
{
	cout << a << endl;
	//这种情况也是不被允许的，重定义默认参数 
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
	//fun2(); 这个函数如果不给参数是调用不了的
	fun2(100);
	fun3();//但这个函数是可以调用的，虽然没有给值，但是它有备用值
	fun3(50);//当然，如果传入一个值的话，就不会用备用值了
	fun4();
	fun4(10, 20, 30);
	//如果全部给值的话，参数会从左到右依次接收
	fun4(10, 20, 30, 40, 50);
}

//void test()
//{
//	int a;
//	//C++头文件中定义的所有成员都属于std命名空间
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