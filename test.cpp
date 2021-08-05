#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
	//迭代器类型： T*
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
		//检查容量
		if (_finish == _endOfStorage)
		{
			//增容
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			reserve(newC);
		}
		//插入
		*_finish = val;
		//更新
		++_finish;
	}

	void reverse(size_t n)
	{
		if (n > capacity())
		{
			//保存原始的size
			size_t sz = size();
			//开空间
			T* arr = new T[n];
			//拷贝内容
			if (_start)
			{
				//自定义类型，浅拷贝： 如果有资源，会产生资源被多次释放
				//memcpy(arr, _start, sizeof(T) * sz);
				//深拷贝
				for (size_t i = 0; i < sz; ++i)
				{
					//如果是自定义类型，调用赋值运算符重载函数
					//只要赋值运算符实现了深拷贝，此处即为深拷贝
					arr[i] = _start[i];
				}
				delete[] _start;
			}
			//更新
			_start = arr;
			_finish = _start + sz;
			_endOfStorage = _start + n;
		}
	}

	void resize(size_t n, const T& val = T())
	{
		// n > capacity: 增容
		if (n > capacity())
		{
			reverse(n);
		}
		//size < n <= capacity : [size, n - 1]填充val
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
		//n <= size 只修改size
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		//检查位置
		if (pos >= _start && pos <= _finish)
		{
			//检查容量
			if (_finish == _endOfStorage)
			{
				//保存元素个数
				size_t num = pos - _start;
				//增容会导致迭代器失效
				size_t n = _endOfStorage == nullptr ? 1 : 2 * capacity();
				reverse(n);
				//更新迭代器
				pos = _start + num;
			}
			//移动元素：从后向前移动
			iterator end = _finish;
			while (end != pos)
			{
				*end = *(end - 1);
				--end;
			}
			//插入
			*pos = val;
			//更新
			++_finish;
		}
	}

	iterator test(iterator pos)
	{
		//检查位置
		if (pos < _finish && pos >= _start)
		{
			//移动元素：从前向后移动
			iterator start = pos + 1;
			while (start != _finish)
			{
				*(start - 1) = *start;
				++start;
			}
			//更新
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

	//赋值运算符现代写法
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