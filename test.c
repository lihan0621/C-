#include <stdio.h>

typedef int LDataType;

//˫���ͷѭ���б�Ľڵ�
typedef struct ListNode {
	LDataType _data;
	//ָ����һ���ڵ����ʼλ��
	struct ListNode* _next;
	//ָ����һ���ڵ����ʼλ��
	struct ListNode* _prev;
}ListNode;

//˫���ͷѭ������
typedef struct List {
	struct ListNode* _head;
}List;

//�����ڵ�
struct ListNode* createListNode(LDataType val) {
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

//��ʼ������
void ListInit(List* lst) {
	if (lst == NULL)
		return;
	//������
	lst->_head = createListNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}

//β��
void listPushBack(List* lst, LDataType val) {
	/*	
	if (lst == NULL)
		return;
	struct ListNode* last = lst->_head->_prev;
	struct ListNode* newNode = createListNode(val);
	//head ...... last newNode
	last->_next = newNode;
	newNode->_prev = last;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
	*/

	listInsert(&lst, lst->_head, val);
}

//βɾ
void listPopBack(List* lst) {
	/*
	if (lst == NULL)
		return;
	if (lst->_head->_next == lst->_head)
		return;
	struct ListNode* last = lst->_head->_prev;
	struct ListNode* prev = last->_prev;
	free(last);
	lst->_head->_prev = prev;
	prev->_next = lst->_head;
	*/
	listErase(lst, lst->_head->_prev);
}

//���
void printlist(List* lst) {
	struct ListNode* cur = lst->_head->_next;
	while (cur != lst->_head) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//ͷ��
void listPushFront(List* lst, LDataType val) {
	/*
	if (lst == NULL)
		return;
	struct ListNode* next = lst->_head->_next;
	struct ListNode* newNode = createListNode(val);
	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	newNode->_next = next;
	next->_prev = newNode;
	*/
	listInsert(lst, lst->_head->_next, val);
}

//ͷɾ
void listPopFront(List* lst) {
	/*
	if (lst == NULL || lst->_head->_next == lst->_head)
		return;
	struct ListNode* next = lst->_head->_next;
	struct ListNode* nextnext = next->_next;
	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;
	free(next);
	*/
	listErase(lst, lst->_head->_next);
}

//ɾ������λ�õĽڵ�
void listErase(List* lst, struct ListNode* node) {
	if (lst == NULL || node == lst->_head)
		return;
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;
	prev->_next = next;
	next->_prev = prev;
	free(node);
}

//�ڵ�ǰ�ڵ�֮ǰ�����½ڵ�
void listInsert(List* lst, struct ListNode* node, LDataType val) {
	if (lst == NULL)
		return;
	struct ListNode* prev = node->_prev;
	struct ListNode* newNode = createListNode(val);
	// prev  newNode  node
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = node;
	node->_prev = newNode;
}

//����
listDestroy(List* lst) {
	if (lst) {
		if (lst->_head) {
			struct ListNode* cur = lst->_head->_next;
			while (cur != lst->_head) {
				struct ListNode* next = cur->_next;
				free(cur);
				cur = next;
			}
			free(lst->_head);
		}
	}
}