#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue
{
public:
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		//调整
		while (child > 0)
		{
			if (v[parent] < v[child])
			{
				swap(v[parent], v[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < v.size())
		{
			//从左右孩子中找到最大值
			if (child + 1 < v.size() && v[child] < v[child + 1])
				++child;
			if (v[parent] < v[child])
			{
				swap(v[parent], v[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	void push(const T& val)
	{
		v.push_back(val);
		shiftUp(v.size() - 1);
	}

	void pop()
	{
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		shiftDown();
	}

	T& top()
	{
		return v[0];
		//return v.front();
	}

	size_t size() const
	{
		return v.size();
	}

	bool empty() const
	{
		return v.empty();
	}

private:
	vector<T> v;
};

void test()
{
	PriorityQueue<int> pq;
	pq.push(9);
	pq.push(5);
	pq.push(2);
	pq.push(7);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main1()
{
	test();
	system("pause");
	return 0;
}