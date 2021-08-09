#include <iostream>
#include <list>
using namespace std;

template<class T>
class Queue
{
public:
	void push(const T& val)
	{
		_q.push_back(val);
		//_q.push_front(val);
	}

	void pop()
	{
		_q.pop_front();
		//_q.pop_back();
	}

	T& front()
	{
		return _q.front();
		//return _q.back();
	}

	size_t size() const
	{
		return _q.size();
	}

	bool empty()
	{
		return _q.empty();
	}

	//”√list µœ÷
private:
	list<T> _q;
};

void test()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}