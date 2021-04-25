#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
#define MAXSIZE 100

typedef struct snode
{
	int data;
	int next;//���ָ��(�±�)
}snode, slink[MAXSIZE];

//snode arr[MAXSIZE];//����Ϊmaxsize�ṹ������
//typedef snode Arr[MAXSIZE];//����Ϊmaxsize�ṹ����������
//Arr a;//a�ǳ���Ϊmaxsize�Ľṹ������
//���һ�����нڵ�������Ŀ�����ò�������ʱ�ҿ��нڵ���ٶȱ�ΪO��1��

void initlink(snode* sq)
{
	assert(sq != NULL);
	//if (sq == NULL);
	//
	//	return;
	
	sq[0].next = 0;//0�±�Ϊ��Ч��������ı�ͷ���Ҹ���Ϊѭ������
	for (int i = 1; i < MAXSIZE; i++)//��������б�
	{
		sq[i].next = i + 1;
	}
	sq[MAXSIZE - 1].next = 1;//1�±�Ϊ�����б�ı�ͷ
}

static bool Isfull(snode* sq)
{
	return sq[1].next == 1;
}

bool Isempty(snode* sq)
{
	return sq[0].next == 0;//��Ч����û�����ݽڵ�
}

bool Insert_head(snode* sq, int val)
{
	if (Isfull(sq))
		return false;
	//��ȡһ����������ĵ�һ���ڵ�
	int p = sq[1].next;

	//�����нڵ�ӿ����б����޳�
	sq[1].next = sq[p].next;
	//��������
	sq[p].data = val;
	//�����нڵ���뵽��Ч��������
	sq[p].next = sq[0].next;
	sq[0].next = p;
	//�±������ź�ָ���Դ�������
	return true;
}

void show(snode* sq)
{
	for (int p = sq[0].next; p != 0;)//0����������ͷ����±�
	{
		printf("%d ", sq[p].data);
	}
}

int main()
{
	slink s;//sΪ��������������
	initlink(s);
	for (int i = 0; i < 10; i++)
	{
		Insert_head(s, i);
	}
	show(s);

	return 0;
}
