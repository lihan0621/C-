#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
	//���������ͣ� T*
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}
	Vector(size_t n, const T& val = T())
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			_start[i] = val;
		}
	}

	template<class inputIterator>
	Vector(inputIterator first, inputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		//[first, last)
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endOfStorage)
		{
			//����
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//����
		*_finish = val;
		//����
		++_finish;
	}

	void reverse(size_t n)
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
				//�Զ������ͣ�ǳ������ �������Դ���������Դ������ͷ�
				//memcpy(arr, _start, sizeof(T) * sz);
				//���
				for (size_t i = 0; i < sz; ++i)
				{
					//������Զ������ͣ����ø�ֵ��������غ���
					//ֻҪ��ֵ�����ʵ����������˴���Ϊ���
					arr[i] = _start[i];
				}
				delete[] _start;
			}
			//����
			_start = arr;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	void resize(size_t n, const T& val = T())
	{
		// n > capacity: ����
		if (n > capacity())
		{
			reverse(n);
		}
		//size < n <= capacity : [size, n - 1]���val
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size ֻ�޸�size
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		//���λ��
		if (pos >= _start && pos <= _finish)
		{
			//�������
			if (_finish == _endOfStorage)
			{
				//����Ԫ�ظ���
				size_t num = pos - _start;
				//���ݻᵼ�µ�����ʧЧ
				size_t n = _endOfStorage == nullptr ? 1 : 2 * capacity();
				reverse(n);
				//���µ�����
				pos = _start + num;
			}
			//�ƶ�Ԫ�أ��Ӻ���ǰ�ƶ�
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				--end;
			}
			//����
			*pos = val;
			//����
			++_finish;
		}
	}

	iterator test(iterator pos)
	{
		//���λ��
		if (pos < _finish && pos >= _start)
		{
			//�ƶ�Ԫ�أ���ǰ����ƶ�
			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			//����
			--_finish;
		}
		return pos;
	}

	void popBack()
	{
		erase(end() - 1);
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endOfStorage - _start;
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
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

	T& operator[](size_t pos)
	{
		if (pos >= 0 && pos < size())
			return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		if (pos >= 0 && pos < size())
			return _start[pos];
	}

	Vector(const Vector<T>& v)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		size_t n = v.capacity();
		_start = new T[n];
		for (size_t i = 0; i < v.size(); ++i)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.size();
		_endOfStorage = _start + n;
	}

	Vector<T>& operator=(const Vector<T>& v)
	{
		if (this != &v)
		{
			delete[] _start;
			size_t n = v.capacity();
			_start = new T[n];
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_endOfStorage = _start + n;
		}
		return *this;
	}

	//��ֵ������ִ�д��
	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStorage, v._endOfStorage);
	}

private:
	iterator _start;
	iterator _finish;
	iterator _endOfStorage;
};

template<class T>
ostream& operator<<(ostream& out, const Vector<T>& v)
{
	for (const auto& e : v)
	{
		out << e << " ";
	}
	out << endl;
	return out;
}

template<class T>
void printVector(const Vector<T>& vec)
{
	typename Vector<T>::const_iterator cit = vec.begin();
	while (cit != vec.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

template<class T>
void printForVector(const Vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test()
{
	Vector<int> v1;
	Vector<char> v2;
	cout << v1.size() << endl;
	cout << v2.size() << endl;
	cout << v1.capacity() << endl;
	cout << v2.capacity() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}