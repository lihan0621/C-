#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PolyNode
{
	float coef;            //ϵ��
	int exp;			   //ָ��
	struct PolyNode *next;
} PolyNode;
typedef PolyNode *Polynomial;

Polynomial CreateList(){
	float co;
	int   ex;
	Polynomial head, p, l;
	head = (Polynomial)malloc(sizeof(PolyNode));
	p = head;
	scanf("%f%d", &p->coef, &p->exp);			//����ͷ��㣬�������õ�һ���ڵ㣬Ϊ�˱�֤��Ϊ��
	if (head->coef == 0 && head->exp == 0){        //���ͷ�������Ԫ�ؾ�Ϊ0����Ϊ���ڵ�����
		head->next = NULL;
	}
	else{
		p->next = (Polynomial)malloc(sizeof(PolyNode));
		p = p->next;
		while (1){
			scanf("%f%d", &co, &ex);
			if (co == 0 && ex == 0) break;			// x=0����y=0 ����������
			p->coef = co;
			p->exp = ex;
			l = p;
			p->next = (Polynomial)malloc(sizeof(PolyNode));
			p = p->next;
		}
		l->next = NULL;
	}
	return head;
}
void Sortlist(Polynomial L){ // ��ð�ݷ�������L�еĽڵ㰴ָ���������С�
	Polynomial a, b;
	float temp_co;        //�����м��������������Ԫ�ص�ֵ��
	int temp_ex;
	b = L;
	a = L;
	for (a; a != NULL; a = a->next){
		b = L;
		for (b; b->next != NULL; b = b->next){
			if (b->exp<b->next->exp){
				temp_co = b->coef;
				temp_ex = b->exp;
				b->coef = b->next->coef;
				b->exp = b->next->exp;
				b->next->coef = temp_co;
				b->next->exp = temp_ex;
			}
		}
	}
	return;
}
void Display(Polynomial p){
	Polynomial Pointer;
	Pointer = p;
	do{
		printf("%.2fx^%d  ", Pointer->coef, Pointer->exp);
		Pointer = Pointer->next;
	} while (Pointer != NULL);
}
Polynomial LinkList(Polynomial A, Polynomial B, int n)  //��������A B���������趨B��ͷָ��Ϊ���Ӻ��ͷָ�� n=1��ʾ�ӷ���n=2��ʾ������
{
	Polynomial tail_b, C, op_pointer;  // op_pointer ����ȡ������B cof ����ֵ��
	tail_b = B;
	op_pointer = B;
	for (op_pointer; op_pointer != NULL; op_pointer = op_pointer->next){
		if (n == 2){
			op_pointer->coef = -op_pointer->coef;
			//printf("%.2f  %d\n",op_pointer->coef,op_pointer->exp);
		}
	};

	for (tail_b; tail_b->next != NULL; tail_b = tail_b->next);  // ���� B A ������B����ͷΪ�ϲ���ı�ͷ
	tail_b->next = A;

	C = B;
	Sortlist(C);
	return C;
}
void MergeList(Polynomial C){      // �ϲ�C��exp��ֵ��ͬ�Ľڵ�.
	Polynomial C1, C2;
	C1 = C;
	C2 = C1->next;
	while (C2 != NULL){
		if (C1->exp == C1->next->exp){
			C1->coef = C1->next->coef + C1->coef;
			C1->next = C1->next->next;
			free(C2);
			C2 = C1->next;
		}
		else{
			C1 = C1->next;
			C2 = C2->next;
		}
	}
}

void main(){
	Polynomial A, B, Com;
	int s;
	printf("\n����������A������:��ʽΪ coeffient exp �Կո�ֿ�\n");
	A = CreateList();
	Display(A);
	printf("\n����������B������:��ʽΪ coeffient exp �Կո�ֿ�\n");
	B = CreateList();
	Display(B);
	printf("��ѡ��ӷ����Ǽ���\n");
	printf("����1����ӷ�\n");
	printf("����2�������\n");
	scanf("%d", &s);
	if (s == 1 || s == 2){
		Com = LinkList(A, B, s);
		MergeList(Com);
		Display(Com);
	}
	else{
		printf("�����˷Ƿ��ַ�\n");
	}

}