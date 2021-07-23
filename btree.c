#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}BNode;

//链式结构的创建
//ABD##E#H##CF##G##
BNode* creatBTree(DataType arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	else
	{
		//创建以当前数据为根的子树
		BNode* root = (BNode*)malloc(sizeof(BNode));
		if (root)
		{
			root->_data = arr[*idx];
			++(*idx);
			root->_left = creatBTree(arr, idx);
			root->_right = creatBTree(arr, idx);
			return root;
		}
	}
}

//前序遍历
void preOrder(BNode* root)
{
	//根 左子树 右子树
	if (root)
	{
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//中序遍历
void inOrder(BNode* root)
{
	//左子树 根 右子树
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//后序遍历
void postOrder(BNode* root)
{
	//左子树 右子树 根
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//二叉树中的节点个数
int bTreeSize(BNode* root)
{
	if (root == NULL)
		return 0;
	//root左子树的节点 + root右子树的节点 + 1
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}

void bTreeSize2(BNode* root, int* idx)
{
	if (root)
	{
		++(*idx);
		bTreeSize2(root->_left, idx);
		bTreeSize2(root->_right, idx);
	}
}

//计算叶子节点的个数
int bTreeLeafSize(BNode* root)
{
	//左右子树的叶子和
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//第k层节点的个数
int bTreeKSize(BNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//左右子树第k - 1节点个数和
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//查找某一个节点
BNode* bTreeFind(BNode* root, DataType ch)
{
	if (root == NULL)
		return NULL;
	if (root->_data == ch)
		return root;
	//左子树
	BNode* node = bTreeFind(root->_left, ch);
	if (node)
		return node;
	return bTreeFind(root->_right, ch);
}

//销毁
void bTreeDestroy(BNode** root)
{
	if (*root)
	{
		bTreeDestroy(&((*root)->_left));
		bTreeDestroy(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BNode* root = creatBTree(arr, &idx);
}

int main()
{
	test();
	return 0;
}