#include <stdio.h>

void Swap(int* arr, int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void test()
{
	int arr[] = { 1,2,3 };
	Swap(arr, &arr[1], &arr[2]);
	for (int i = 0; i < 3; ++i)
		printf("%d ", arr[i]);
}

int main()
{
	test();
	return 0;
}