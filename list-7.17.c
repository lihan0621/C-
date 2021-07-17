#include <stdio.h>

typedef int LDataType;

typedef struct listNode {
	LDataType _data;
	struct listNode* _next;//��һ�����ݵĴ��λ��
}listNode;
typedef struct list {
	//��ŵ�һ���ڵ�ĵ�ַ
	listNode* _head;
}list;

void initList(list* lst) {
	if (lst == NULL)
		return;
	//��ʼ��Ϊ�յ�����
	lst->_head = NULL;
}

listNode* creatNode(LDataType val) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}

//β��
void listPushBack(list* lst, LDataType val) {
	if (lst == NULL)
		return;
	//��һ��: ����������һ������
	if (lst->_head == NULL) {
		//�����ڵ�
		lst->_head = creatNode(val);
	}
	else {
		//����, �ҵ����һ���ڵ�
		listNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}
		//����
		tail->_next = creatNode(val);
	}
}

//βɾ
void listPopBack(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* tail = lst->_head;
	listNode* prev = NULL;
	//����, �ҵ����һ���ڵ�
	while (tail->_next != NULL) {
		prev = tail;
		tail = tail->_next;
	}
	//ɾ���ڵ�
	free(tail);
	//�޸�ָ��
	if (prev == NULL)//ɾ����Ϊͷ���, ����ͷ���
		lst->_head = NULL;	
	else
		prev->_next = NULL;
}

//ͷ��
void listPushFront(list* lst, LDataType val) {
	if (lst == NULL)
		return;
	//�յ���������һ������
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else {		//�ǿյ�����
		listNode* node = creatNode(val);
		listNode* next = lst->_head->_next;
		//head, node, next������һ������
		lst->_head = node;
		node->_next = next;
	}
}

//ͷɾ
void listPopFront(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	listNode* next = lst->_head->_next;
	//�ͷ�ͷ���
	free(lst->_head);
	lst->_head = next;
}

//���м��������
void listInsertAfter(listNode* cur, LDataType val) {
	listNode* node = creatNode(val);
	listNode* next = cur->_next;
	//  cur   node   next
	cur->_next = node;
	node->_next = next;
}

//ɾ����ǰ�ڵ�����λ��
void listEraseAfter(listNode* cur) {
	//cur next next->next
	listNode* next = cur->_next;
	if (next == NULL)
		return;
	listNode* nextnext = next->_next;
	free(next);
	cur->_next = nextnext;
}

//����
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

//�ͷ�
void listDestroy(list* lst) {
	if (lst == NULL || lst->_head == NULL)
		return;
	//�ӵ�һ���ڵ㿪ʼ�ͷ�
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
