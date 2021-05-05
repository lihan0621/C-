#define  _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct node
//{
//	float coef;   //系数 
//	int expn;     //指数 
//	struct node *next;
//}PolyNode;      //多项式节点 polynomial node 
//typedef PolyNode* Polynomial;
//Polynomial createPolynomial()   //创建多项式 
//{
//	PolyNode *p, *q, *head = (PolyNode *)malloc(sizeof(PolyNode));   //头节点 
//	head->next = NULL;
//	float coef;
//	int expn;
//	while (scanf("%f %d", &coef, &expn) && coef)    // 默认，按指数递减排列 
//	{
//		if (head->next)
//		{
//			p = head;
//			while (p->next && expn < p->next->expn)
//				p = p->next;
//			if (p->next)
//			{
//				if (expn == p->next->expn)  //有相同指数的直接把系数加到原多项式 
//				{
//					p->next->coef += coef;
//					//若是相加后系数为0，则舍弃该节点 
//					if (p->next->coef > -0.000001 && p->next->coef < 0.000001)
//					{
//						q = p->next;
//						p->next = q->next;
//						free(q);
//					}
//				}
//				else
//				{
//					q = (PolyNode*)malloc(sizeof(PolyNode));
//					q->coef = coef;
//					q->expn = expn;
//					q->next = p->next;
//					p->next = q;
//				}
//			}
//			else
//			{
//				p->next = (PolyNode*)malloc(sizeof(PolyNode));
//				p = p->next;
//				p->coef = coef;
//				p->expn = expn;
//				p->next = NULL;
//			}
//		}
//		else
//		{
//			head->next = (PolyNode*)malloc(sizeof(PolyNode));
//			head->next->coef = coef;
//			head->next->expn = expn;
//			head->next->next = NULL;
//		}
//	}
//	return head;
//}
////多项式与指定单项式相乘，该单项式为 coefx^expn 
//Polynomial multiply(Polynomial poly, float coef, int expn)
//{
//	PolyNode *p, *q, *Poly = (PolyNode*)malloc(sizeof(PolyNode));
//	p = Poly;
//	q = poly->next;
//	while (q)
//	{
//		p->next = (PolyNode*)malloc(sizeof(PolyNode));
//		p = p->next;
//		p->coef = (q->coef*coef);
//		p->expn = (q->expn + expn);
//		q = q->next;
//	}
//	p->next = NULL;
//	return Poly;
//}
//void add(Polynomial poly1, Polynomial poly2)   //把 poly2 加到 poly1 上
//{
//	PolyNode *p, *q, *r;
//	r = poly1;
//	p = poly1->next;  //指向第一个节点
//	q = poly2->next;
//	poly2->next = NULL;
//	while (p && q)
//	{
//		if (p->expn > q->expn)
//		{
//			r->next = p;
//			p = p->next;
//			r = r->next;
//		}
//		else if (p->expn < q->expn)
//		{
//			r->next = q;
//			q = q->next;
//			r = r->next;
//		}
//		else
//		{
//			PolyNode *t;
//			p->coef += q->coef;
//			if (!(p->coef > -0.000001 && p->coef < 0.000001)) //系数不为0
//			{
//				r->next = p;
//				r = r->next;
//				p = p->next;
//			}
//			else
//			{
//				t = p;
//				p = p->next;
//				free(t);
//			}
//			t = q;
//			q = q->next;
//			free(t);
//		}
//	}
//	if (p)
//		r->next = p;
//	if (q)
//		r->next = q;
//}
////多项式减法 poly1-poly2形成一个新的多项式
//Polynomial polySubtract(Polynomial poly1, Polynomial poly2)
//{
//	//把poly2的系数取相反数，形成一个新的多项式
//	Polynomial poly = (PolyNode*)malloc(sizeof(PolyNode)); //构造头节点
//	PolyNode *p, *q;
//	p = poly;
//	q = poly2->next;
//	while (q)
//	{
//		p->next = (PolyNode*)malloc(sizeof(PolyNode));
//		p = p->next;
//		p->coef = -(q->coef);  //系数取反
//		p->expn = q->expn;
//		q = q->next;
//	}
//	p->next = NULL;
//	add(poly, poly1);  //利用加法
//	return poly;
//}
////多项式相加 poly1+poly2形成一个新的多项式 
//Polynomial polyAdd(Polynomial poly1, Polynomial poly2)
//{
//	Polynomial poly = (PolyNode*)malloc(sizeof(PolyNode));  //和多项式的头节点 
//	poly->next = NULL;
//	PolyNode *p, *q, *r;
//	r = poly;
//	p = poly1->next;
//	q = poly2->next;
//	while (p&&q)
//	{
//		if (p->expn > q->expn)
//		{
//			r->next = (PolyNode*)malloc(sizeof(PolyNode));
//			r = r->next;
//			r->coef = p->coef;
//			r->expn = p->expn;
//			p = p->next;
//		}
//		else if (p->expn < q->expn)
//		{
//			r->next = (PolyNode*)malloc(sizeof(PolyNode));
//			r = r->next;
//			r->coef = q->coef;
//			r->expn = q->expn;
//			q = q->next;
//		}
//		else
//		{
//			float m = p->coef + q->coef;
//			if (!(m > -0.000001 && m < 0.000001))
//			{
//				r->next = (PolyNode*)malloc(sizeof(PolyNode));
//				r = r->next;
//				r->coef = m;
//				r->expn = p->expn;
//			}
//			q = q->next;
//			p = p->next;
//		}
//	}
//	while (p)
//	{
//		r->next = (PolyNode*)malloc(sizeof(PolyNode));
//		r = r->next;
//		r->coef = p->coef;
//		r->expn = p->expn;
//		p = p->next;
//	}
//	while (q)
//	{
//		r->next = (PolyNode*)malloc(sizeof(PolyNode));
//		r = r->next;
//		r->coef = q->coef;
//		r->expn = q->expn;
//		q = q->next;
//	}
//	r->next = NULL;
//	return poly;
//}
////Polynomial polyMultiply(Polynomial poly1, Polynomial poly2)   //多项式相乘  
////{
////	Polynomial poly = (PolyNode*)malloc(sizeof(PolyNode));  //创建多项式和的头节点 
////	poly->next = NULL;
////	PolyNode *p;
////	p = poly2->next;
////	while (p)
////	{
////		add(poly, multiply(poly1, p->coef, p->expn));
////		p = p->next;
////	}
////	return poly;
////}
//void printPoly(Polynomial poly)    //打印多项式 
//{
//	if (poly && poly->next)
//	{
//		PolyNode *p = poly->next;  //p指向第一个节点
//		while (p->next)
//		{
//			if (p->coef)
//			{
//				printf("%gx^%d", p->coef, p->expn);
//
//			}
//			p = p->next;
//			if (p && (p->coef > 0))
//				printf("+");
//		}
//		if (p->expn == 0 && p->coef != 0)
//		{
//			printf("%g", p->coef);   //打印常数项 
//
//		}
//		else if (p->coef != 0)
//		{
//			printf("%gx^%d", p->coef, p->expn);
//
//		}
//		printf("\n");
//	}
//}
//void clear(Polynomial poly)   //释放内存
//{
//	if (poly && poly->next)
//	{
//		PolyNode *p, *q;
//		p = poly;
//		while (p)
//		{
//			q = p->next;
//			free(p);
//			p = q;
//		}
//	}
//	poly = NULL;
//}
//int main()
//{
//	printf("用链表实现多项式的加减法\n");
//	Polynomial poly1, poly2, poly;
//	printf("创建多项式一\n");
//	poly1 = createPolynomial();
//	printf("多项式一：\n");
//	printPoly(poly1);
//	printf("创建多项式二\n");
//	poly2 = createPolynomial();
//	printf("多项式二：\n");
//	printPoly(poly2);
//	printf("两多项式相加，和为：\n");
//	poly = polyAdd(poly1, poly2);
//	printPoly(poly);
//	clear(poly);
//	/*printf("两个多项式相乘，积为：\n");
//	poly = polyMultiply(poly1, poly2);
//	printPoly(poly);
//	clear(poly);*/
//	printf("两多项式相减，差为：\n");
//	poly = polySubtract(poly1, poly2);
//	printPoly(poly);
//	clear(poly1);
//	clear(poly2);
//	clear(poly);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
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
	scanf("%d", &count);
	while (count != 0){
		p = (Node *)malloc(sizeof(Node));
		printf("输入指数和系数:");
		scanf("%d,%d", p->index, p->ratio);
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
			printf("%d+", p->ratio);
		}
		else if (p->next == NULL){
			printf("%dx^%d", p->ratio, p->index);
		}
		else{
			printf("%dx^%d+", p->ratio, p->index);
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