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

	//������
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
//	//unique_ptr: ��û�и�ֵ�Ϳ����ĳ����£���������ʹ��
//	//unique_ptr: ������
//	unique_ptr<Date> up(new Date);
//	//unique_ptr: �Ŀ�������Ϊɾ������
//	//unique_ptr<Date> up2(up);
//	unique_ptr<Date> up3(new Date);
//	//unique_ptr: ��ֵ�����Ϊɾ������
//	//up3 = up;
//}

//auto_ptr: ��ֹʹ�ã�����Ȩת������
//auto_ptr��ģ��ʵ��
//template <class T>
//class AutoPtr
//{
//public:
//	//���캯����ȡ��Դ����Ȩ
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
//	//����Ȩת��
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
//			//����Ȩת��
//			_ptr = ap->_ptr;
//			ap->_ptr = nullptr;
//		}
//		return *this;
//	}
//
//	//�������ͷ���Դ
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

//����ָ�룺
// 1. ʵ��RAII˼��
// 2. ʵ��ָ�빦�ܣ�*��->

//template <class T>
//class Smartptr
//{
//public:
//	//���캯����ȡ��Դ����Ȩ
//	Smartptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//�������ͷ���Դ
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
//	//����д��
//	//int* ptr = new int;		//����ָ��ָ��ͬһ����Դ���ڻ�����Դʱ��������ظ��ͷŵ�����
//	//Smartptr<int> sp(ptr);
//	//Smartptr<int> sp2(ptr);
//
//	Smartptr<int> sp(new int);
//	//Smartptr<int> sp2((int*)malloc(sizeof(int)));
//
//	Smartptr<A> sp2(new A);
//
//	//����ָ��, ���������������Զ��ͷ��ڴ棬 �������ڴ�й©������
//	*sp = 10;
//	sp2->_a = 100;
//	(*sp2)._a = 1000;
//
//	//��ָͨ�룬�ֶ��ͷ��ڴ�, �����ڴ�й©������
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