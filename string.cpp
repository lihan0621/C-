//深浅拷贝



//#include<iostream>
//#include<string>
//using namespace std;
////现代写法
//class String
//{
//public:
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//	//拷贝构造：现代写法--->复用拷贝的逻辑
//	//借助构造函数在创建局部对象时，进行空间申请+内容拷贝
//	//通过交换成员的执行，最终达到拷贝构造的目的
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(_data, tmp._data);
//	}
//	//赋值运算符：现代写法-->复用拷贝
//	//借助拷贝构造完成：进行空间申请+内容拷贝
//	//借助局部对象的析构函数完成当前对象原有资源的释放
//	String& operator=(String str)
//	{
//		swap(_data, str._data);
//		return *this; 
//	}
//	~String()
//	{
//		if (_data)
//		{
//			delete[]_data;
//			_data = nullptr;
//		}
//	}
//private:
//	char* _data;
//};
//传统写法
//class String
//{
//public:
//	/*String()
//		:_data(new char[1] )
//	{
//		_data[0] = '\0'; 
//	}*/
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])
//	{
//		strcpy(_data, str);
//	}
//	////浅拷贝
//	//String(const String& str)
//	//	:_data(str._data)
//	//{}
//	//深拷贝
//	String(const String& str)
//		:_data(new char[strlen(str._data) + 1])
//	{
//		strcpy(_data, strcat._data);
//	}
//	String& operator=(const String& str)
//	{
//		if (this != &str)
//		{
//			delete[] _data;
//			_data = new char[strlen(str._data) + 1];
//			strcpy(_data, str._data);
//		}
//		return *this;
//	}
//	const char* c_str()const
//	{
//		return _data;
//	}
//	~String()
//	{
//		if (_data)
//		{
//			delete[]_data;
//			_data = nullptr;
//		}
//	}
//
//private:
//	char* _data;
//};
//void test()
//{
//	String str;
//	cout << str.c_str() << endl;
//	String str2;
//	cout << str2.c_str() << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}