#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define OK  1
#define ERROR 0
typedef struct Node{
	int ratio;//ϵ��
	int index;//ָ��
	struct Node *next;
} Node, *LinkList;
int InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(Node));
	if (L == NULL) return false;
	L->next = NULL;
	return OK;
}
int CreatList(LinkList &L){
	Node *p;
	Node *s;//ָ��β��
	int count;
	s = L;
	printf("���봴���ĸ���:");
	scanf_s("%d", &count);
	while (count != 0){
		p = (Node *)malloc(sizeof(Node));
		cout << "����ָ����ϵ��:";
		//scanf("%d %d", p->index, p->ratio);
		cin >> p->index >> p->ratio;

		s->next = p;
		s = p;

		count--;
	}
	s->next = NULL;
	return true;

}
int MergeList(LinkList &L1, LinkList &L2, LinkList &L3){
	Node *pa, *pb, *pc;
	pa = L1->next;
	pb = L2->next;
	L3 = pc = L1;
	while (pa != NULL&&pb != NULL){
		if (pa->index<pb->index){
			pc->next = pa;
			pc = pa;
			pa = pa->next;

		}
		if (pb->index<pa->index){
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		if (pa->index == pb->index){//ϵ����ͬ
			if (pa->ratio + pb->ratio != 0){
				pa->ratio = pa->ratio + pb->ratio;
				pc->next = pa;
				pc = pa;
				pa = pa->next;
				pb = pb->next;

			}
			else{
				pa = pa->next;
				pb = pb->next;
			}

		}
	}
	while (pa != NULL){
		pc->next = pa;
		pc = pa;
		pa = pa->next;
	}
	while (pb != NULL){
		pc->next = pb;
		pc = pb;
		pb = pb->next;
	}
	return true;

}
void Print(LinkList &L){
	Node *p;
	p = L->next;
	while (p != NULL){
		if (p->index == 0){
			printf("%d+", p->ratio);//cout<<p->ratio<<"+";
		}
		else if (p->next == NULL){
			printf("%dx^%d", p->ratio, p->index);
		}//cout<<p->ratio<<"x^"<<p->index;
		else{
			printf("%dx^%d+", p->ratio, p->index);//cout<<p->ratio<<"x^"<<p->index<<"+";
		}
		p = p->next;
	}

	printf("\n");

}
int main(){

	LinkList L1, L2, L3;


	InitList(L1);//��ʼ��
	InitList(L2);
	CreatList(L1);//��������
	Print(L1);//����
	CreatList(L2);
	Print(L2);

	MergeList(L1, L2, L3);//�ϲ�ͬ����
	Print(L3);
	system("pause");
	return 0;




}

