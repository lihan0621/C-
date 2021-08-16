#pragma once
#ifndef _DCLIST_H_
#define _DCLIST_H_

#include "Common.h"

typedef struct DCListNode
{
	Elemtype data;
	struct DCListNode* prev;
	struct DCListNode* next;
}DCListNode;

typedef struct DCList
{
	DCListNode* head;
}DCList;

//函数声明
DCListNode* _creatNode(Elemtype v);
void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist, Elemtype v);
void DCListPushFront(DCList* plist, Elemtype v);
void DCListPopBack(DCList* plist);
void DCListPopFront(DCList* plist);
void DCListShow(DCList* plist);
void DCListInsertByVal(DCList* plist, Elemtype v);
DCListNode* DCListFind(DCList* plist, Elemtype key);
void DCListEraseByVal(DCList* plist, Elemtype key);
void DCListSort(DCList* plist);
int DCListLength(DCList* plist);
void DCListClear(DCList* plist);
void DCListReverse(DCList* plist);
void DCListDestroy(DCList* plist);



//函数实现
DCListNode* _creatNode(Elemtype v)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = v;
	s->next = s->prev = s;
	return s;
}

void DCListInit(DCList* plist)
{
	plist->head = _creatNode(-1);
}

void DCListPushBack(DCList* plist, Elemtype v)
{
	//创建一个新节点
	DCListNode* s = _creatNode(v);

	//构造新的连接
	s->next = plist->head;
	s->prev = plist->head->prev;
	s->next->prev = s;
	s->prev->next = s;
}

void DCListPushFront(DCList* plist, Elemtype v)
{
	//创建新节点
	DCListNode* s = _creatNode(v);

	s->next = plist->head->next;
	s->prev = plist->head;
	s->next->prev = s;
	s->prev->next = s;
}

void DCListPopBack(DCList* plist)
{
	if (plist->head->next == plist->head)
		return;
	DCListNode* p = plist->head->prev;
	p->prev->next = plist->head;
	plist->head->prev = p->prev;
	free(p);
}

void DCListPopFront(DCList* plist)
{
	if (plist->head->next == plist->head)
		return;
	DCListNode* p = plist->head->next;
	p->next->prev = plist->head;
	plist->head->next = p->next;
	free(p);
}

void DCListShow(DCList* plist)
{
	if (plist->head->next == plist->head)
		return;
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void DCListInsertByVal(DCList* plist, Elemtype v)
{
	//创建节点
	DCListNode* s = _creatNode(v);

	DCListNode* p = plist->head->next;
	while (p != plist->head && v > p->data)
		p = p->next;

	s->next = p;
	s->prev = p->prev;
	s->next->prev = s;
	s->prev->next = s;
}

DCListNode* DCListFind(DCList* plist, Elemtype key)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && p->data != key)
		p = p->next;

	if (p == plist->head)
		return NULL;
	else
		return p;
}

void DCListEraseByVal(DCList* plist, Elemtype key)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head && p->data != key)
		p = p->next;
	if (p == plist->head)
		return;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}

void DCListSort(DCList* plist)
{
	if (plist->head->next == plist->head)
		return;
	DCListNode* p = plist->head->next->next;
	DCListNode* prev = plist->head->prev;

	//截断链表
	plist->head->next->next = plist->head;
	plist->head->prev = plist->head->next;

	prev->next = p;
	p->prev = prev;

	DCListNode* nq = p;
	while (p->next != p)
	{
		DCListNode* q = p->next;
		if (p->data < plist->head->next->data)
		{
			p->next = plist->head->next;
			p->prev = plist->head;
			p->next->prev = p;
			p->prev->next = p;
		}
		else
		{
			DCListNode* np = plist->head->next;
			while (np->next != plist->head && p->data > np->next->data)
				np = np->next;
			p->prev = np->next->prev;
			p->next = np->next;
			p->next->prev = p;
			p->prev->next = p;
		}
		p = q;
		if(p == nq)
			break;
	}
}

void DCListReverse(DCList* plist)
{
	if (plist->head->next == plist->head)
		return;
	DCListNode* p = plist->head->next->next;
	DCListNode* next = plist->head->next;

	plist->head->prev = next;
	next->next = plist->head;

	while (p != plist->head)
	{
		DCListNode* q = p->next;
		p->prev = plist->head;
		p->next = next;
		p->prev->next = p;
		p->next->prev = p;
		next = p;
		p = q;
	}
}

int DCListLength(DCList* plist)
{
	DCListNode* p = plist->head->next;
	int len = 0;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}

void DCListClear(DCList* plist)
{
	DCListNode* p = plist->head->next;
	while (p != plist->head)
	{
		DCListNode* next = p->next;
		free(p);
		p = next;
	}
	free(plist->head);
}

void DCListDestroy(DCList* plist)
{
	DCListClear(plist);
}






#endif /* _DCLIST_H_ */
