#pragma once
#ifndef _SCLIST_H_
#define _SCLIST_H_

#include "Common.h"

typedef struct SCListNode
{
	Elemtype data;
	struct SCListNode* next;
}SCListNode;

typedef struct SCList
{
	SCListNode* phead;
}SCList;

//函数声明
void SCListInit(SCList* plist);
void SCListPushBack(SCList* plist, Elemtype v);
void SCListPushFront(SCList* plist, Elemtype v);
void SCListPopFront(SCList* plist);
void SCListShow(SCList* plist);




//函数实现
void SCListInit(SCList* plist)
{
	plist->phead = NULL;
}

void SCListPushBack(SCList* plist, Elemtype v)
{
	SCListNode* s = (SCListNode*)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;
	if (plist->phead == NULL)
	{
		plist->phead = s;
		plist->phead->next = plist->phead;
		return;
	}
	SCListNode* p = plist->phead;
	while (p->next != plist->phead)
		p = p->next;
	p->next = s;
	s->next = plist->phead;
}

void SCListPushFront(SCList* plist, Elemtype v)
{
	SCListNode* s = (SCListNode*)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;

	if (plist->phead == NULL)
	{
		plist->phead = s;
		plist->phead->next = plist->phead;
		return;
	}
	SCListNode* p = plist->phead;
	while (p->next != plist->phead)
		p = p->next;
	s->next = plist->phead;
	p->next = s;
	plist->phead = s;
}

void SCListPopFront(SCList* plist)
{
	if (plist->phead == NULL)
		return;
	SCListNode* p = plist->phead;
	while (p->next != plist->phead)
		p = p->next;
	plist->phead = plist->phead->next;
	p->next = plist->phead;
}

void SCListShow(SCList* plist)
{
	SCListNode* p = plist->phead;
	while (p->next != plist->phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d->Over.\n", p->data);
}



#endif /* _SCLIST_H_ */
