#include <iostream>
#include <queue>
using namespace std;

struct A
{
	A(int a)
		:_a(a)
	{}
	int _a;

	//自定义类型需要写出比较运算符的重载函数
	bool operator<(const A& a) const
	{
		return _a < a._a;
	}
};

void test()
{
	priority_queue<A> q;
	q.push(A(1));
	q.push(A(2));
	q.push(A(534));
	q.push(A(653));
	q.push(A(95));

	while (!q.empty())
	{
		cout << q.top()._a << " ";
		q.pop();
	}
	cout << endl;

}

//void test()
//{
//	//默认是大堆结构
//	priority_queue<int> q;
//	q.push(100);
//	q.push(1);
//	q.push(150);
//	q.push(10);
//	q.push(20);
//
//	while (!q.empty())
//	{
//		cout << q.top() << " ";
//		q.pop();
//	}
//	cout << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}