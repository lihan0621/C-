#include <iostream>
#include <unordered_map>
using namespace std;



void test()
{
	unordered_map<int, int> m;
	//�����������map���ߣ� O(1)
	m.insert(make_pair(1, 1));
	m[2] = 2;

	for (int i = 3; i < 100; ++i)
	{
		m[i] = i;
	}

	//�����map/set, unordered_map/setֻ�����������
	//������������ ���������
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