#include <stdlib.h>
#include <iostream>

using namespace std;


void test()
{
	//new: operator new--->malloc
	int* ptr = new int;
	//delete: operator delete-->free
	delete ptr;
}

//void* operator new(size_t n);
//void test()
//{
//	//通过这两种方式就可以看出：operator new不是new的运算符重载函数
//	//void* ptr = operator new(sizeof(int));
//	//void* ptr2 = new sizeof(int);
//	//同理：operator delete也不是delete的运算符重载函数
//	//operator new和operator delete是C++中的全局函数
//	//它们的使用方式类似于malloc和free
//	//operator new：malloc + 异常
//	int* ptr = (int*)operator new(sizeof(int));
//	int* ptr2 = (int*)malloc(sizeof(int));
//
//	//operator delete：封装了free
//	operator delete(ptr);
//	free(ptr2);
//}

//class A
//{
//public:
//	/*A()
//	{
//		cout << "A()" << endl;
//	}*/
//	A(int a = 10)
//		:_a(a)
//	{}
//	A(int a, int b, int c)
//		:_a(a)
//	{}
//	~A()
//	{
//		cout << "清理资源" << endl;
//		cout << "~A()" << endl;
//	}
//private:
//	int _a = 10;
//};
//
//void test()
//{
//	A* mpa= (A*)malloc(sizeof(A));
//	free(mpa);
//	cout << "---------" << endl;
//	//自定义类型：new：申请空间 + 调用构造函数进行空间内容的初始化
//	//类型指针 指针变量 new 类型--->调用默认构造(无参，全缺省)
//	A* pa1 = new A;
//	//类型指针 指针变量 new 类型(参数列表)--->调用带参构造
//	A* pa2 = new A(10);
//	A* pa3 = new A(1, 2, 3);
//	//自定义类型：delete：调用析构完成资源清理 + 释放空间
//	delete pa1;
//	delete pa2;
//	delete pa3;
//
//	//自定义类型：连续空间
//	//new[]：申请空间 + 调用N次构造函数，需要有默认构造存在
//	A* arrA = new A[100];
//	//不能使用带参的构造进行对个对象的空间申请和初始化
//	//A* arrA2 = new A(10)[3];
//	//delete[]：调用N次析构 + 空间释放
//	delete[] arrA;
//}

//void test()
//{
//	//申请和释放的方式保持一致
//	//malloc ---> free
//	int* mptr = (int*)malloc(sizeof(int));
//	free(mptr);
//
//	//类型指针 指针变量 = new 类型
//	//类型指针 指针变量 = new 类型(初始值)
//	//类型指针 指针变量 = new 类型[元素个数]
//	//new --->delete
//	int* ptr = new int;
//	delete ptr;
//	//申请空间 + 初始化：初始值为10--->4byte
//	int* ptr2 = new int(10);
//	delete ptr2;
//	//new[] ---> delete[]
//	//连续空间：包含10个元素--->40byte，内容为随机值
//	int* arr = new int[10];
//	//释放连续空间
//	delete[] arr;
//}

//void test()
//{
//	//malloc只负责申请空间，不负责初始化
//	char* ptr = (char*)malloc(sizeof(char));
//	//调整空间大小
//	char* ptr2 = (char*)realloc(ptr, 2 * sizeof(char));
//	//申请新的空间，功能和malloc相同
//	char* ptr3 = (char*)realloc(NULL, sizeof(char));
//	char* ptr4 = (char*)realloc(ptr3, sizeof(char) * 100);
//
//	char* ptr5 = (char*)realloc(NULL, sizeof(char));
//	char* ptr6 = (char*)realloc(ptr5, sizeof(char) * 100000);
//
//	//ptr指向的空间不能显示释放
//	//只能显式释放realloc返回之后的空间，传入realloc中的指针空间不能显式释放
//	//free(ptr);
//	free(ptr2);
//	//free(ptr3);
//	free(ptr4);
//	//free(ptr5);
//	free(ptr6);
//
//	//申请空间 + 全部初始化为0
//	char* ptr7 = (char*)calloc(4, sizeof(char));
//}

//void test()
//{
//	char* ptr = (char*)malloc(0x7fffffff);
//	char* ptr2 = (char*)malloc(0xffffffff);
//}


//int globalVar = 1;
//static int staticGlobalVar = 1;
//
//void test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}

int main()
{
	test();
	system("pause");
	return 0;
}
