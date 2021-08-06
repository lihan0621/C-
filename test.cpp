#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template<class T>
void printList(list<T>& lst)
{
	typename list<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void printReverseList(list<T>& lst)
{
	typename list<T>::reverse_iterator it = lst.rbegin();
	while (it != lst.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


template<class T>
void printReverseList2(list<T>& lst)
{
	cout << "反向迭代器的正向输出" << endl;
	typename list<T>::reverse_iterator it = lst.rend();
	--it;
	while (it != lst.rbegin())
	{
		cout << *it << " ";
		++it;
	}
	cout << *it << endl;
}

template<class T>
void printForList(list<T>& lst)
{
	for (auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test()
{
	int arr[] = { 9,5,2,7 };
	int arr2[] = { 7,5,2,9 };
	list<int> lst(arr, arr + 4);
	list<int> lst2(arr2, arr2 + 4);
	lst.sort();
	lst2.sort();
	lst.merge(lst2);
	printForList(lst);
}

//void test()
//{
//	string str = "12344321";
//	list<char> lst(str.begin(), str.end());
//	printForList(lst);
//	//unique: 在数据有序的情况下，进行元素的去重
//	lst.unique();
//	printForList(lst);
//	lst.sort();
//	printForList(lst);
//	lst.unique();
//	printForList(lst);
//}

//void test()
//{
//	string s = "1234";
//	string s2 = "abc";
//	list<char> lst(s.begin(), s.end());
//	list<char> lst2(s2.begin(), s2.end());
//	//lst.splice(lst.begin(), lst2);
//	//lst.splice(lst.begin(), lst2, ++lst2.begin());
//	lst.splice(lst.begin(), lst2, ++lst2.begin(), lst2.end());
//	printList(lst);
//	printList(lst2);
//
//	lst.remove('f');
//	printList(lst);
//}

//void test()
//{
//	list<int> lst;
//	lst.push_front(1);
//	lst.push_back(2);
//
//	lst.insert(lst.begin(), 0);
//	list<int>::iterator it = lst.begin();
//	cout << *it << endl;
//
//	lst.insert(lst.end(), 3);
//	lst.emplace(lst.begin(), -1);
//	lst.emplace_back(4);
//	lst.emplace_front(-2);
//
//	list<int> copy = lst;
//	lst.insert(lst.end(), copy.begin(), copy.end());
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//插入不会导致迭代器失效
//	cout << *it << endl;
//
//	//删除导致迭代器失效
//	//erase返回值：迭代器--->被删除元素的下一个元素的位置
//	it = lst.erase(it);
//	cout << *it << endl;
//
//	cout << lst.size() << endl;
//	//lst.clear();
//	//cout << lst.size() << endl;
//	lst.resize(5, 100);
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	lst.resize(7, 200);
//	for (const auto& e : lst)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//}

//void test()
//{
//	list<int> lst;
//	list<char> lst2(5, 'a');
//	string str = "1234567";
//	list<char> lst3(str.begin(), str.end());
//	list<char> copy(lst3);
//
//	vector<char> v(str.begin(), str.end());
//	list<char> lst4(v.begin(), v.end());
//
//	char arr[] = "abcd";
//	list<char> lst5(arr, arr + 4);
//}

int main()
{
	test();
	system("pause");
	return 0;
}