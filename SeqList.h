#pragma once

#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#include "Common.h"
#pragma warning(disable:6308)

#define IN_C 3

#define Elemtype int

typedef struct SeqList
{
	Elemtype* base;
	size_t size;
	size_t capacity;
}SeqList;

//��������
void Swap(int* a, int* b);
bool _IsFull(SeqList* pst);
bool _IsEmpty(SeqList* pst);
bool _AddCapacity(SeqList* pst);

//-------------------------------------------------------------
void SeqListInit(SeqList* pst, size_t capacity);
void SeqListPushBack(SeqList* pst, Elemtype v);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList* pst);
void SeqListPushFront(SeqList* pst, Elemtype v);
void SeqListInsertByPos(SeqList* pst, size_t pos, Elemtype v);
void SeqListInsertByVal(SeqList* pst, Elemtype v);
void SeqListEraseByPos(SeqList* pst, size_t pos);
void SeqListEraseByVal(SeqList* pst, Elemtype key);
Elemtype SeqListFindByPos(SeqList* pst, size_t pos);
size_t SeqListFindByVal(SeqList* pst, Elemtype v);
size_t SeqListLength(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
void SeqListDestroy(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListShow(SeqList* pst);
void SeqListSort(SeqList* pst);
void SeqListReverse(SeqList* pst);

//����ʵ��

bool _AddCapacity(SeqList* pst)
{
	pst->base = (Elemtype*)realloc(pst->base, sizeof(Elemtype) * (pst->capacity + IN_C));
	if (pst->base == NULL)
		return false;
	pst->capacity += IN_C;
	return true;
}

bool _IsFull(SeqList* pst)
{
	return pst->size >= pst->capacity;
}

bool _IsEmpty(SeqList* pst)
{
	return pst->size == 0;
}

//��ʼ��
void SeqListInit(SeqList* pst, size_t capacity)
{
	assert(pst != NULL);
	pst->capacity = capacity;
	pst->base = (Elemtype*)malloc(sizeof(Elemtype) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(Elemtype) * pst->capacity);
	pst->size = 0;
}

//β��
void SeqListPushBack(SeqList* pst, Elemtype v)
{
	//�������
	if(_IsFull(pst) && !_AddCapacity(pst))
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	pst->base[pst->size++] = v;
}

//βɾ
void SeqListPopBack(SeqList* pst)
{
	if(_IsEmpty(pst))
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	//ɾ������
	pst->size--;
}

//ͷɾ
void SeqListPopFront(SeqList* pst)
{
	if (_IsEmpty(pst))
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	for (size_t i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

//��ӡ
void SeqListShow(SeqList* pst)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

//ͷ��
void SeqListPushFront(SeqList* pst, Elemtype v)
{
	//�������
	if(_IsFull(pst))
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	//�ƶ�����
	for(int i=pst->size; i>0; --i)
	{
		pst->base[i] = pst->base[i-1];
	}
	//��������
	pst->base[0] = v;
	pst->size++;
}

//��λ�ò���
void SeqListInsertByPos(SeqList* pst, size_t pos, Elemtype v)
{
	//�������
	if(_IsFull(pst))
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	//���λ��
	if(pos < 0 || pos>pst->size)
	{
		printf("�����λ�÷Ƿ��� %d ���ܲ���.\n", v);
		return;
	}

	//��������
	for(size_t i = pst->size; i > pos; --i)
		pst->base[i] = pst->base[i-1];
	pst->base[pos] = v;
	pst->size++;
}

//��ֵ����
void SeqListInsertByVal(SeqList* pst, Elemtype v)
{
	//�������
	if(_IsFull(pst))
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	//Ѱ�Ҳ����λ��
	size_t pos = 0;
	while (pos < pst->size && v > pst->base[pos])
		pos++;
	SeqListInsertByPos(pst, pos, v);

}

//��λ��ɾ��
void SeqListEraseByPos(SeqList* pst, size_t pos)
{
	//���λ��
	if(pos < 0 || pos>pst->size)
	{
		printf("ɾ����λ�÷Ƿ�������ɾ������\n");
		return;
	}
	for (size_t i = pos; i < pst->size - pos; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//��ֵɾ��
void SeqListEraseByVal(SeqList* pst, Elemtype key)
{
	int pos = 0;
	while (key != pst->base[pos])
		pos++;
	SeqListInsertByPos(pst, pos, key);
}

//��λ�ò���
Elemtype SeqListFindByPos(SeqList* pst, size_t pos)
{
	//���λ��
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}

//��ֵ����
size_t SeqListFindByVal(SeqList* pst, Elemtype v)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (pst->base[i] == v)
			return i;
	}
	return -1;
}

//˳�����
size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

//˳�������
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

//����˳���
void SeqListDestroy(SeqList* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->size = pst->capacity = 0;

}

//���˳���
void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

//����
void SeqListSort(SeqList* pst)
{
	for (size_t i = 0; i < pst->size - 1; ++i)
	{
		bool flag = false;
		for (size_t j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j] > pst->base[j + 1])
				Swap(&pst->base[j], &pst->base[j + 1]);
			flag = true;
		}

		if (!flag)  //û�н���������
			return;
	}
}

void SeqListReverse(SeqList* pst)
{
	int start = 0;
	int end = pst->size - 1;
	while (start < end)
	{
		Swap(&pst->base[start], &pst->base[end]);
		++start;
		--end;
	}
}


#endif /*_SEQ_LIST_H_*/
