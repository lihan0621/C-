#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


mutex mtx;

//����ģʽ
//2. ����ģʽ
class singlenton
{
	//���еķ�����ȡ����
public:
	static singlenton* getSingleton()
	{
		mtx.lock();
		if (_sin == nullptr)
		{
			//��һ��ʹ�ô���
			_sin = new singlenton;
			cout << _sin << endl;
		}
		mtx.unlock();
		return _sin;
	}
private:
	//���캯��˽��
	singlenton()
	{}

	//������
	singlenton(const singlenton&) = delete;

	//staticָ���Ա
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

//����ģʽ
//1. ����ģʽ
// a. ����ֻ�ܱ�����һ��

//class singleton
//{
//public:
//	//���еķ�����������
//	static singleton* getSingleton()
//	{
//		//��ȡ�Ѵ��ڶ���ĵ�ַ
//		return &_instance;
//	}
//private:
//	//���캯��˽��
//	singleton()
//	{}
//
//	//����һ�����static��Ա
//	static singleton _instance;
//
//	//������
//	singleton(const singleton&) = delete;	
//};
//
//singleton singleton::_instance;
//
//void test()
//{
//	singleton* ptr = singleton::getSingleton();
//}

//����Ĺ��캯������Ϊ˽�е�
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

//���ܼ̳е���
//���ඨ���final��
//class A final
//{};
//class B : public A
//{};

//class StackObj
//{
//private:
//	//��ֹ����operator new
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
//	//���еķ�����������
//	static StackObj getObj()
//	{
//		return StackObj();
//	}
//	//���캯��˽��
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
//	//���ù��캯����������
//	static HeapObj* getObj()
//	{
//		//HeapObj* p = new HeapObj();
//		//return *p;
//		return new HeapObj;
//	}
//	//��ֹ���캯���ĵ��ã� ˽��
//private:
//	HeapObj()
//	{}
//
//	//������
//	//ֻ��������ʵ��
//	//HeapObj(const HeapObj&);
//
//	//��������Ϊdelete����
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