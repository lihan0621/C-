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

//函数声明
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

//函数实现

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

//初始化
void SeqListInit(SeqList* pst, size_t capacity)
{
	assert(pst != NULL);
	pst->capacity = capacity;
	pst->base = (Elemtype*)malloc(sizeof(Elemtype) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(Elemtype) * pst->capacity);
	pst->size = 0;
}

//尾插
void SeqListPushBack(SeqList* pst, Elemtype v)
{
	//检查容量
	if(_IsFull(pst) && !_AddCapacity(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	pst->base[pst->size++] = v;
}

//尾删
void SeqListPopBack(SeqList* pst)
{
	if(_IsEmpty(pst))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}

	//删除数据
	pst->size--;
}

//头删
void SeqListPopFront(SeqList* pst)
{
	if (_IsEmpty(pst))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}

	for (size_t i = 0; i < pst->size - 1; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

//打印
void SeqListShow(SeqList* pst)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

//头插
void SeqListPushFront(SeqList* pst, Elemtype v)
{
	//检查容量
	if(_IsFull(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	//移动数据
	for(int i=pst->size; i>0; --i)
	{
		pst->base[i] = pst->base[i-1];
	}
	//插入数据
	pst->base[0] = v;
	pst->size++;
}

//按位置插入
void SeqListInsertByPos(SeqList* pst, size_t pos, Elemtype v)
{
	//检查容量
	if(_IsFull(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	//检查位置
	if(pos < 0 || pos>pst->size)
	{
		printf("插入的位置非法， %d 不能插入.\n", v);
		return;
	}

	//插入数据
	for(size_t i = pst->size; i > pos; --i)
		pst->base[i] = pst->base[i-1];
	pst->base[pos] = v;
	pst->size++;
}

//按值插入
void SeqListInsertByVal(SeqList* pst, Elemtype v)
{
	//检查容量
	if(_IsFull(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	//寻找插入的位置
	size_t pos = 0;
	while (pos < pst->size && v > pst->base[pos])
		pos++;
	SeqListInsertByPos(pst, pos, v);

}

//按位置删除
void SeqListEraseByPos(SeqList* pst, size_t pos)
{
	//检查位置
	if(pos < 0 || pos>pst->size)
	{
		printf("删除的位置非法，不能删除数据\n");
		return;
	}
	for (size_t i = pos; i < pst->size - pos; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//按值删除
void SeqListEraseByVal(SeqList* pst, Elemtype key)
{
	int pos = 0;
	while (key != pst->base[pos])
		pos++;
	SeqListInsertByPos(pst, pos, key);
}

//按位置查找
Elemtype SeqListFindByPos(SeqList* pst, size_t pos)
{
	//检查位置
	assert(pos >= 0 && pos < pst->size);
	return pst->base[pos];
}

//按值查找
size_t SeqListFindByVal(SeqList* pst, Elemtype v)
{
	for (size_t i = 0; i < pst->size; ++i)
	{
		if (pst->base[i] == v)
			return i;
	}
	return -1;
}

//顺序表长度
size_t SeqListLength(SeqList* pst)
{
	return pst->size;
}

//顺序表容量
size_t SeqListCapacity(SeqList* pst)
{
	return pst->capacity;
}

//销毁顺序表
void SeqListDestroy(SeqList* pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->size = pst->capacity = 0;

}

//清空顺序表
void SeqListClear(SeqList* pst)
{
	pst->size = 0;
}

//排序
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

		if (!flag)  //没有交换过数据
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
