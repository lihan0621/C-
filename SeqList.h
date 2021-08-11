#pragma once

#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#include "Common.h"

#define Elemtype int

typedef struct SeqList
{
	Elemtype* base;
	size_t size;
	size_t capacity;
}SeqList;

//��������
void SeqListInit(SeqList* pst, size_t capacity);
void SeqListPushBack(SeqList* pst, Elemtype v);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList* pst);
void SeqListPushFront(SeqList* pst, Elemtype v);
void SeqListInsertByPos(SeqList* pst, size_t pos, Elemtype v);
void SeqListEraseByPos(SeqList* pst, size_t pos);
Elemtype SeqListFindByPos(SeqList* pst, size_t pos);
size_t SeqListFindByVal(SeqList* pst, Elemtype v);
size_t SeqListLength(SeqList* pst);
size_t SeqListCapacity(SeqList* pst);
void SeqListDestroy(SeqList* pst);
void SeqListClear(SeqList* pst);
void SeqListShow(SeqList* pst);

//����ʵ��
void SeqListInit(SeqList* pst, size_t capacity)
{
	assert(pst != NULL);
	pst->capacity = capacity;
	pst->base = (Elemtype*)malloc(sizeof(Elemtype) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(Elemtype) * pst->capacity);
	pst->size = 0;
}

void SeqListPushBack(SeqList* pst, Elemtype v)
{
	//�������
	if(pst->size >= pst->capacity)
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	pst->base[pst->size++] = v;
}

void SeqListPopBack(SeqList* pst)
{
	if(pst->size == 0)
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	//ɾ������
	pst->size--;
}

void SeqListPopFront(SeqList* pst)
{
	if (pst->size == 0)
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	for (size_t i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

void SeqListShow(SeqList* pst)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* pst, Elemtype v)
{
	//�������
	if(pst->size >= pst->capacity)
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

void SeqListInsertByPos(SeqList* pst, size_t pos, Elemtype v)
{
	//�������
	if(pst->size >= pst->capacity)
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

	}
}

Elemtype SeqListFindByPos(SeqList* pst, size_t pos)
{
	//���λ��
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}

size_t SeqListFindByVal(SeqList* pst, Elemtype v)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (pst->base[i] == v)
			return i;
	}
	return -1;
}

size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

void SeqListDestroy(SeqList* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->size = pst->capacity = 0;

}

void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}


#endif /*_SEQ_LIST_H_*/
