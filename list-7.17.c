#include <stdio.h>

typedef int LDataType;

typedef struct listNode {
	LDataType _data;
	struct listNode* _next;//下一个数据的存放位置
}listNode;
typedef struct list {
	//存放第一个节点的地址
	listNode* _head;
}list;

void initList(list* lst) {
	if (lst == NULL)
		return;
	//初始化为空的链表
	lst->_head = NULL;
}

listNode* creatNode(LDataType val) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//尾插
void listPushBack(list* lst, LDataType val) {
	if (lst == NULL)
		return;
	//第一种: 空链表插入第一个数据
	if (lst->_head == NULL) {
		//创建节点
		lst->_head = creatNode(val);
	}
	else {
		//遍历, 找到最后一个节点
		listNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//插入
		tail->_next = creatNode(val);
	}
}

//尾删
void listPopBack(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* tail = lst->_head;
	listNode* prev = NULL;
	//遍历, 找到最后一个节点
	while (tail->_next != NULL) {
		prev = tail;
		tail = tail->_next;
	}
	//删除节点
	free(tail);
	//修改指向
	if (prev == NULL)//删除的为头结点, 更新头结点
		lst->_head = NULL;	
	else
		prev->_next = NULL;
}

//头插
void listPushFront(list* lst, LDataType val) {
	if (lst == NULL)
		return;
	//空的链表插入第一个数据
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else {		//非空的链表
		listNode* node = creatNode(val);
		listNode* next = lst->_head->_next;
		//head, node, next重新做一个连接
		lst->_head = node;
		node->_next = next;
	}
}

//头删
void listPopFront(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* next = lst->_head->_next;
	//释放头结点
	free(lst->_head);
	lst->_head = next;
}

//给中间插入数据
void listInsertAfter(listNode* cur, LDataType val) {
	listNode* node = creatNode(val);
	listNode* next = cur->_next;
	//  cur   node   next
	cur->_next = node;
	node->_next = next;
}

//删除当前节点后面的位置
void listEraseAfter(listNode* cur) {
	//cur next next->next
	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

//查找
void listFind(list* lst, LDataType val) {
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* cur = lst->_head;
	while (cur) {
		if (cur->_data == val)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

//释放
void listDestroy(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	//从第一个节点开始释放
	listNode* cur = lst->_head;
	while (cur) {
		listNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;
}

void test() {
	list lst;
	initList(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
}

int main() {
	test();
	return 0;
}
