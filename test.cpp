#include <stdlib.h>
#include <iostream>

using namespace std;

template<class T>
class seqList
{
public:
	seqList(int n)
		:_data(new T(n))
		,_size(0)
		,_capacity(n)
	{}
	T seqListAt(size_t pos);
private:
	//int* _data;
	T* _data;
	size_t _size;
	size_t _capacity;
};

//类外定义函数：需要加泛型声明
template<class T>
T seqListAt(size_t pos)
{
	return _data[pos];
}

void test()
{
	//错误写法
	//seqList sq;
	//类模板实例化之后，真正的类型---> 类名<模板参数类型>
	seqList<int> sq(10);
	seqList<double> sq2(10);
}

//template<class T1, class T2, class T3>
//void print(const T1& a, const T2& b, const T3& c)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
////和函数模板对应的普通函数
//void print(const int& a, const int& b, const double& c)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//void test()
//{
//	int a = 1, b = 2;
//	char c = 'm', d = 'n';
//	double e = 1.2, f = 2.4;
//
//	//匹配规则：
//	//1.优先匹配普通函数
//	//2.如果函数模板可以实例化一个更加匹配的函数，则走实例化
//	//3.如果指明需要进行实例化，则直接实例化
//	print(a, b, c);
//	print(a, b, e);
//	print(a, b, e);
//	//显示实例化
//	print<int, int, double>(a, b, e);
//}

//struct A
//{
//	A(int a)
//		:_a(a)
//	{}
//	int _a;
//};
////函数模板
////T: 模板参数
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void test()
//{
//	int a = 1, b = 2;
//	char c = 'm', d = 'n';
//	double e = 1.2, f = 2.4;
//	A a1(10);
//	A a2(20);
//	Swap(a, b);
//	Swap(c, d);
//	Swap(e, f);
//	Swap(a1, a2);
//}

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

int main()
{
	test();
	system("pause");
	return 0;
}
