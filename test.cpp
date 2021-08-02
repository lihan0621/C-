#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
template <class T>
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
	size_t size()
	{
		return _q.size();
	}
	bool empty()
	{
		return _q.empty();
	}
	//用list实现
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
template <class t>
class stack
{
public:
	void push(const t& val)
	{
		_st.push_back(val);
	}
	void pop()
	{
		 _st.pop_back();
	}
	t& top()
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
	//用vector实现stack
private:
	vector<t> _st;
};
#include<list>
template<class t>
class Stack2
{
public:
	void push(const t& val)
	{
		_st.push_front(val);
		//_st.push_back(val);
	}
	void pop()
	{
		_st.pop_front();
		//_st.pop_back();
	}
	t& top()
	{
		return _st.front();
		//return _st.back();
	}
	size_t size() const
	{
		return _st.size();
	}
	bool empty() const
	{
		return _st.empty();
	}
private:
	list<t> _st;
};
//void test()
//{
//	//Stack<int> st;
//	Stack2 <int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	cout << endl;
//}
int main()
{
	test();
	return 0;
}