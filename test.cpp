#define  _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

class String
{
public:

	//String迭代器
	//实现：字符指针
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		//第一个元素的位置
		return _data;
	}

	const_iterator begin() const
	{
		//第一个元素的位置
		return _data;
	}

	iterator end()
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}

	const_iterator end() const
	{
		//最后一个元素的下一个位置
		return _data + _size;
	}


	String(const char* str = "")
		:_size(strlen(str))
		,_capacity(_size)
		,_data(new char[_size + 1])
	{
		strcpy(_data, str);
	}

	//拷贝构造
	String(const String& str)
		:_size(0)
		,_capacity(0)
		,_data(nullptr)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_size, str._size);
		swap(_capacity, str._capacity);
		swap(_data, str._data);
	}

	String& operator=(const String& str)
	{
		String tmp(str._data);
		Swap(tmp);
		return *this;
	}

	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}

	//可读可写
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	//只读
	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char* c_str() const
	{
		return _data;
	}

	//尾插一个字符
	void pushBack(const char& ch)
	{
		//没有空余的空间
		if (_size == _capacity)
		{
			//增容: 2倍
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//假如有空余空间
		_data[_size] = ch;
		++_size;
		_data[_size] = '\0';
	}

	void reserve(size_t n)
	{
		//只增加容量
		if (n > _capacity)
		{
			//1.开空间
			char* tmp = new char[n + 1];
			//2.拷贝
			strcpy(tmp, _data);
			//3.释放原有空间
			delete[] _data;
			//更新成员
			_data = tmp;
			_capacity = n;

		}
	}

	void resize(size_t n, const char& ch = '\0')
	{
		// n > _capacity
		if (n > _capacity)
		{
			//增容
			reserve(n);
		}
		// _size < n <= _capacity
		//for (size_t pos = _size; pos < n; ++pos)
		//	_data[pos] = ch;
		if(n > _size)
			memset(_data + _size, ch, sizeof(char) * (n - _size));
		// n <= _size
		_size = n;
		_data[_size] = '\0';
	}

	void append(const char* str)
	{
		int len = strlen(str);
		//1.检查容量
		if (_size + len > _capacity)
		{
			//增容
			reserve(_size + len);
		}
		//2.插入
		memcpy(_data + _size, str, sizeof(char) * len);
		//strcpy(_data + _size, str);
		//3.更新
		_size += len;
		_data[_size] = '\0';
	}

	String& operator+=(const String& str)
	{
		append(str._data);
		return *this;
	}
	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	String& operator+=(const char ch)
	{
		pushBack(ch);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//0.检查位置的有效性：[0, _size]
		assert(pos <= _size);
		//1.检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		//2.移动元素：从后向前移动
		//最先移动的为'\0' 
		size_t end = _size + 1;
		while (end > pos)
		{
			_data[end] = _data[end - 1];
			--end;
		}

		//3.插入
		_data[pos] = ch;
		//4.更新
		_size++;
	}

	void insert(size_t pos, const char* ptr)
	{
		//检查位置
		assert(pos <= _size);
		int len = strlen(ptr);
		//检查容量
		if (_size + len > _capacity)
		{
			reserve(len + _size);
		}
		//移动元素
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_data[end] = _data[end - pos];
			--end;
		}
		//插入
		//for (int i = 0; i < len; ++i)
		//{
		//	_data[i + pos] = ptr[i];
		//}
		memcpy(_data + pos, ptr, sizeof(char) * len);
		//更新
		_size += len;
	}

	void erase(size_t pos, size_t len = npos)
	{
		assert(pos < _size);
		//从pos开始，删除剩余的所有元素
		if (len == npos || pos + len >= _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else
		{
			//从前向后，每一个待移动的元素统一向前移动len个位置
			size_t start = pos + len;
			while (start <= _size)
			{
				_data[start - len] = _data[start];
				++start;
			}
			//更新
			_size -= len;
		}
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		for (int i = 0; i < _size; ++i)
		{
			if (_data[i] == ch)
				return i;
		}
		//未找到或者位置越界
		return npos;
	}

	size_t find(const char* ptr, size_t pos = 0)
	{
		assert(pos < _size);
		char* str = strstr(_data + pos, ptr);
		if (str)
		{
			return str - _data;
		}
		return npos;
	}

	String substr(size_t pos, size_t len = npos)
	{
		assert(pos < _size);
		if (len == npos || pos + len >= _size)
		{
			String str(_data + pos);
			return str;
			//return String(_data + pos);
		}
		else
		{
			char* newC = new char[len + 1];
			memcpy(newC, _data + pos, sizeof(char) * len);
			newC[len] = '\0';
			return String(newC);
			delete[] newC;
		}
	}

	//输出格式比较难受，一般不这么来写，一般定义成非成员函数
	//ostream& operator<<(ostream& out)
	//{
	//	//不是按照c风格的字符串形式输出
	//	for (const auto& ch : *this)
	//	{
	//		out << ch;
	//	}
	//	return out;
	//}

private:
	//size：有效字符的个数
	size_t _size;
	//容量：最大存放字符的个数
	size_t _capacity;
	char* _data;

	static const size_t npos;
};

const size_t String::npos = -1;

ostream& operator<<(ostream& out, const String& str)
{
	//不是按照c风格的字符串形式输出
	for (const auto& ch : str)
	{
		out << ch;
	}
	return out;
}

istream& operator>>(istream& in, String& str)
{
	char ch;
	//如果使用cin不能读入空格和换行，读入就不会结束
	while (ch = cin.get())
	{
		if (ch == ' ' || ch == '\n')
			break;
		//尾插
		str += ch;
	}
	return cin;
}

bool operator<(const String& str1, const String& str2)
{
	int ret = strcmp(str1.c_str(), str2.c_str());
	if (ret < 0)
		return true;
	return false;
}

bool operator==(const String& str1, const String& str2)
{
	int ret = strcmp(str1.c_str(), str2.c_str());
	if (ret == 0)
		return true;
	return false;
}

String operator+(const String& str1, const String& str2)
{
	String str = str1;
	str += str2;
	return str;
}
String operator+(const char* str1, const String& str2)
{
	String str = str2;
	str += str1;
	return str;
}
String operator+(const char ch, const String& str2)
{
	String str = str2;
	str += ch;
	return str;
}

void printString(const String& str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

void printFor(const String& str)
{
	for (const auto& ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void printIterator(const String& str)
{
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}



void test()
{
	String str = "123456789";
	for (const auto& ch : str)
	{
		cout << ch << " ";
	}
	cout << endl;
	String::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";
		*it = 'a';
		++it;
	}
	cout << endl;
}
//
//void test()
//{
//	String str = "1234";
//	String copy(str);
//}

//现代写法
//class String
//{
//public:
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//
//	//拷贝构造
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(_data, tmp._data);
//	}
//
//	String& operator=(const String& str)
//	{
//		String tmp(str._data);
//		swap(_data, tmp._data);
//		return *this;
//	}
//
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//private:
//	char* _data;
//};
//
//void test()
//{
//	String str = "1234";
//	String copy(str);
//}

//传统写法
//class String
//{
//public:
//	//无参构造函数
//	//String()
//	//	:_data(new char[1])
//	//{
//	//	_data[0] = '\0';
//	//}
//
//	//带缺省值的构造函数
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//
//	//浅拷贝
//	String(const String& str)
//		:_data(str._data)
//	{}
//
//	//深拷贝： 拷贝对象的内容 + 对象的资源
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		//拷贝资源
//		strcpy(_data, str._data);
//	}
//
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			//释放原有的资源空间
//			delete[] _data;
//			//开新的资源空间
//			_data = new char[strlen(str._data) + 1];
//			//拷贝内容
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//
//	const char* c_str() const
//	{
//		return _data;
//	}
//	
//	//析构函数
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//
//private:
//	char* _data;
//};
//
//void test()
//{
//	String str("1234");
//	String str2 = "abc";
//	String copy(str);
//}

//void test()
//{
//	string str;
//	cout << str.c_str() << endl;
//	char arr[] = "abc";
//	cout << arr << endl;
//	String str2;
//	cout << str2.c_str() << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}