#include<stdio.h>
#include<stdlib.h>
void fun()
{
	printf("hello\n");
}
int main()
{
	int num = 10;
	int* p = &num;

	//不加括号，fun就是函数指针
	//fun();
	//short a = 0xf122;
	//int b = a;
	//int i = 1;
	//int ret = ++i + ++i + ++i;
	//printf("%d\n", ret);
	return 0;
}