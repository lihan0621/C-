#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}BNode;

//��ʽ�ṹ�Ĵ���
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
		//�����Ե�ǰ����Ϊ��������
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

//ǰ�����
void preOrder(BNode* root)
{
	//�� ������ ������
	if (root)
	{
		printf("%c ", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}

//�������
void inOrder(BNode* root)
{
	//������ �� ������
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}

//�������
void postOrder(BNode* root)
{
	//������ ������ ��
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//�������еĽڵ����
int bTreeSize(BNode* root)
{
	if (root == NULL)
		return 0;
	//root�������Ľڵ� + root�������Ľڵ� + 1
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

//����Ҷ�ӽڵ�ĸ���
int bTreeLeafSize(BNode* root)
{
	//����������Ҷ�Ӻ�
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//��k��ڵ�ĸ���
int bTreeKSize(BNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//����������k - 1�ڵ������
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//����ĳһ���ڵ�
BNode* bTreeFind(BNode* root, DataType ch)
{
	if (root == NULL)
		return NULL;
	if (root->_data == ch)
		return root;
	//������
	BNode* node = bTreeFind(root->_left, ch);
	if (node)
		return node;
	return bTreeFind(root->_right, ch);
}

//����
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