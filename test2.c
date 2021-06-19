//#include <stdio.h>
///*
//int main() {
//	struct S1
//	{
//		char c1;
//		int i;
//		char c2;
//	};
//	printf("%d\n", sizeof(struct S1));
//	//练习2
//	struct S2
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	printf("%d\n", sizeof(struct S2));
//	//练习3
//	struct S3
//	{
//		double d;
//		char c;
//		int i;
//	};
//	printf("%d\n", sizeof(struct S3));
//	//练习4-结构体嵌套问题
//	struct S4
//	{
//		char c1;
//		struct S3 s3;
//		double d;
//	};
//	printf("%d\n", sizeof(struct S4));
//	return 0;
//}*/
//
//#pragma pack(2)//设置默认值
//struct A {
//	char a;
//	int b;
//	char c;
//};
//
//#pragma pack(2)//还原默认值
//enum Sex {
//	MALE,
//	FEMALE,
//	UNKNOWN
//};
//
//enum Week {
//	Monday,
//	Tuesday,
//	Wednesday
//};
//
//union Un {
//	char i;
//	int a;
//};
//
//union IPAddress {
//	unsigned int data;
//	struct IP {
//		unsigned char a;
//		unsigned char b;
//		unsigned char c;
//		unsigned char d;
//	}ip;
//};
//int main1() {
//
//	union Un u;
//	u.i = 10;
//	u.a = 0;
//	printf("%d\n", u.i);
//
//	//按理说Sex和Week这个概念是不相同的
//	//但是在C语言中,因为大家都被视为int, 就可以使用
//	//enum Sex s = MALE;
//	//s = Monday;
//	//struct A structA;
//	//printf("%p\n", &structA);
//	//printf("%p\n", &structA.a);
//	//printf("%p\n", &structA.b);
//	//printf("%p\n", &structA.c);
//	//printf("%d\n", sizeof(structA));
//	return 0;
//}
//int main() {
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d\n", *(aa + 1));
//	printf("%d\n", &(aa[1][0]));
//	return 0;
//}
//int main() {
//	int aa[5] = { 1,2,3,4,5 };
//	printf("%d\n", aa + 1);
//	printf("%d\n", &(aa[1]));
//	return 0;
//}