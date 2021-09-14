#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

struct A
{
public:
	A(int a = 10)
		:_a(a)
	{}

	A(int a, int b, int c)
		:_a(a)
	{}

	int _a;
};

template <class T>
class Vector
{
public:
	Vector(size_t n)
		:_arr(new T[n])
		, _size(0)
		, _capacity(n)
	{}

	Vector(const initializer_list<T>& lst)
		:_arr(new T(lst.size()))
		, _size(lst.size())
		, _capacity(_size)
	{
		int idx = 0;
		for (const auto& e : lst)
		{
			arr[idx++] = lst;
		}
	}

private:
	T* _arr;
	size_t _size;
	size_t _capacity;
};

void test()
{
	int a = 10;
	A a1(100);
	//���ι������ʽ����ת��
	A a2(200);
	int arr[] = { 1,2,3 };

	//C++11�У�֧���������ͣ��Զ������͵��б��ʼ��
	int b = { 10 };
	int c{ 100 };
	A a3 = { 1 };
	A a4{ 5 };
	A a5 = { 1,2,3 };
	A a6{ 1,2,3 };

	vector<int> v = { 1,2,3,4,5 };
	list<int> lst = { 1,2,3,4,5 };
	set<int> s = { 1,2,3,4,5 };
	map<int, int> m = { {1,1},{2,2},{3,3} };
	pair<int, int> p = { 1,2 };

	//�Զ���������࣬�����Ҫ�ó�ʼ���б���г�ʼ����
	//��Ҫ����һ�����캯��������Ϊinitializer_list
	Vector<int> v2 = { 1,2,3 };
	Vector<int> v3 = { 1 };
}

int main()
{
	test();
	system("pause");
	return 0;
}