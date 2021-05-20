//#include<iostream>
//#include<string>
//using namespace std;
//class A
//{
//	virtual void func()
//	{
//		cout << "func" << endl;
//	}
//	//float f;
//	//char p;
//	//int adf[3];
//};
//int main()
//{
//	cout << sizeof(A);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short* p = (short*)arr;
//	for (int i = 0; i < 5; ++i) {
//		*(p + i) = 0;
//	}
//	for (int i = 0; i < 5; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//void fun()
//{
//	int sum = 0;
//	int cur = 0;
//	for (int i = 1; i <= 5; i++) {
//		cur = cur * 10 + 2;
//		sum += cur;
//	}
//	printf("%d", sum);
//}
//int calcDecimalCount(int num)
//{
//	int count = 0;
//	while (num != 0) {
//		num /= 10;
//	count++;
//	}
//	return count;
//}
//int shuixian(int num)
//{
//	int oldnum = num;
//	int n = calcDecimalCount(num);
//	int sum = 0;
//	while (num != 0) {
//		int tmp = num % 10;
//		sum += pow(tmp, n);
//	}
//	if (sum == oldnum)
//		return 1;
//	return 0;
//}
//´òÓ¡ÁâÐÎ
//void printLine(int starCount, int spaceCount)
//{
//	for (int i = 0; i < spaceCount; i++) {
//
//	}
//}
//void printlingxing()
//{
//	for (int row = 1; row <= 6; row++) {
//		printLine(2 * row - 1, 7 - row);
//	}
//	printLine();
//}
//int main()
//{
//	for (int i = 0; i < 100000; ++i) {
//		if (shuixian(i)) {
//			printf("%d\n", i);
//		}
//	}
//	//fun();
//	return 0;
//}