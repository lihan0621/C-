#define F(x, y) ((x) + (y))
#include <stdio.h>

struct Test1
{
	short a;
	char b;
	long c;
	long d;
};

struct Test2
{
	long a;
	short b;
	char c;
	long d;
};

struct Test3
{
	short a;
	long b;
	char c;
	long d;
};

void test()
{
	struct Test1 T1;
	struct Test2 T2;
	struct Test3 T3;
	printf("%d  %d  %d", sizeof(T1), sizeof(T2), sizeof(T3));
}

void test4()
{
	int i = 1, sum = 0;
	while (i < 10) {
		sum = sum + 1;
		i++;
	}
	printf("%d  %d\n", i, sum);
}

void test3()
{
	int x;
	x = 5 > 2 + 1 && 2 || 2 * 4 < 4 - !0;
	printf("%d\n", x);
}

void test2()
{
	int a = 3, b = 4;
	printf("%d\n", F(a++, b++));
}

void test1()
{
	char a[20];
	char* ptr = (char*)a;
	char* ptr2 = (char*)(a + 5);
	int n = ptr2 - ptr;
	printf("%d\n", n);
}

int main()
{
	test();
	system("pause");
	return 0;
}