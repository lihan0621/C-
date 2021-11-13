#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#pragma warning(disable:6031)
#include "Common.h"

#define  TreeElemType char

//定义树形节点
typedef struct BinTreeNode
{
	TreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

//定义树形结构
typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree* t);
void BinTreeCreat_1(BinTree* t);
BinTree BinTreeCreat_2();
BinTree BinTreeCreat_3(const char* str, int* i);

BinTree BinTreeCreat_VLR_LVR(const char* vlr, const char* lvr, int n);
BinTree BinTreeCreat_LVR_LRV(const char* lvr, const char* lrv, int n);

//递归遍历
void PreOrder(BinTree t);
void IndOrder(BinTree t);
void PostOrder(BinTree t);
void LevelOrder(BinTree t);

//非递归遍历
void PreOrder_Nor(BinTree t);
void IndOrder_Nor(BinTree t);
void PostOrder_Nor(BinTree t);


size_t Size(BinTree t);
size_t Height(BinTree t);
BinTreeNode* Find(BinTree t, TreeElemType key);
BinTreeNode* Parent(BinTree t, BinTreeNode* s);
BinTree Clone(BinTree t);
bool Equal(BinTree t1, BinTree t2);

void BinTreeInit(BinTree* t)
{
	*t = NULL;
}

void BinTreeCreat_1(BinTree* t)
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreat_1(&((*t)->leftChild));
		BinTreeCreat_1(&((*t)->rightChild));
	}
}

BinTree BinTreeCreat_2()
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreat_2();
		t->rightChild = BinTreeCreat_2();
		return t;
	}
}

BinTree BinTreeCreat_3(const char* str, int* i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*i];
		(*i)++;
		t->leftChild = BinTreeCreat_3(str, i);
		(*i)++;
		t->rightChild = BinTreeCreat_3(str, i);
		return t;

	}
}


BinTree BinTreeCreat_VLR_LVR(const char* vlr, const char* lvr, int n)
{
	if (n == 0)
		return NULL;

	int k = 0;
	while (lvr[k] != vlr[0])
		++k;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = lvr[k];

	t->leftChild = BinTreeCreat_VLR_LVR(vlr + 1, lvr, k);
	t->rightChild = BinTreeCreat_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);

	return t;
}

BinTree BinTreeCreat_LVR_LRV(const char* lvr, const char* lrv, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lvr[k] != lrv[n - 1])
		++k;

	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = lvr[k];

	t->rightChild = BinTreeCreat_LVR_LRV(lvr + k + 1, lrv + k, n - k - 1);
	t->leftChild = BinTreeCreat_LVR_LRV(lvr, lrv, k);

	return t;
}

void PreOrder(BinTree t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}

void IndOrder(BinTree t)
{
	if (t != NULL)
	{
		IndOrder(t->leftChild);
		printf("%c ", t->data);
		IndOrder(t->rightChild);
	}
}

void PostOrder(BinTree t)
{
	if (t != NULL)
	{
		PostOrder(t->leftChild);
		PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}

#include "Stack.h"
void PreOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack s;
		LinkStackInit(&s);

		LinkStackPush(&s, t);
		while (!LinkStackEmpty(&s))
		{
			BinTreeNode* p = LinkStackTop(&s);
			LinkStackPop(&s);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				LinkStackPush(&s, p->rightChild);
			if (p->leftChild != NULL)
				LinkStackPush(&s, p->leftChild);
		}
	}
}

/*
void IndOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack s;
		LinkStackInit(&s);

		while (t || !LinkStackEmpty(&s))
		{
			while (t)
			{
				LinkStackPush(&s, t);
				t = t->leftChild;
			}
			BinTreeNode* p = LinkStackTop(&s);
			LinkStackPop(&s);
			printf("%c ", p->data);

			t = p->rightChild;
		}
	}
}
*/

void IndOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack s;
		LinkStackInit(&s);

		LinkStackPush(&s, t);
		while (!LinkStackEmpty(&s))
		{
			while (t && t->leftChild != NULL)
			{
				LinkStackPush(&s, t->leftChild);
				t = t->leftChild;
			}

			BinTreeNode* p = LinkStackTop(&s);
			LinkStackPop(&s);
			printf("%c ", p->data);

			t = p->rightChild;
			if (t != NULL)
				LinkStackPush(&s, t);
		}
	}
}


void PostOrder_Nor(BinTree t)
{
	if (t != NULL)
	{
		LinkStack s;
		LinkStackInit(&s);

		BinTreeNode* p, *prev = NULL;    //prev代表当前节点的前驱访问节点 
		while (t || !LinkStackEmpty(&s))
		{
			while (t)
			{
				LinkStackPush(&s, t);
				t = t->leftChild;
			}

			p = LinkStackTop(&s);
			if (p->rightChild == NULL || p->rightChild == prev)
			{
				printf("%c ", p->data);
				LinkStackPop(&s);   //要访问
				prev = p;    //更新prev访问节点 
			}
			else
				t = p->rightChild; 
		}
	}
}

#include "Queue.h"
void LevelOrder(BinTree t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueuePush(&Q, t);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q);
			LinkQueuePop(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueuePush(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueuePush(&Q, p->rightChild);
		}
	}
}

size_t Size(BinTree t)
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}


size_t Height(BinTree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = Height(t->leftChild);
		int right_h = Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
		//return Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) + 1 : Height(t->rightChild) + 1; 
}

BinTreeNode* Find(BinTree t, TreeElemType key)
{
	if (t == NULL || t->data == key)
		return t;
	BinTreeNode* p = Find(t->leftChild, key);
	if (p != NULL)   //说明左树找到了
		return p;
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s)
{
	if (t == NULL || t == s)  //t==s是用于判断是否求的是根节点的父节点
		return NULL;
	if (t->leftChild == s || t->rightChild == s)
		return t;
	BinTreeNode* p = Parent(t->leftChild, s);
	if (p != NULL)
		return p;
	return Parent(t->rightChild, s);

}

BinTree Clone(BinTree t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode* new_t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(new_t != NULL);
		new_t->data = t->data;
		new_t->leftChild = Clone(t->leftChild);
		new_t->rightChild = Clone(t->rightChild);
		return new_t;
	}
}

bool Equal(BinTree t1, BinTree t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->data == t2->data) 
		&& Equal(t1->leftChild, t2->leftChild) 
		&& Equal(t1->rightChild, t2->rightChild);
}

#endif /* _TREE_H_ */
#pragma once
