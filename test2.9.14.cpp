#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{}

	//default�ñ�������ʾ����һ��Ĭ�Ϲ��캯��
	A() = default;

	A(const A&) = default;

	A& operator=(const A&) = default;

};

class B
{
public:
	B()
	{}

	//��Ա�����������Ϊɾ����������ʾ�������ܱ�ʹ��
	//���������ѿ�������͸�ֵ����������ɾ������
	B(const B&) = delete;

	B& operator=(const B&) = delete;
};

void test()
{
	B b;

	//B copy(b);
	//b = copy;
}

//int fun(int a)
//{
//	return a;
//}
//
//void test()
//{
//	auto a = 10;
//	int b = 1;
//	int c = 2;
//	decltype(b + c) d;
//	cout << typeid(d).name() << endl;
//	cout << typeid(decltype(fun(a))).name() << endl;
//	cout << typeid(decltype(fun)).name() << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}