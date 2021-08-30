#include <iostream>
#include <set>
#include <map>
using namespace std;

template <class T1, class T2>
void printMap(const map<T1, T2>& m)
{
	//map中的数据是pair
	//迭代器访问的顺序：按照key的中序遍历的顺序
	map<int, int>::const_iterator it = m.begin();
	while (it != m.end())
	{
		//不能直接输出pair对象
		//cout << *it << endl;
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
}

template <class T1, class T2>
void printMap2(const map<T1, T2>& m)
{
	//map中的数据是pair
	//迭代器访问的顺序：按照key的中序遍历的顺序
	map<int, int>::const_reverse_iterator it = m.rbegin();
	while (it != m.rend())
	{
		//不能直接输出pair对象
		//cout << *it << endl;
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
}

void test()
{
	map<int, int> m;
	pair<int, int> arr[] = { pair<int, int>(5, 5), pair<int, int>(1,2),
		pair<int, int>(3,3),pair<int, int>(0,0),pair<int,int>(1,3) };
	//map中key不能重复，val可以重复
	map<int, int> m2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	printMap(m2);
	cout << "reverse_it" << endl;
	printMap2(m2);

	map<int, int, greater<int>> m3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& p : m3)
	{
		cout << p.first << "--->" << p.second << endl;
	}
}

//template <class T>
//void printSet(const set<T>& s)
//{
//	for (auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//void test()
//{
//	set<int> s;
//	int arr[] = { 1,2,3,4,4 };
//	//set中不存放重复的数据，天然去重，所以s2中只会存在4个元素
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set迭代器遍历，数据天然有序：本质迭代器进行中序遍历
//	//set<int>::iterator it = s2.begin();
//	//while (it != s2.end())
//	//{
//	//	cout << *it << " ";
//	//	//set迭代器不支持修改
//	//	//*it = 10;
//	//	++it;
//	//}
//	//cout << endl;
//
//	//cout << "reverse iterator:" << endl;
//	//set<int>::reverse_iterator rit = s2.rbegin();
//	//while (rit != s2.rend())
//	//{
//	//	cout << *rit << " ";
//	//	++rit;
//	//}
//	//cout << endl;
//
//	//insert: 插入失败：已有数据迭代器，false
//	pair<set<int>::iterator, bool> ret = s2.insert(2);
//	cout << ret.second << " " << *ret.first << endl;
//	//insert: 插入成功：新数据迭代器，true
//	ret = s2.insert(20);
//	cout << ret.second << " " << *ret.first << endl;
//	printSet(s2);
//	//iterator insert(iterator position, const value_type & val);
//	//insert(iterator, val): iterator只是一个位置建议，最终数据的位置不一定在指定迭代器之前
//	s2.insert(ret.first, 0);
//	printSet(s2);
//
//	int arr2[] = { 12,9,6,18,39,12,9,6 };
//	s2.insert(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
//	printSet(s2);
//
//	int num = s2.erase(39);
//	printSet(s2);
//	cout << num << endl;
//	num = s2.erase(399);
//	cout << num << endl;
//	s2.erase(s2.begin());
//	//erase: 不能传非法位置：比如end;
//	//s2.erase(s2.end());
//	printSet(s2);
//	s2.erase(++s2.begin(), --s2.end());
//	printSet(s2);
//}

int main()
{
	test();
	system("pause");
	return 0;
}