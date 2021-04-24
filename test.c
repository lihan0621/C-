#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Findkey(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}
int FindMax(int arr[], int n) {
	//int max = 0;int arr[] = { -1, -2, -3, -4 };
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int FindSecond(int arr[], int n)
{
	int first;
	int second;
	if (arr[0] > arr[1]) {
		first = arr[0];
		second = arr[1];
	}
	if (arr[0] < arr[1]) {
		first = arr[1];
		second = arr[0];
	}
	for (int i = 2; i < n; i++) {
		if (arr[i] > first) {
			second = first;
			first = arr[i];
		}
		else if (arr[i] > second) {
			second = arr[i];
		}
	}
	return second;
}
int main()
{
	int arr[] = { 1,84,5,43,27,74,7,8,73,12,4,76 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//int key = 0;
	//scanf("%d", &key);
	//int index = Findkey(arr, n, key);
	//if (index == -1) {
	//	printf("√ª’“µΩ\n");
	//}
	//else {
	//	printf("%d\n", index);
	//}
	int max = FindMax(arr, n);
	printf("%d\n", max);
	int second = FindSecond(arr, n);
	printf("%d\n", second);
	return 0;
}