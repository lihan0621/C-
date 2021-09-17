#include <iostream>
using namespace std;

//智能指针：
// 1. 实现RAII思想
// 2. 实现指针功能：*，->

template <class T>
class Smartptr
{
public:
	//构造函数获取资源管理权
	Smartptr(T* ptr)
		:_ptr(ptr)
	{}

	//析构中释放资源
	~Smartptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

private:
	T* _ptr;
};

class A
{
public:
//private:
	int _a = 10;
};

void test()
{
	//错误写法
	//int* ptr = new int;		//两个指针指向同一份资源，在回收资源时，会出现重复释放的问题
	//Smartptr<int> sp(ptr);
	//Smartptr<int> sp2(ptr);

	Smartptr<int> sp(new int);
	//Smartptr<int> sp2((int*)malloc(sizeof(int)));

	Smartptr<A> sp2(new A);

	//智能指针, 编译器调用析构自动释放内存， 不存在内存泄漏的问题
	*sp = 10;
	sp2->_a = 100;
	(*sp2)._a = 1000;

	//普通指针，手动释放内存, 存在内存泄漏的问题
	int* p = new int;
	A* pa = new A;
	*p = 5;
	pa->_a = 1;
	(*pa)._a = 10;

	delete p;
	delete pa;

	return;
	cout << "test" << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}