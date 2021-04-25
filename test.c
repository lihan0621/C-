//#include<stdio.h>
//#include<stdlib.h>
//void Print(int arr[6]){
//	int* p = arr;
//	for (int i = 0; i < 6; i++){
//	printf("%d",*(p+i));
//	}
//}
//int main(){
//	int arr[6] = { 0, 1, 2, 3, 4, 5 };
//	Print( arr[6]);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
﻿int PrintArr(int arr[])
{
	int i = 0;
	int* p = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	PrintArr(arr);

	return 0;
}