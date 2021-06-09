#include<iostream>
using namespace std;
template<class T>
class Vector
{
public:
	//����������T*
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endofStorage(nullptr)
	{}
	Vector(size_t n, const T& val = T())
		:_start(new T[n])
		,_finish(_start + n)
		,_endofStorage(_start + n)
	{
		for (size_t i = 0; i < n; ++i)
			_start[i] = val;
	}
	template<class inputIterator>
	Vector(inputIterator first, inputIterator last)
		:_start(nullptr)
		,_finish(nullptr)
		,_endofStorage(nullptr)
	{
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}
	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endofStorage)
		{
			//����
			size_t newC = _endofStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//����
		*_finish = val;
		//����
		++_finish;
	}
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//����ԭʼ��size
			size_t sz = size();
			//���ռ�
			T* arr = new T[n];
			//��������
			if (_start)
			{
				//�Զ������ͣ�ǳ�������������Դ�������Դ������ͷ�
				//memcpy(arr, _start, sizeof(T) * sz);
				//���
				for (size_t i = 0; i < sz; ++i)
				{
					//������Զ������ͣ����ø�ֵ��������غ���
					//ֻҪ��ֵ�����ʵ����������˴���Ϊ���
					arr[i] = _start[i];
				}
				delete[]_start;
			}
			//����
			_start = arr;
			_finish = _start + sz;
			_endofStorage = _start + n;
		}
	}
	void resize(size_t n, const T& val = T())
	{
		if (n > capacity())
		{
			reserve(n);
		}
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		_finish = _start + n;
	}
	void insert(iterator pos, const T& val)
	{
		if (pos >= _start && pos <= _finish)
		{
			if (_finish == _endofStorage)
			{
				//����Ԫ�صĸ���
				size_t num = pos - _start;
				//���ݻᵼ�µ�����ʧЧ
				size_t n = _endofStorage == nullptr ? 1 : 2 * capacity();
				reserve(n);
				//���µ�����
				pos = _start + num;
			}
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
		}
	}
	void earse(iterator pos)
	{
		//���λ��
		if (pos < _finish && pos >= _start)
		{
			//�ƶ�Ԫ�أ���ǰ����ƶ�
			iterator start = pos + 1;
			while (start != _finish)
			{ 
				*(start - 1) = start;
				++start;
			}
			--_finish;
		}
	}
	void popBack()
	{
		earse(end() - 1);
	}
	size_t size()const
	{
		return _finish - _start;
	}
	size_t capacity()const
	{
		return _endofStorage - _start;
	}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator begin() const
	{
		return _start;
	}
	const_iterator end() const
	{
		return _finish;
	}
	~Vector()
	{
		if (_start)
		{
			delete[]_start;
			_start = _finish = _endofStorage = nullptr;
		}
	}
	T& operator[](size_t pos)
	{
		if (pos >= 0 && pos < size())
		{
			return _start[pos];
		}
	}
	const T& operator[](size_t pos)const
	{
		if (pos >= 0 && pos < size())
		{
			return _start[pos];
		}
	}
	Vector(const Vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endofStorage(nullptr)
	{
		size_t n = v.capacity();
		_start = new T[n];
		for (size_t i = 0; i < v.size(); ++i)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.size();
		_endofStorage = _start + n;
	}
	/*Vector<T>& operator=(const Vector<T>& v)
	{
		if (this != &v)
		{
			delete[]_start;
			size_t n = v.capacity();
			_start = new T[n];
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_endofStorage = _start + n;
		}
		return *this;
	}*/
	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofStorage, v._endofStorage);
	}
private:
	iterator _start;
	iterator _finish;
	iterator _endofStorage;
};
template<class T>
ostream operator<<(ostream out, const Vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		out << v[i] << " ";
	}
	out << endl;
	return out;
}
struct A
{
	int _a = 10;
};
template<class T>
void printVector(const Vector<T>& vec)
{
	typename Vector<T>::const_iterator cit = vec.begin();
	while (cit != vec.end())
	{
		cout << *cit << " ";
		//*cit = T();
		++cit;
	}
	cout << endl;
}
template<class T>
void printForVector(const Vector<T>& vec)
{
	for (auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test()
{
	int arr[] = { 1,2,3,4 };
	Vector<int>v(arr, arr + 4);
	Vector<int>copy(v);
	int arr2[] = { 5,6,7,8 };
	Vector<int>v2(arr2, arr2 + 4);
	v2 = v;
}
//void test()
//{
//	Vector<int>v;
//	v.insert(v.begin(), 1);
//	printForVector(v);
//	v.insert(v.end(), 2);
//	printForVector(v);
//}
//void test()
//{
//	Vector<int>v1;
//	Vector<int*>v2;
//	Vector<A>v3;
//	cout << v1.size() << endl;
//	cout << v2.size() << endl;
//	cout << v3.size() << endl;
//	cout << v1.capacity() << endl;
//	cout << v2.capacity() << endl;
//	cout << v3.capacity() << endl;
//	Vector<int>v4(5);
//	Vector<int*>v5(5);
//	Vector<A>v6(5);
//	cout << v4.size() << endl;
//	cout << v5.size() << endl;
//	cout << v6.size() << endl;
//	cout << v4.capacity() << endl;
//	cout << v5.capacity() << endl;
//	cout << v6.capacity() << endl;
//	Vector<int>::iterator it = v4.begin();
//	while (it != v4.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	printVector(v4);
//	printForVector(v4);
//}
int main()
{
	test();
	return 0;
}