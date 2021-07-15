#include <stdio.h>

//静态顺序表: 空间不变
typedef int SLDataType;
#define N 10
typedef struct seqList1 {
	SLDataType _data[N];
	size_t _size;      
	size_t _capaticy; 
}seqList1;
//动态顺序表定义: 空间可变
typedef struct seqList {
	SLDataType* _data;//需要动态开辟的数组
	size_t _size;      //有效元素的个数
	size_t _capaticy;  //当前可以存放的最大元素个数
}seqList;

void test1() {
	printf("静态: %d\n", sizeof(seqList1));
	printf("动态: %d\n", sizeof(seqList));
}

int main1() {
	test();
	system("pause");
	return 0;
}