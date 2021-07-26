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
	int* p = NULL;//预处理，宏替换：int* p = 0;
	int* p2 = 0;//这两个没有区别
	fun(NULL);
	fun((int*)NULL);
	fun(nullptr);
}

//void test()
//{
//	//之前我们写的for循环
//	int arr[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	//范围for： 当前的数据 : 循环的范围
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
//	//auto: 自动类型推导
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
//	//实际编译时：int a = 10 + 20
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
////引用作返回值，返回值的生命周期需要大于函数的生命周期
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
//	//常引用：引用指向的实体不能修改
//	//const 类型&
//	const int a = 10;
//	//这种写法是不允许的
//	//int& ra = a;
//	//这里必须加上const修饰
//	const int& ra = a;
//	const int& ra2 = 100;
//	double d = 2.5;
//	int c = 10;
//	c = d;
//	const int& ra3 = d;
//}

//void test()
//{
//	//这样写是不对的，引用定义必须初始化
//	//int& ra;
//	int a = 10;
//	int& ra = a;
//	int& ra1 = a;
//	int& ra2 = a;
//	//以下四种方法都可以改变a的内容
//	a = 5;
//	ra = 4;
//	ra1 = 3;
//	ra2 = 2;
//
//	int b = 100;
//	//这里不是一个重新修改指向的操作，这里是一个赋值的操作
//	//此时a的内容就变成了100
//	ra1 = b;
//}

//void test()
//{
//	int a = 10;
//	//ra是一个引用：是a的别名，指向和a相同的实体
//	int& ra = a;
//	A sa;
//	sa.a = 1;
//	sa.b = 1;
//	sa.c = 1;
//	sa.d = 1;
//	sa.e = 1;
//	//rsa和sa指向共同的实体，rsa的内容发生改变，sa的内容也会发生改变
//	//这里不是一个拷贝，不分配新的空间
//	A& rsa = sa;
//	//这才是一个拷贝：分配新的空间
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