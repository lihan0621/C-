#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"lstack.h"
Stack* Buynode()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	assert(s != nullptr);
	s->next = nullptr;
	return s;
}
//��ʼ������(�൱��˳����β��)
void Init(Stack* plist)
{
	plist = Buynode();
	plist->data = 0;
	plist->next = nullptr;
	printf("%d\n", plist->data);
}
//��ջ
bool Push(Stack* plist, Elemtype val)
{
	assert(plist != nullptr);
	Stack* s = Buynode();
	if (s == nullptr) return false;
	s->data = val;
	if (plist->next == nullptr)
	{
		plist->next = s;
		return true;
	}
	s->next = plist->next;
	plist->next = s;
	printf("��ջ�ɹ�\n");
	plist->data++;
	return true;
}
//��ջ����ջ�Ļ���Ҫ���߳�ջ��ֵ��
bool pop(Stack* plist, Elemtype* rval)
{
	assert(plist != nullptr);
	if (Is_empty(plist)) return false;
	*rval = plist->next->data;
	Stack* p = plist->next;
	plist->next = p->next;
	free(p);
	p = nullptr;
	plist->data -= 1;
	return false;
}
//��ȡջ��Ԫ��
bool Top(Stack* plist, Elemtype* rval)
{
	assert(plist != nullptr);
	if (Is_empty(plist)) return false;
	*rval = plist->next->data;
	return true;
}

//��ȡ��Ч���ݸ���
int Get_length(Stack* plist)
{
	assert(plist != nullptr);
	return plist->data;
}
//�п�
bool Is_empty(Stack* plist)
{
	assert(plist != nullptr);
	return plist->data == 0;
}
//���
void Clear(Stack* plist)
{
	assert(plist != nullptr);
	plist->data = 0;
	plist->next = nullptr;
}
//����
void Destory(Stack* plist)
{
	assert(plist != nullptr);
	while (plist->data != 0)
	{
		Stack* p = plist->next;
		plist->next = p->next;
		free(p);
		p = nullptr;
		plist->data -= 1;
	}
}
//��ӡ
void Show(Stack* plist)
{
	assert(plist != nullptr);
	Stack* s = plist->next;
	//for (s; s != nullptr; s = s->next)
	//{
	//	printf("%d ", s->data);
	//}
	while (s != nullptr)
	{
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}
int main()
{
	Stack a;
	Init(&a);//
	for (int i = 0; i < 5; i++)
	{
		Push(&a, i + 1);//
	}
	Show(&a);
	int b = 0;
	Top(&a, &b);//
	printf("%d\n", b);
	pop(&a, &b);//
	printf("%d\n", b);
	int length = Get_length(&a);
	printf("%d\n", length);
	return 0;
}




