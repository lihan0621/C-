#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX_SIZE 10
struct Student {
	int age;
	float score;
	char name[20];
	char sno[20];
};

typedef struct{
	struct Student* elems;
	int length;
	int size;
}Sqlist;
void ShowMenu() {
	printf("\n       *****************���˵�**************\n");
	printf("         *    1. ����ѧ��                    *\n");
	printf("         *    2. ����ѧ��                    *\n");
	printf("         *    3. ��ѯѧ��                    *\n");
	printf("         *    4. ɾ��ѧ��                    *\n");
	printf("         *    5. ����ѧ����                  *\n");
	printf("         *    6. ��ѯ����ѧ��                *\n");
	printf("         *    7. �޸�ѧ����Ϣ                *\n");
	printf("         *    8. ѧ��ƽ���ɼ�                *\n");
	printf("         *    9. ��ѯѧ����߷ֺͲ�����ɼ�  *\n");
	printf("         *    10. �˳�                       *\n");
	printf("         *************************************\n");



}
//��ʼ��˳���
bool InitList(Sqlist *L) {
	L->elems = (struct Student *)malloc(MAX_SIZE * sizeof(struct Student));
	if (!L->elems) return false;
	L->length = 0;
	L->size = MAX_SIZE;
	return true;
}
//��˳���������Ԫ��
bool ListAppend(Sqlist* L, struct Student e) {
	if (!L->elems || L->length == L->size) return false;
	L->elems[L->length] = e;
	L->length++;
	return true;
}
//��˳����в���Ԫ��
bool ListInsert(Sqlist *L,struct Student e,int i) {
	if (i < 0 || i >= L->length) return false;
	if (L->length == L->size) return false;
	 for (int j = L->length - 1; j >= i; j--) {
		L->elems[j + 1] = L->elems[j];
	}
	L->elems[i] = e;
	L->length++;
	return true;
}
//��ѯ˳�����Ԫ����Ϣ
bool SearchList(Sqlist *L,int i) {
	if (i<0 || i>L->length - 1) return false;

	return true;
}
//ɾ��˳����Ԫ��
bool DeleteList(Sqlist *L,int i) {
	if (L->length == 0||i<0||i>=L->length) return false;
	if (L->length - 1 == i)
		L->length--;
	else {
		for (int j = i; j <= L->length-2; j++) {
			L->elems[j] = L->elems[j + 1];
		}
		L->length--;
	}
	
	return true;
}
//����˳���
bool DestroyList(Sqlist *L) {
	if (L->elems) delete[] L->elems;
	L->length=0;
	L->size = 0;
	return true;
}
void Update(Sqlist L) {
	printf("��������Ҫ�޸ĵ�λ��\n");
	int i = 0;
	scanf("%d", &i);
	printf("������ѧ����ѧ�� sno:");
	scanf("%s", &L.elems[i].sno);
	printf("������ѧ�������� name:");
	scanf("%s", &L.elems[i].name);
	printf("������ѧ���ĳɼ� score:");
	scanf("%f", &L.elems[i].score);
	printf("������ѧ�������� age:");
	scanf("%d", &L.elems[i].age);
}
//���˳�����Ԫ����Ϣ
void ListPrint(Sqlist L) {
	printf("˳���Ԫ�� size:%d  �ѱ���Ԫ�ظ��� length:%d \n", L.size, L.length);		
	for (int i = 0; i < L.length; i++) {
		printf("�� %d ��ͬѧ�� sno:%s name:%s score:%f age:%d\n",i, L.elems[i].sno, L.elems[i].name, L.elems[i].score, L.elems[i].age);
	}
}
void Input(struct Student *stu) {//����ѧ����Ϣ����

	printf("������ѧ����ѧ�� sno:");
	scanf("%s", stu->sno);
	printf("������ѧ�������� name:");
	scanf("%s", stu->name);
	printf("������ѧ���ĳɼ� score:");
	scanf("%f", &stu->score);
	printf("������ѧ�������� age:");
	scanf("%d", &stu->age);
}
void Ave(Sqlist L) {
	int ave = 0;
	for (int i = 0; i < L.length - 1; i++) {
		ave = (L.elems[i].score + L.elems[i + 1].score) / L.length;
	}
	printf("ƽ���ɼ�Ϊ: %d", ave);
}
void MaxFailScore(Sqlist L) {
	int max = 0;
	for (int i = 0; i < L.length; i++) {
		max = L.elems[0].score;
		if (max < L.elems[i].score) {
			max = L.elems[i].score;
		}
		if (L.elems[i].score < 60.0) {
			printf("�������ѧ����ϢΪ: %s  %s  %f\n", L.elems[i].sno, L.elems[i].name, L.elems[i].score);
		}
	}
	printf("��߷�Ϊ: %d\n", max);
}
int main() {
	Sqlist list;
	struct Student stu;
	int tag;
	int count;
	int position;
	printf("��ʼ���ɹ�!");
	InitList(&list);
	while (1) {
		   
			ShowMenu();
			printf("please enter the fuction you selected:");
			scanf("%d", &tag);
		switch (tag) {
		case 1:
			printf("���������ӵĸ���:");
			scanf("%d", &count);
			for (int i = 0; i <=count-1; i++) {
				Input(&stu);
				if (ListAppend(&list, stu)) printf("����ɹ�!\n");				
				else  printf("����ʧ��!\n");		
			}
			
			break;
		case 2:
			
			printf("���������ĸ���:");
			scanf("%d", &count);
			for (int i = 0; i <= count - 1; i++) {
				printf("����������λ��:");
				scanf("%d", &position);
				Input(&stu);
				if (ListInsert(&list, stu, position)) printf("����ɹ�!\n");
				else  printf("����ʧ��!\n");
			}			
			break;
		case 3:
			printf("��������Ҫ��ѯ��ѧ��λ��:");
			scanf("%d", &position);
			if (SearchList(&list, position)) {
				printf("��ѯ�ɹ�!\n");
				printf("�� %d ��ͬѧ�� sno:%s name:%s score:%f age:%d\n", 
					position , list.elems[position].sno, list.elems[position].name, list.elems[position].score, list.elems[position].age);
			}
			else printf("��ѯʧ��!");
			break;
		case 4:
			printf("������ɾ���ĸ���:");
			scanf("%d", &count);
			for (int i = 0; i <= count - 1; i++) {
				printf("������ɾ����λ��:");
				scanf("%d", &position);
				if (DeleteList(&list,position)) printf("ɾ���ɹ�!\n");
				else  printf("ɾ��ʧ��!\n");
			}
			break;
		case 5:
			if (DestroyList(&list)) printf("����˳���ɹ�!\n");
			else printf("����˳���ʧ��!\n");
			break;
		case 6:
			ListPrint(list);
			break;
		case 7:
			Update(list);
			break;
		case 8:
			Ave(list);
			break;
		case 9:
			MaxFailScore(list);
			break;
		case 10:
			return 0;
		default:
			printf("input error!\n");
			break;
		}
	}
	return 0;
}