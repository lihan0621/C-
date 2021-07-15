#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDataType;
typedef struct seqList {
	SLDataType* _data;//��Ҫ��̬���ٵ�����
	size_t _size;      //��ЧԪ�صĸ���
	size_t _capaticy;  //��ǰ���Դ�ŵ����Ԫ�ظ���
}seqList;

//��ʼ��
void InitSeqList(seqList* sl) {
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capaticy = 0;
}

//�������
void CheckCapacity(seqList* sl) {
	//assert(sl);
	if (sl == NULL)
		return;
	//���Ԫ�ظ�����������ͬ, ˵���ռ�����, ��Ҫ�����ռ�(����)
	if (sl->_size == sl->_capaticy) {
		int newCapacity = sl->_capaticy == 0 ? 1 : 2 * sl->_capaticy;
		//��һ������Ŀռ�, �������е�����, �ͷ�ԭ�еĿռ�
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType) * newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType) * sl->_size);
		free(sl->_data);
		//��һ��д��
		//sl->_data = (SLDataType*)realloc(sl->_data, sizeof(SLDataType) * newCapacity);
		//����
		sl->_data = tmp;
		sl->_capaticy = newCapacity;
	}
}

//β��
void pushBack(seqList* sl, SLDataType val) {
	//�������
	CheckCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

//βɾ
void popBack(seqList* sl) {
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}

//ͷ��
// һ�㲻����ͷ��: Ч��̫��
//1.�ƶ�Ԫ��: [0, size)ȫ������ƶ�һ��λ��
//      ����: ���ܴ�ǰ����ƶ�, �ᵼ�����ݱ�����
void pushFront(seqList* sl, SLDataType val) {
	if (sl == NULL)
		return;
	//0.�������
	CheckCapacity(sl);
	//1.�ƶ�Ԫ��: ��ǰ����ƶ�
	size_t end = sl->_size;
	while (end > 0) {
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//ͷ��
	sl->_data[0] = val;
	//����
	sl->_size++;
}

//ͷɾ
//1.�ƶ�Ԫ��: [0, size)ȫ����ǰ�ƶ�һ��λ��
//����: ���ܴӺ���ǰ�ƶ�, �ᵼ�����ݱ�����
void popFront(seqList* sl) {
	if (sl == NULL || sl->_size == 0)
		return;
	CheckCapacity(sl);
	int start = 1;
	while (start < sl->_size) {
		sl->_data[start - 1] = sl->_data[start];
		++start;
	}
	sl->_size--;
}

void insert(seqList* sl, int pos, SLDataType val) {
	if (sl == NULL)
		return;
	//0.�������
	CheckCapacity(sl);
	//��Ч�Ĳ���λ��: [0, size]
	if (pos >= 0 && pos <= sl->_size) {
		size_t end = sl->_size;
		//�ƶ�Ԫ��: [pos, size)
		while (end > pos) {
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}
		//����
		sl->_data[pos] = val;
		//����
		sl->_size++;
	}
}

void erase(seqList* sl, int pos) {
	if (sl == NULL || sl->_size == 0)
		return;
	//0.�������
	CheckCapacity(sl);
	if (pos >= 0 && pos < sl->_size) {
		//�ƶ�Ԫ��: (pos, size)
		//��pos + 1��ʼ��ǰ����Դ��ƶ�Ԫ��
		int start = pos + 1;
		while (start < sl->_size) {
			sl->_data[start - 1] = sl->_data[start];
			--start;
		}
		--sl->_size;
	}
}

int empty(seqList* sl) {
	if (sl == NULL || sl->_size == 0)
		return 1;
	else
		return 0;
}

int size(seqList* sl) {
	if (sl == NULL)
		return 0;
	else
		return sl->_size;
}

int find(seqList* sl, SLDataType val) {
	for (size_t i = 0; i < sl->_size; ++i) {
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}

//��ӡ
void printSeqList(seqList* sl) {
	for (size_t i = 0; i < sl->_size; i++) {
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

void test() {
	seqList sl;
	InitSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
}

int main() {
	test();
	return 0;
}
