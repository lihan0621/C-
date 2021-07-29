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

//���ⶨ�庯������Ҫ�ӷ�������
template<class T>
T seqListAt(size_t pos)
{
	return _data[pos];
}

void test()
{
	//����д��
	//seqList sq;
	//��ģ��ʵ����֮������������---> ����<ģ���������>
	seqList<int> sq(10);
	seqList<double> sq2(10);
}

//template<class T1, class T2, class T3>
//void print(const T1& a, const T2& b, const T3& c)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
////�ͺ���ģ���Ӧ����ͨ����
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
//	//ƥ�����
//	//1.����ƥ����ͨ����
//	//2.�������ģ�����ʵ����һ������ƥ��ĺ���������ʵ����
//	//3.���ָ����Ҫ����ʵ��������ֱ��ʵ����
//	print(a, b, c);
//	print(a, b, e);
//	print(a, b, e);
//	//��ʾʵ����
//	print<int, int, double>(a, b, e);
//}

//struct A
//{
//	A(int a)
//		:_a(a)
//	{}
//	int _a;
//};
////����ģ��
////T: ģ�����
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
