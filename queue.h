#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

typedef BNode* QDataType;

typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
} QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
} Queue;

void queueInit(Queue* q);
QNode* creatNode(QDataType data);
//队尾入队
void queuePush(Queue* q, QDataType data);
//队头出队
void queuePop(Queue* q);
//获取队头元素
QDataType queueFront(Queue* q);
//获取队尾元素
QDataType queueBack(Queue* q);
int queueSize(Queue* q);
int queueEmpty(Queue* q);
void queueDestory(Queue* q);