#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define OK  1
#define ERROR 0
typedef struct Node{
	int ratio;//系数
	int index;//指数
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
	Node *s;//指向尾部
	int count;
	s = L;
	printf("输入创建的个数:");
	scanf_s("%d", &count);
	while (count != 0){
		p = (Node *)malloc(sizeof(Node));
		cout << "输入指数和系数:";
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
		if (pa->index == pb->index){//系数相同
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


	InitList(L1);//初始化
	InitList(L2);
	CreatList(L1);//创建链表
	Print(L1);//遍历
	CreatList(L2);
	Print(L2);

	MergeList(L1, L2, L3);//合并同类项
	Print(L3);
	system("pause");
	return 0;




}

