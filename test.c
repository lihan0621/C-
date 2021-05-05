//#include<stdio.h>
//#include<stdlib.h>
////int Statistics(int num){
////	int count = 0;
////	while (num){
////		num = num & num - 1;
////			count++;
////	}
////	printf("%d\n",count);
////	return count;
////}
////int calc_diff_bit(int a,int b){
////	int tem = a ^ b;
////	return Statistics(tem);
////}
////void Printbit(int num){
////	for (int i = 0; i <= 30; i += 2){
////		printf("%d ",(num >> i) & 1);
////	}
////	printf("\n");
////	for (int i = 1; i <= 31; i += 2){
////		printf("%d ", (num >> i) & 1);
////	}
////	printf("\n");
////}
//void exchange(int a,int b){
//	printf("%d-%d\n",a,b);
//	/*a = a + b;
//	b = a - b;
//	a = a - b;*/
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d-%d\n",a,b);
//}
//int main(){
//	exchange(10, 20);
//	
//	system("pause");
//	return 0;
//}
//#include < stdio.h >
//#include<stdlib.h>
//struct S
//{
//	int a;
//	int b;
//};
//int main()
//{
//	struct S a, *p = &a;
//	a.a = 99;
//	printf("%d\n", a.a);
//	system("pause");
//	return 0;
//}
#include < stdio.h >
#include<stdlib.h>
int main(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p = (int *)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(p - 1));
	system("pause");
	return 0;
}