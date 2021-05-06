//#include<stdio.h>
//#include<stdlib.h>
//int maxNum(int x, int y)
//{
//	return x > y ? x : y;
//}
//void swap(int* a,int* b)
//{
//	a = b;
//}
//void fun()
//{
//	int a = 10, b = 20, c = 30;
//	if (a < b) {
//		swap(&a, &b);
//	}
//	if (a < c) {
//		swap(&a, &c);
//	}
//	printf("%d", a);
//	if (b < c) {
//		printf("%d", c);
//		printf("%d", b);
//	}
//	else {
//		printf("%d", b);
//		printf("%d", c);
//	}
//}
//void print3()
//{
//	for (int i = 0; i < 100; i += 3) {
//		printf("%d\n", i);
//	}
//}
//void fun2(int x, int y)
//{
//	int min = x < y ? x : y;
//	int result = 1;
//	for (int i = 1; i <= min; i++) {
//		if (x % i == 0 && y % i == 0) {
//			result = i;
//		}
//	}
//	printf("%d\n", result);
//}
//int main()
//{
//	//print3();
//	//fun2(10 , 20);
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int table(int num)
{
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}
int main()
{
	table(9);
	return 0;
}