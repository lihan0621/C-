#include<iostream>
#include<stdlib.h>
using namespace std;


class Test
{
public:
	Test(int data = 0) : m_data(data)
	{
		cout << "Test::Test()" << endl;
	}
public:
	void* operator new[](size_t sz)
	{
		void* ptr = malloc(sz);               //operator new������
		return ptr;
	}
		void operator delete[](void* ptr)         //delete ����
	{
		free(ptr);
	}
		void* operator new(size_t size, Test* ptr)
	{
		return &ptr[0]; // acement new������
	}
	void operator delete(void* ptr)
	{
		delete[] ptr;
	}
private:
	int m_data;
};





void main()
{
	Test* pt = new Test[10];
	delete[]pt;              //�����о���


	Test* pt1 = new Test[10];
	new(pt1)Test(1);
	delete[]pt1;     //���棺warning C4291: ��void *Test::operator new(size_t,Test *)��: δ�ҵ�ƥ���ɾ��������������ʼ�������쳣���򲻻��ͷ��ڴ�	
	
}
