#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#define MAXSIZE 100

typedef struct snode
{
	int data;
	int next;//后继指针(下标)
}snode, slink[MAXSIZE];

//snode arr[MAXSIZE];//长度为maxsize结构体数组
//typedef snode Arr[MAXSIZE];//长度为maxsize结构体数组类型
//Arr a;//a是长度为maxsize的结构体数组
//添加一条空闲节点的链表的目的是让插入数据时找空闲节点的速度变为O（1）

void initlink(snode* sq)
{
	assert(sq != NULL);
	//if (sq == NULL);
	//
	//	return;
	
	sq[0].next = 0;//0下标为有效数据链表的表头，且该链为循环链表
	for (int i = 1; i < MAXSIZE; i++)//处理空闲列表
	{
		sq[i].next = i + 1;
	}
	sq[MAXSIZE - 1].next = 1;//1下标为空闲列表的表头
}

static bool Isfull(snode* sq)
{
	return sq[1].next == 1;
}

bool Isempty(snode* sq)
{
	return sq[0].next == 0;//有效链表没有数据节点
}

bool Insert_head(snode* sq, int val)
{
	if (Isfull(sq))
		return false;
	//获取一个空闲链表的第一个节点
	int p = sq[1].next;

	//将空闲节点从空闲列表中剔除
	sq[1].next = sq[p].next;
	//放入数据
	sq[p].data = val;
	//将空闲节点插入到有效数据链中
	sq[p].next = sq[0].next;
	sq[0].next = p;
	//下标中括号和指向自带解引用
	return true;
}

void show(snode* sq)
{
	for (int p = sq[0].next; p != 0;)//0是优先链的头结点下标
	{
		printf("%d ", sq[p].data);
	}
}

int main()
{
	slink s;//s为整个链表数组名
	initlink(s);
	for (int i = 0; i < 10; i++)
	{
		Insert_head(s, i);
	}
	show(s);

	return 0;
}
