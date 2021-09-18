#include <iostream>
#include <memory> 
using namespace std;

struct Date
{
	int _y = 1;
	int _m = 2;
	int _d = 3;

	~Date()
	{
		cout << "~Date()" << endl;
	}
};

template <class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{}

	//防拷贝
	UniquePtr(const UniquePtr<T>& up) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>& up) = delete;

	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

private:
	T* _ptr;
};

//void test()
//{
//	//unique_ptr: 在没有赋值和拷贝的场景下，可以正常使用
//	//unique_ptr: 防拷贝
//	unique_ptr<Date> up(new Date);
//	//unique_ptr: 的拷贝构造为删除函数
//	//unique_ptr<Date> up2(up);
//	unique_ptr<Date> up3(new Date);
//	//unique_ptr: 赋值运算符为删除函数
//	//up3 = up;
//}

//auto_ptr: 禁止使用：管理权转移问题
//auto_ptr：模拟实现
//template <class T>
//class AutoPtr
//{
//public:
//	//构造函数获取资源管理权
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	//管理权转移
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this != &ap)
//		{
//			if (_ptr)
//				delete _ptr;
//			//管理权转移
//			_ptr = ap->_ptr;
//			ap->_ptr = nullptr;
//		}
//		return *this;
//	}
//
//	//析构中释放资源
//	~AutoPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr; 
//		}
//	}
//
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	AutoPtr<int> ap(new int);
//	AutoPtr<int> ap2(new int(3));
//	*ap = 10;
//	*ap2 = 100;
//
//	AutoPtr<int> ap3 = ap;
//	//*ap = 100;
//
//	int* pa = new int;
//	int* pa2 = pa;
//
//}

//智能指针：
// 1. 实现RAII思想
// 2. 实现指针功能：*，->

//template <class T>
//class Smartptr
//{
//public:
//	//构造函数获取资源管理权
//	Smartptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//析构中释放资源
//	~Smartptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//class A
//{
//public:
////private:
//	int _a = 10;
//};
//
//void test()
//{
//	//错误写法
//	//int* ptr = new int;		//两个指针指向同一份资源，在回收资源时，会出现重复释放的问题
//	//Smartptr<int> sp(ptr);
//	//Smartptr<int> sp2(ptr);
//
//	Smartptr<int> sp(new int);
//	//Smartptr<int> sp2((int*)malloc(sizeof(int)));
//
//	Smartptr<A> sp2(new A);
//
//	//智能指针, 编译器调用析构自动释放内存， 不存在内存泄漏的问题
//	*sp = 10;
//	sp2->_a = 100;
//	(*sp2)._a = 1000;
//
//	//普通指针，手动释放内存, 存在内存泄漏的问题
//	int* p = new int;
//	A* pa = new A;
//	*p = 5;
//	pa->_a = 1;
//	(*pa)._a = 10;
//
//	delete p;
//	delete pa;
//
//	return;
//	cout << "test" << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}