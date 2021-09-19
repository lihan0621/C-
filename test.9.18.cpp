#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;

//单例模式
//2. 懒汉模式
class singlenton
{
	//公有的方法获取对象
public:
	static singlenton* getSingleton()
	{
		mtx.lock();
		if (_sin == nullptr)
		{
			//第一次使用创建
			_sin = new singlenton;
			cout << _sin << endl;
		}
		mtx.unlock();
		return _sin;
	}
private:
	//构造函数私有
	singlenton()
	{}

	//防拷贝
	singlenton(const singlenton&) = delete;

	//static指针成员
	static singlenton* _sin;
};

singlenton* singlenton::_sin = nullptr;

void fun(int n)
{
	for (int i = 0; i < n; ++i)
	{
		singlenton::getSingleton();
	}
}

void test()
{
	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);
	thread t3(fun, n);
	t1.join();
	t2.join();
	t3.join();
}

//单例模式
//1. 饿汉模式
// a. 对象只能被创建一次

//class singleton
//{
//public:
//	//公有的方法创建对象
//	static singleton* getSingleton()
//	{
//		//获取已存在对象的地址
//		return &_instance;
//	}
//private:
//	//构造函数私有
//	singleton()
//	{}
//
//	//定义一个类的static成员
//	static singleton _instance;
//
//	//防拷贝
//	singleton(const singleton&) = delete;	
//};
//
//singleton singleton::_instance;
//
//void test()
//{
//	singleton* ptr = singleton::getSingleton();
//}

//基类的构造函数定义为私有的
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//void test()
//{
//	B b;
//}

//不能继承的类
//把类定义成final类
//class A final
//{};
//class B : public A
//{};

//class StackObj
//{
//private:
//	//禁止调用operator new
//	void* operator new(size_t n) = delete;
//};
//
//void test()
//{
//	//StackObj* ptr = new StackObj;
//	StackObj so;
//}

//class StackObj
//{
//public:
//	//公有的方法创建对象
//	static StackObj getObj()
//	{
//		return StackObj();
//	}
//	//构造函数私有
//private:
//	StackObj()
//	{}
//};
//
//StackObj so = StackObj::getObj();
//
//void test()
//{
//	//new StackObj;
//	StackObj so = StackObj::getObj();
//}

//class HeapObj
//{
//public:
//	//调用构造函数创建对象
//	static HeapObj* getObj()
//	{
//		//HeapObj* p = new HeapObj();
//		//return *p;
//		return new HeapObj;
//	}
//	//禁止构造函数的调用： 私有
//private:
//	HeapObj()
//	{}
//
//	//防拷贝
//	//只声明，不实现
//	//HeapObj(const HeapObj&);
//
//	//或者声明为delete函数
//	HeapObj(const HeapObj&) = delete;
//
//};
//
//void test()
//{
//	//HeapObj h;
//	HeapObj* ptr = HeapObj::getObj();
//	//HeapObj copy(*ptr);
//}

int main()
{
	test();
	system("pause");
	return 0;
}