#include <iostream>
#include <unordered_map>
using namespace std;



void test()
{
	unordered_map<int, int> m;
	//操作性能相比map更高： O(1)
	m.insert(make_pair(1, 1));
	m[2] = 2;

	for (int i = 3; i < 100; ++i)
	{
		m[i] = i;
	}

	//相对于map/set, unordered_map/set只有正向迭代器
	//迭代器遍历， 不是有序的
	unordered_map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;

	cout << "m.equal_range" << endl;
	auto range = m.equal_range(3);
	it = range.first;
	while (it != range.second)
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}