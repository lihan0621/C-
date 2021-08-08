#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Stack
{
public:
	void push(const T& val)
	{
		_st.push_back(val);
	}

	void pop()
	{
		_st.pop_back();
	}

	T& top()
	{
		return _st.back();
	}

	size_t size() const
	{
		return _st.size();
	}

	bool empty() const 
	{
		return _st.empty();
	}

	//”√ vector µœ÷stack
private:
	vector<T> _st;
};

#include <list>
template<class T>
class Stack2
{
public:

	void push(const T& val)
	{
		_st.push_front(val);
		//_st.push_back(val);
	}

	void pop()
	{
		_st.pop_front();
		//_st.pop_back();
	}

	T& top()
	{
		return _st.front();
		return _st.back();
	}

	size_t size() const
	{
		return _st.size;
	}

	bool empty() const
	{ 
		return _st.empty();
	}

private:
	list<T> _st;
};

void test()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}
