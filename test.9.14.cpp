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
	//单参构造的隐式类型转换
	A a2(200);
	int arr[] = { 1,2,3 };

	//C++11中，支持内置类型，自定义类型的列表初始化
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

	//自定义的容器类，如果需要用初始化列表进行初始化，
	//需要定义一个构造函数，参数为initializer_list
	Vector<int> v2 = { 1,2,3 };
	Vector<int> v3 = { 1 };
}

int main()
{
	test();
	system("pause");
	return 0;
}