#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef int(*ptr)(int);
void test()
{
	//lambda����ʽ��[��׽�б�] (�����б�) (mutable��ѡ)->����ֵ���� {������}
	//��׽�б�����׽���������еı���
	int a = 10;
	int b = 20;
	[a, b] {return a + b; };
	//�����б��������ں����Ĳ����б�
	[a, b](int c, int d, int e) {return a + b + c; };
	//����ֵ�������ں����ķ���ֵ
	[a, b](int c)->int {return a + b + c; };
	//�����壺�����ں����ĺ����壺�����ж��ָ��
	//mutable���޸Ĳ�׽�б��б���������Ϊ��const��Ĭ��Ϊconst����
	//[a, b] (int c)->{a = 10; }; //a,b������Ĭ��Ϊconst
	[a, b](int c) mutable->int {a = 10; b = 200; };
	//�����б��ͷ���ֵ����ʡ��
	[] {};
	//����ֵ����һ�㲻��д�����������Զ��Ƶ�
	[a, b] {return a + b; };
	//�����mutable, ��ʹ�����б�Ϊ�գ�Ҳ��Ҫ��ʾд����
	[a, b]()mutable {return a + b; };

	auto f = [a, b](int c) {return a + b + c; };
	//���϶�Ϊ���壬�����ָ���������
	int e = f(10);
	cout << e << endl;
	//[=]: ��ֵ����ʽ��׽���������е����б���
	auto f2 = [=]() {return a + b + e; };
	//[&]: �����õ���ʽ��׽���������е����б���
	auto f3 = [&]() {a = 1; b = 1000; };
	f3();
	//[=, &����x]: x�����õ���ʽ��׽��������ֵ����ʽ��׽
	//[&, ����x]: x��ֵ����ʽ��׽����������������ʽ��׽
	//����Ĳ�׽��ʽ: [=, ����x]��[&, &����x]
	auto f4 = [&, a]() {return a + b; };
	auto f5 = [=, &a, &e]() {return a + b + e; };
	//[this]: ��׽��Ա�����е�thisָ��

	//lambda����ʽ֮�䲻���໥��ֵ
	auto f = [](int a) {return a; };
	auto f2 = [](int a) {return a; };
	//f = f2;
	//��������
	auto f3(f);
	ptr f4 = f;
	f4();
}

struct A
{
	void fun(int a)
	{
		auto f = [this]() {return this->_a; };
	}
	int _a;
};

//�ڿ������������lambda������׽�б�����Ϊ��
int g = 10;
auto f = [] {};

//struct A
//{
//public:
//	A(int age = 1, int id = 1, string name = "")
//		:_age(age)
//		, _id(id)
//		, _name(name)
//	{}
//
//	bool operator<(const A& a)
//	{
//		return _age < a._age;
//	}
//
//	int _age;
//	int _id;
//	string _name;
//};
//
//struct Less
//{
//	bool operator()(const A& a, const A& b)
//	{
//		return a._id > b._id;
//	}
//};
//
//void test()
//{
//	vector<A> vec = { {18,1,"a"},{29,3,"b"},{13,25,"c"} };
//	sort(vec.begin(), vec.end());
//	sort(vec.begin(), vec.end(), Less());
//	sort(vec.begin(), vec.end(),
//		[](const A& a, const A& b)
//		{ return a._name > b._name; });
//}

//void test()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//
//	// Ĭ�ϰ���С�ڱȽϣ��ų������������
//	sort(array, array + sizeof(array) / sizeof(array[0]));
//
//	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
//	sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//}

//void Fun(int& x) { cout << "lvalue ref" << endl; }
//void Fun(int&& x) { cout << "rvalue ref" << endl; }
//void Fun(const int& x) { cout << "const lvalue ref" << endl; }
//void Fun(const int&& x) { cout << "const rvalue ref" << endl; }
////T&&��δ����������
////��������&&����ֵ����
//template<typename T>
//void PerfectForward(T&& t) { Fun(std::forward<T>(t)); }
////void PerfectForward(const T& t) { Fun(t); }
//
//void test()
//{
//	PerfectForward(10); // rvalue ref
//	int a;
//	PerfectForward(a); // lvalue ref
//	PerfectForward(move(a)); // rvalue ref
//	const int b = 8;
//	PerfectForward(b); // const lvalue ref
//	PerfectForward(move(b)); // const rvalue ref
//}

int main()
{
	test();
	system("pause");
	return 0;
}