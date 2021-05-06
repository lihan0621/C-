#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;
	for (int i = 0; i < 4; i++) {
		*(p + i) = 0;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}