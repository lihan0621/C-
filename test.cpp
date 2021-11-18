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
		void* ptr = malloc(sz);               //operator new的重载
		return ptr;
	}
		void operator delete[](void* ptr)         //delete 重载
	{
		free(ptr);
	}
		void* operator new(size_t size, Test* ptr)
	{
		return &ptr[0]; // acement new的重载
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
	delete[]pt;              //不会有警告


	Test* pt1 = new Test[10];
	new(pt1)Test(1);
	delete[]pt1;     //警告：warning C4291: “void *Test::operator new(size_t,Test *)”: 未找到匹配的删除运算符；如果初始化引发异常，则不会释放内存	
	
}
