#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define A 4 + 5
#define B A*A
// N 2
//#define M N+1
//#define NUM (M+1)*M/2
//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	} 
//	return b;
//}
//int f(int n)
//{
//	if (n) return f(n - 1) + n;
//	else return n;
//}
//int a, b;
//void fun()
//{
//	a = 100;
//	b = 200;
//}
//struct HAR{ int x, y; struct HAR *p; } h[2];
//int func(int i, int j)
//	{
//			if (i <= 0 || j <= 0)
//				return 1;
//			return 2 * func(i - 3, j / 2);
//		}
//int main()
//{
	//h[0].x = 1; h[0].y = 2;
	//h[1].x = 3; h[1].y = 4;
	//h[0].p = &h[1]; h[1].p = h;
	//printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);
	//int a, b;
	//scanf("%d,%d", &a, &b);
	//if (a>b) a = b; b = a;
	//else a++; 
	//b++;
	//	
	//char s[] = "abcdefgh", *p = s;
	//p += 3;
	//printf("%d\n", strlen
	//	(strcpy(p, "ABCD")));
	/*printf("%d\n", func(15,20));*/
	//int a[] = { 2, 4, 6, 8 }, *p = a, i;
	//for (i = 0; i<4; i++)
	//	a[i] = *p++;
	//printf("%d\n", a[2]);
	//int a = 1; int b = 2;
	//for (; a<8; a++)
	//{
	//	b += a; a += 2;
	//}
	//printf("%d\n", B*B);
	//short i = 65537;
	//int j = i + 1;
	//printf("i=%d,j=%d\n", i, j);
//	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
//	p = a;
//	k = &p;
//	printf(" % d", *(p++));
//	printf(" % d\n", **k);
//		getchar();
//	return 0;
//}
//int main()
//{
//	int a = 5, b = 7;
//	fun();
//	printf("%d %d\n", a, b);
//int main()
//{
//	printf("%d", f(4));
//	//char str[] = "ABCD", *p = str;
//	//printf("%d\n", *(p + 4));
//	//char *p = "abcdefgh", *r;
//	//long *q;
//	//q = (long*)p;
//	//q++;
//	//r = (char*)q;
//	//printf("%s\n", r);
//
//	/*func(1);
//	int b;*/
//	//int n = 2;
//	//n += n -= n*n;
//	//printf("%d\n", n);
//
////int main()
////{
////		int i = 0, a = 0;
////		while (i<20)
////		{
////			for (;;)
////			{
////				if ((i % 10) == 0) break;
////				else i--;
////			} i
////				+= 11; a += i;
////		}
////		printf("%d\n", a);
//	getchar();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int fun(int x, int y)
//{
//	if (x == y)
//		return (x);
//	else
//		return ((x + y) / 2);
//} 
//int main()
//{
//	int a = 4, b = 5, c = 6;
//	printf("%d\n", fun(2 * a, fun(b, c)));
//	getchar();
//	return 0;
//}
int* Array()
{
	int arr[] = { 1, 2, 3 };
	return arr;
}
int main()
{

	getchar();
	return 0;
}