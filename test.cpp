#include <iostream>
#include <set>
#include <map>
using namespace std;

template <class T1, class T2>
void printMap(const map<T1, T2>& m)
{
	//map�е�������pair
	//���������ʵ�˳�򣺰���key�����������˳��
	map<int, int>::const_iterator it = m.begin();
	while (it != m.end())
	{
		//����ֱ�����pair����
		//cout << *it << endl;
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
}

template <class T1, class T2>
void printMap2(const map<T1, T2>& m)
{
	//map�е�������pair
	//���������ʵ�˳�򣺰���key�����������˳��
	map<int, int>::const_reverse_iterator it = m.rbegin();
	while (it != m.rend())
	{
		//����ֱ�����pair����
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
	//map��key�����ظ���val�����ظ�
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
//	//set�в�����ظ������ݣ���Ȼȥ�أ�����s2��ֻ�����4��Ԫ��
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set������������������Ȼ���򣺱��ʵ����������������
//	//set<int>::iterator it = s2.begin();
//	//while (it != s2.end())
//	//{
//	//	cout << *it << " ";
//	//	//set��������֧���޸�
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
//	//insert: ����ʧ�ܣ��������ݵ�������false
//	pair<set<int>::iterator, bool> ret = s2.insert(2);
//	cout << ret.second << " " << *ret.first << endl;
//	//insert: ����ɹ��������ݵ�������true
//	ret = s2.insert(20);
//	cout << ret.second << " " << *ret.first << endl;
//	printSet(s2);
//	//iterator insert(iterator position, const value_type & val);
//	//insert(iterator, val): iteratorֻ��һ��λ�ý��飬�������ݵ�λ�ò�һ����ָ��������֮ǰ
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
//	//erase: ���ܴ��Ƿ�λ�ã�����end;
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