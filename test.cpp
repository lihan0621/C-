#include <iostream>
#include <vector>
using namespace std;

void test()
{
	vector<int> v(3, 10);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	v.push_back(4);
	//���ݣ� resize, reserve, push_back, insert, emplace, emplace_back
	//������ʧЧ�� ������ָ���λ���ǷǷ�λ�ã� �ռ��Ѿ��ͷ�
 	//cout << *it << endl;

	it = v.begin();
	cout << *it << endl;
	//������ʧЧ�� ������ָ���λ�÷����˱仯		
	v.erase(it);
	cout << *it << endl;
}

//struct A
//{
//public:
//	explicit A(int a, int b)
//		:_a(a)
//		,_b(b)
//	{}
//private:
//	int _a;
//	int _b;
//};
//void test()
//{
//	vector<A> v;
//	A a1(1, 1);
//	v.push_back(a1);
//	//v.push_back(2);
//	//ֻ��Ҫ�����캯����Ҫ�Ĳ������ӿ��ڲ�ֱ�Ӵ�������
//	v.emplace_back(2, 3);
//	v.emplace_back(a1);
//}

//void test()
//{
//	string str("123");
//	vector<char> v(str.begin(), str.end());
//	v.assign(5, 'a');
//	string ptr("abcde");
//	v.assign(ptr.begin(), ptr.end());
//
//	v.insert(v.begin(), '0');
//	v.insert(--v.end(), 5, 'a');
//	v.insert(++v.begin(), ptr.begin(), ptr.end());
//
//	v.erase(v.begin());
//	v.erase(++v.begin(), --v.end());
//}

//void test()
//{
//	string str = "123456";
//	vector<char> v(str.begin(), str.end());
//	for (int i = 0; i < v.size(); ++i)
//	{
//		cout << v.operator[](i) << " ";
//		v.operator[](i) = i + 'a';
//		cout << v[i] << " ";
//		v[i] = i + 'q';
//	}
//	cout << endl;
//}

//struct A
//{
//	int _a;
//	char _c;
//	double _d;
//	int* ptr;
//};
//
//void test()
//{
//	vector<int> v1;
//	vector<char> v2;
//	vector<int*> v3;
//	vector<double> v4;
//	vector<A> v5;
//	cout << v1.max_size() << endl;
//	cout << v2.max_size() << endl;
//	cout << v3.max_size() << endl;
//	cout << v4.max_size() << endl;
//	cout << v5.max_size() << endl;
//}

//void Swap(int& a, int& b)
//{
//	a ^= b ^= a ^= b;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//}

//void test()
//{
//	string str("1234567890");
//	vector<char> v(str.begin(), str.end());
//	//vector<char>::iterator it = v.begin();
//	//int idx = 0;
//	//while (it != v.end())
//	//{
//	//	cout << *it << " ";
//	//	*it = idx + 'a';
//	//	++idx;
//	//	++it;
//	//}
//	//cout << endl;
//	vector<char>::const_iterator it = v.cbegin();
//	int idx = 0;
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		//*it = idx + 'a';
//		++idx;
//		++it;
//	}
//	cout << endl;
//	vector<char>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}

//struct A
//{
//	A(int a = 1, int b = 2)
//		:_a(a)
//		,_b(b)
//	{}
//	int _a = 1;
//	int _b = 2;
//};
//
//void test()
//{
//	//��vector�������޲ι���
//	vector<int> v1;
//	vector<char> v2;
//	vector<A> v3;
//
//	//vector(n, value)
//	//�������ͣ� ȱʡ��ֵΪ��0ֵ
//	//int: 0; float/double: 0.0; char: \0; ָ�룺 nullptr
//	vector<int> v4(5);
//	vector<char> v5(5);
//	vector<int*> v6(5);
//	vector<float> v7(5);
//
//	//�Զ������ͣ� ȱʡֵΪĬ�Ϲ��촴���Ķ���
//	vector<A> v8(5);
//	//vector<�Զ�������> ������(num, ���캯��(����))
//	vector<A> v9(5, A(10, 20));
//
//	//template <class InputIterator>
//	//vector(InputIterator first, InputIterator last,
//	//	const allocator_type & alloc = allocator_type());
//	int arr[] = { 1,2,3,4,5 };
//	vector<int> v10(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	char arr2[] = { 1,2,3,4,5 };
//	vector<char> v11(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
//	string str("1234567890");
//	vector<char> v12(str.begin(), str.end());
//}



int main()
{
	test();
	system("pause");
	return 0;
}