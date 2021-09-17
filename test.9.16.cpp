#include <iostream>
using namespace std;

//����ָ�룺
// 1. ʵ��RAII˼��
// 2. ʵ��ָ�빦�ܣ�*��->

template <class T>
class Smartptr
{
public:
	//���캯����ȡ��Դ����Ȩ
	Smartptr(T* ptr)
		:_ptr(ptr)
	{}

	//�������ͷ���Դ
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
	//����д��
	//int* ptr = new int;		//����ָ��ָ��ͬһ����Դ���ڻ�����Դʱ��������ظ��ͷŵ�����
	//Smartptr<int> sp(ptr);
	//Smartptr<int> sp2(ptr);

	Smartptr<int> sp(new int);
	//Smartptr<int> sp2((int*)malloc(sizeof(int)));

	Smartptr<A> sp2(new A);

	//����ָ��, ���������������Զ��ͷ��ڴ棬 �������ڴ�й©������
	*sp = 10;
	sp2->_a = 100;
	(*sp2)._a = 1000;

	//��ָͨ�룬�ֶ��ͷ��ڴ�, �����ڴ�й©������
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