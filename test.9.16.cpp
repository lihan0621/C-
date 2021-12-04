#include <iostream>
#include <memory> 
#include <thread>
using namespace std;

struct A
{
	int _a = 1;
	int _b = 2;

	~A()
	{
		cout << "~A" << endl;
	}
};

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _countPtr(new size_t(1))
		, _mtx(new mutex)
	{}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _countPtr(sp._countPtr)
		, _mtx(sp._mtx)
	{
		//�������ۼ�
		//++(*_countPtr);
		addCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		//�жϹ�����Ƿ�Ϊͬһ����Դ
		if(_ptr != sp._ptr)
		{
			//�������Լ�
			//���������Ϊ0����ǰ���������һ���������Դ�Ķ���
			//�������Դ���ͷ�
			//if (--(*_countPtr) == 0)
			if(subCount() == 0)
			{
				delete _ptr;
				delete _countPtr;
				delete _mtx;
			}
			_ptr = sp._ptr;
			_countPtr = sp._countPtr;

			//�������ۼ�
			//++(*_countPtr);
			addCount();
		}
		return *this;
	}

	~SharedPtr()
	{
		//�������Լ�
		//if (--(*_countPtr) == 0)
		if(subCount() == 0)
		{
			delete _ptr;
			delete _countPtr;
			delete _mtx;
			_countPtr = nullptr;
			_ptr = nullptr;
			_mtx = nullptr;
		}
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	size_t getCount()
	{
		return *_countPtr;	
	}

	size_t addCount()
	{
		_mtx->lock();
		++(*_countPtr);
		_mtx->unlock();
		return *_countPtr;
	}

	size_t subCount()
	{
		_mtx->lock();
		--(*_countPtr);
		_mtx->unlock;
		return *_countPtr;
	}
private:
	T* _ptr;
	size_t* _countPtr;
	//ÿһ����Դ��һ����������
	mutex* _mtx;
};

void test()
{
	SharedPtr<A> sp(new A[100]);
}

//struct Date
//{
//	int _y = 1;
//	int _m = 2;
//	int _d = 3;
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//};
//
//struct ListNode
//{
//	//shared_ptr<ListNode> _next;
//	//shared_ptr<ListNode> _prev]
//	weak_ptr <ListNode> _next;
//	weak_ptr<ListNode> _prev;;
//	int _data = 1;		
//
//	~ListNode()
//	{
//		cout << "~ListNode" << endl;
//	}
//};
//
//void test()
//{
//	shared_ptr<ListNode> n1(new ListNode);
//	shared_ptr<ListNode> n2(new ListNode);
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	//weak_ptr���ܵ���ʹ�ã� ��������ǽ��sheader_ptrѭ�����õ�����
//	//weak_ptr<ListNode> wp(new ListNode);
//	weak_ptr<ListNode> wp;
//	wp = n1;
//}

//SharedPtr:
// 1. ֧�ָ�ֵ�Ϳ���
// 2. ͨ�����ü�����֤��Դ����ȷ��Ψһ���ͷ�
// 3. ���߳��У��ù������ý��д��в�������֤����������ȷ
// 4. ÿһ����Դ�����Լ����������ü���
//
//template <class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		, _countPtr(new size_t(1))
//		, _mtx(new mutex)
//	{}
//
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _countPtr(sp._countPtr)
//		, _mtx(sp._mtx)
//	{
//		//�������ۼ�
//		//++(*_countPtr);
//		addCount();
//	}
//
//	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
//	{
//		//if (this != &sp)
//		//�жϹ�����Ƿ�Ϊͬһ����Դ
//		if(_ptr != sp._ptr)
//		{
//			//�������Լ�
//			//���������Ϊ0����ǰ���������һ���������Դ�Ķ���
//			//�������Դ���ͷ�
//			//if (--(*_countPtr) == 0)
//			if(subCount() == 0)
//			{
//				delete _ptr;
//				delete _countPtr;
//				delete _mtx;
//			}
//			_ptr = sp._ptr;
//			_countPtr = sp._countPtr;
//
//			//�������ۼ�
//			//++(*_countPtr);
//			addCount();
//		}
//		return *this;
//	}
//
//	~SharedPtr()
//	{
//		//�������Լ�
//		//if (--(*_countPtr) == 0)
//		if(subCount() == 0)
//		{
//			delete _ptr;
//			delete _countPtr;
//			delete _mtx;
//			_countPtr = nullptr;
//			_ptr = nullptr;
//			_mtx = nullptr;
//		}
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
//	size_t getCount()
//	{
//		return *_countPtr;	
//	}
//
//	size_t addCount()
//	{
//		_mtx->lock();
//		++(*_countPtr);
//		_mtx->unlock();
//		return *_countPtr;
//	}
//
//	size_t subCount()
//	{
//		_mtx->lock();
//		--(*_countPtr);
//		_mtx->unlock;
//		return *_countPtr;
//	}
//private:
//	T* _ptr;
//	size_t* _countPtr;
//	//ÿһ����Դ��һ����������
//	mutex* _mtx;
//};
//
//void fun(const SharedPtr<Date>& sp, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		//�޸����ü��������̰߳�ȫ
//		SharedPtr<Date> copy(sp);
//
//		//�������ݵĲ��������̰߳�ȫ��
//		copy->_y++;
//	}
//}
//
//void test()
//{
//	SharedPtr<Date> sp(new Date);
//	SharedPtr<Date> sp2(new Date);
//	int n = 10;
//	//{t1, t2}��{t3, t4}���޸����ü���ʱ���ǲ��е�
//	//t1��t2���޸����ü���ʱ���Ǵ��е�
//	//t3��t4���޸����ü���ʱ���Ǵ��е�
//	thread t1(fun, ref(sp), n);
//	thread t2(fun, ref(sp), n);
//	thread t3(fun, ref(sp2), n);
//	thread t4(fun, ref(sp2), n);
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//	cout << sp.getCount() << endl;
//	cout << sp2.getCount() << endl;
//}

//void test()
//{
//	SharedPtr<Date> sp(new Date);
//	SharedPtr<Date> sp2(new Date);
//	SharedPtr<Date> copy(sp);
//	sp2 = sp;
//}

//void test()
//{
//	shared_ptr<Date> sp(new Date);
//	cout << sp.use_count() << endl;
//	shared_ptr<Date> sp2(sp);
//	cout << sp.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	shared_ptr<Date> sp3(new Date);
//	cout << sp.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	cout << sp3.use_count() << endl;
//
//	sp3 = sp;
//	sp3 = sp2;
//	sp->_y = 2021;
//	sp2->_m = 9;
//	sp3->_d = 18;
//}

//template <class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//������
//	UniquePtr(const UniquePtr<T>& up) = delete;
//	UniquePtr<T>& operator=(const UniquePtr<T>& up) = delete;
//
//	~UniquePtr()
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