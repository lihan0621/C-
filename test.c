#include <stdio.h>

//��̬˳���: �ռ䲻��
typedef int SLDataType;
#define N 10
typedef struct seqList1 {
	SLDataType _data[N];
	size_t _size;      
	size_t _capaticy; 
}seqList1;
//��̬˳�����: �ռ�ɱ�
typedef struct seqList {
	SLDataType* _data;//��Ҫ��̬���ٵ�����
	size_t _size;      //��ЧԪ�صĸ���
	size_t _capaticy;  //��ǰ���Դ�ŵ����Ԫ�ظ���
}seqList;

void test1() {
	printf("��̬: %d\n", sizeof(seqList1));
	printf("��̬: %d\n", sizeof(seqList));
}

int main1() {
	test();
	system("pause");
	return 0;
}