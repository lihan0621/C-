#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include "Common.h"
#define StackElemType int
#define SEQSTACK_DEFAULT_SIZE 8


//顺序栈
typedef struct SeqStack
{
	StackElemType* base;
	size_t capacity;
	int top;
}SeqStack;


bool IsFull(SeqStack* pst)
{return pst->top >= pst->capacity;}
bool IsEmpty(SeqStack* pst)
{return pst->top == 0;}

void SeqStackInit(SeqStack* pst, int sz);
void SeqStackPush(SeqStack* pst, StackElemType x);
void SeqStackShow(SeqStack* pst);
void SeqStackPop(SeqStack* pst);
StackElemType SeqStackTop(SeqStack* pst);
void SeqStackDestory(SeqStack* pst);


void SeqStackInit(SeqStack* pst, int sz)
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
	pst->base = (StackElemType*)malloc(sizeof(SeqStack) * pst->capacity);
	assert(pst->base != NULL);
	pst->top = 0;
}

void SeqStackPush(SeqStack* pst, StackElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("栈已满，%d无法入栈\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("栈已空，无法出栈\n");
		return;
	}
	pst->top--;
}

StackElemType SeqStackTop(SeqStack* pst)
{
	assert(pst && !IsEmpty(pst));
	return pst->base[pst->top - 1]; 
}

void SeqStackShow(SeqStack* pst)
{
	assert(pst);
	for (int i = pst->top - 1; i >= 0; --i) 
	{
		printf("%d\n", pst->base[i]);
	}
}

void SeqStackDestory(SeqStack* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

////////////////////////////////////////////////////


//链栈
typedef struct LinkStackNode
{
	StackElemType data;
	struct LinkStackNode* next;
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

LinkStackNode* _BuyNode(StackElemType x)
{
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s);
	s->data = x;
	s->next = NULL;
	return s;
}

void LinkStackInit(LinkStack* pst);
void LinkStackPush(LinkStack* pst, StackElemType x);
void LinkStackPop(LinkStack* pst);
void LinkStackShow(LinkStack* pst);
StackElemType LinkStackTop(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);


void LinkStackInit(LinkStack* pst)
{pst->head = NULL;}

void LinkStackPush(LinkStack* pst, StackElemType x)
{
	assert(pst);
	LinkStackNode* p = _BuyNode(x);
	if (pst->head != NULL)
		p->next = pst->head;
	pst->head = p;
}

void LinkStackPop(LinkStack* pst)
{
	assert(pst);
	LinkStackNode* p = pst->head;
	if (p != NULL)
	{
		pst->head = p->next;
		free(p);
	}
}

StackElemType LinkStackTop(LinkStack* pst)
{
	assert(pst);
	if (pst->head == NULL)
		return;
	return pst->head->data;
}

void LinkStackDestroy(LinkStack* pst)
{
	assert(pst);
	while (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}


void LinkStackShow(LinkStack* pst)
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

#endif /* _STACK_H_ */
