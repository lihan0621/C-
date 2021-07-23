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
//��β���
void queuePush(Queue* q, QDataType data);
//��ͷ����
void queuePop(Queue* q);
//��ȡ��ͷԪ��
QDataType queueFront(Queue* q);
//��ȡ��βԪ��
QDataType queueBack(Queue* q);
int queueSize(Queue* q);
int queueEmpty(Queue* q);
void queueDestory(Queue* q);