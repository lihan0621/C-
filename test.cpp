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
//	//ͨ�������ַ�ʽ�Ϳ��Կ�����operator new����new����������غ���
//	//void* ptr = operator new(sizeof(int));
//	//void* ptr2 = new sizeof(int);
//	//ͬ��operator deleteҲ����delete����������غ���
//	//operator new��operator delete��C++�е�ȫ�ֺ���
//	//���ǵ�ʹ�÷�ʽ������malloc��free
//	//operator new��malloc + �쳣
//	int* ptr = (int*)operator new(sizeof(int));
//	int* ptr2 = (int*)malloc(sizeof(int));
//
//	//operator delete����װ��free
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
//		cout << "������Դ" << endl;
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
//	//�Զ������ͣ�new������ռ� + ���ù��캯�����пռ����ݵĳ�ʼ��
//	//����ָ�� ָ����� new ����--->����Ĭ�Ϲ���(�޲Σ�ȫȱʡ)
//	A* pa1 = new A;
//	//����ָ�� ָ����� new ����(�����б�)--->���ô��ι���
//	A* pa2 = new A(10);
//	A* pa3 = new A(1, 2, 3);
//	//�Զ������ͣ�delete���������������Դ���� + �ͷſռ�
//	delete pa1;
//	delete pa2;
//	delete pa3;
//
//	//�Զ������ͣ������ռ�
//	//new[]������ռ� + ����N�ι��캯������Ҫ��Ĭ�Ϲ������
//	A* arrA = new A[100];
//	//����ʹ�ô��εĹ�����жԸ�����Ŀռ�����ͳ�ʼ��
//	//A* arrA2 = new A(10)[3];
//	//delete[]������N������ + �ռ��ͷ�
//	delete[] arrA;
//}

//void test()
//{
//	//������ͷŵķ�ʽ����һ��
//	//malloc ---> free
//	int* mptr = (int*)malloc(sizeof(int));
//	free(mptr);
//
//	//����ָ�� ָ����� = new ����
//	//����ָ�� ָ����� = new ����(��ʼֵ)
//	//����ָ�� ָ����� = new ����[Ԫ�ظ���]
//	//new --->delete
//	int* ptr = new int;
//	delete ptr;
//	//����ռ� + ��ʼ������ʼֵΪ10--->4byte
//	int* ptr2 = new int(10);
//	delete ptr2;
//	//new[] ---> delete[]
//	//�����ռ䣺����10��Ԫ��--->40byte������Ϊ���ֵ
//	int* arr = new int[10];
//	//�ͷ������ռ�
//	delete[] arr;
//}

//void test()
//{
//	//mallocֻ��������ռ䣬�������ʼ��
//	char* ptr = (char*)malloc(sizeof(char));
//	//�����ռ��С
//	char* ptr2 = (char*)realloc(ptr, 2 * sizeof(char));
//	//�����µĿռ䣬���ܺ�malloc��ͬ
//	char* ptr3 = (char*)realloc(NULL, sizeof(char));
//	char* ptr4 = (char*)realloc(ptr3, sizeof(char) * 100);
//
//	char* ptr5 = (char*)realloc(NULL, sizeof(char));
//	char* ptr6 = (char*)realloc(ptr5, sizeof(char) * 100000);
//
//	//ptrָ��Ŀռ䲻����ʾ�ͷ�
//	//ֻ����ʽ�ͷ�realloc����֮��Ŀռ䣬����realloc�е�ָ��ռ䲻����ʽ�ͷ�
//	//free(ptr);
//	free(ptr2);
//	//free(ptr3);
//	free(ptr4);
//	//free(ptr5);
//	free(ptr6);
//
//	//����ռ� + ȫ����ʼ��Ϊ0
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
