#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#pragma warning(disable:6031)
#include "Common.h"

#define  TreeElemType char

//�������νڵ�
typedef struct BinTreeNode
{
	TreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

//�������νṹ
typedef BinTreeNode* BinTree;

void BinTreeCreat(BinTree* t);


void BinTreeCreat(BinTree* t)
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
		BinTreeCreat(&((*t)->leftChild));
		BinTreeCreat(&((*t)->rightChild));
	}
}




#endif /* _TREE_H_ */
