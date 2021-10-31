#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Common.h"
#define QueueElemType int

//链队列
typedef struct LinkQueueNode
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail; //指向队尾节点
}LinkQueue;

LinkQueueNode* _BuyQueueNode(QueueElemType x)
{
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
}

void LinkQueueInit(LinkQueue* qu);
void LinkQueuePush(LinkQueue* qu, QueueElemType x);
void LinkQueuePop(LinkQueue* qu);
void LinkQueueShow(LinkQueue* qu);
void LinkQueueDestroy(LinkQueue* qu);
QueueElemType LinkQueueBack(LinkQueue* qu);
QueueElemType LinkQueueFront(LinkQueue* qu);



void LinkQueueInit(LinkQueue* qu)
{
	assert(qu);
	qu->head = qu->tail = NULL;
}

void LinkQueuePush(LinkQueue* qu, QueueElemType x)
{
	assert(qu);
	LinkQueueNode* s = _BuyQueueNode(x);

	/*
	LinkQueueNode* p = qu->head;
	if (qu->head == NULL)
		qu->head = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
	*/

	if (qu->head == NULL)
		qu->head = qu->tail = s;
	else
		qu->tail->next = s;
	qu->tail = s;
}

void LinkQueuePop(LinkQueue* qu)
{
	assert(qu);
	if (qu->head != NULL)
	{
		LinkQueueNode* p = qu->head;
		qu->head = p->next;
		if (qu->head == NULL)
			qu->tail = NULL;
		free(p);
	}
}

QueueElemType LinkQueueBack(LinkQueue* qu)
{
	assert(qu && qu->head);
	return qu->tail;
}

QueueElemType LinkQueueFront(LinkQueue* qu)
{
	assert(qu && qu->head);
	return qu->head;
}

void LinkQueueShow(LinkQueue* qu)
{
	assert(qu);
	LinkQueueNode* p = qu->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void LinkQueueDestroy(LinkQueue* qu)
{
	assert(qu);
	while (qu->head != NULL)
	{
		LinkQueueNode* p = qu->head;
		qu->head = p->next;
		free(p);
	}
	qu->head = qu->tail = NULL;
}



/////////////////////////////////////////////////////////////////////////////

//顺序队列 ---> 循环队列
#define QUEUE_DEFAULT_SIZE 8

typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int front;
	int rear;
}SeqQueue;

void SeqQueueInit(SeqQueue* sq, int sz);
void SeqQueueDestroy(SeqQueue* sq);
void SeqQueuePush(SeqQueue* sq, QueueElemType x);
void SeqQueuePop(SeqQueue* sq);
QueueElemType SeqQueueBack(SeqQueue* sq);
QueueElemType SeqQueueFront(SeqQueue* sq);
void SeqQueueShow(SeqQueue* sq);





void SeqQueueInit(SeqQueue* sq, int sz)
{
	assert(sq);
	sq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	sq->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (sq->capacity + 1));
	assert(sq->base);
	sq->front = sq->rear = 0;
}

void SeqQueuePush(SeqQueue* sq, QueueElemType x)
{
	assert(sq);
	if ((sq->rear + 1) % (sq->capacity + 1) == sq->front)
	{
		printf("队列已满，不能入队\n");
		return;
	}
	sq->base[sq->rear] = x;
	sq->rear = (sq->rear + 1) % (sq->capacity + 1);
}

void SeqQueuePop(SeqQueue* sq)
{
	assert(sq);
	if (sq->front == sq->rear)
	{
		printf("队列已空，不能出队\n");
		return;
	}
	sq->front = (sq->front + 1) % (sq->capacity + 1);
}

QueueElemType SeqQueueBack(SeqQueue* sq)
{
	assert(sq && sq->front != sq->rear);
	return sq->base[((sq->rear - 1) + (sq->capacity + 1)) % (sq->capacity + 1)];
}

QueueElemType SeqQueueFront(SeqQueue* sq)
{
	assert(sq && sq->front != sq->rear);
	return sq->base[sq->front];
}

void SeqQueueDestroy(SeqQueue* sq)
{
	assert(sq);
	free(sq->base);
	sq->base = NULL;
	sq->capacity = sq->front = sq->rear = 0;
}


void SeqQueueShow(SeqQueue* sq)
{
	assert(sq);
	for (int i = sq->front; i != sq->rear;) 
	{
		printf("%d\n", sq->base[i]);
		i = (i + 1) % (sq->capacity + 1);
	}
}



#endif /* _QUEUE_H_ */
