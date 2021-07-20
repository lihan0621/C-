#include <stdio.h>

typedef int LDataType;

//双向带头循环列表的节点
typedef struct ListNode {
	LDataType _data;
	//指向下一个节点的起始位置
	struct ListNode* _next;
	//指向上一个节点的起始位置
	struct ListNode* _prev;
}ListNode;

//双向带头循环链表
typedef struct List {
	struct ListNode* _head;
}List;

//创建节点
struct ListNode* createListNode(LDataType val) {
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

//初始化链表
void ListInit(List* lst) {
	if (lst == NULL)
		return;
	//空链表
	lst->_head = createListNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}

//尾插
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

//尾删
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

//输出
void printlist(List* lst) {
	struct ListNode* cur = lst->_head->_next;
	while (cur != lst->_head) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//头插
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

//头删
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

//删除任意位置的节点
void listErase(List* lst, struct ListNode* node) {
	if (lst == NULL || node == lst->_head)
		return;
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;
	prev->_next = next;
	next->_prev = prev;
	free(node);
}

//在当前节点之前插入新节点
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

//销毁
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