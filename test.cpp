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
	printf("\n       *****************主菜单**************\n");
	printf("         *    1. 增加学生                    *\n");
	printf("         *    2. 插入学生                    *\n");
	printf("         *    3. 查询学生                    *\n");
	printf("         *    4. 删除学生                    *\n");
	printf("         *    5. 销毁学生表                  *\n");
	printf("         *    6. 查询所有学生                *\n");
	printf("         *    7. 修改学生信息                *\n");
	printf("         *    8. 学生平均成绩                *\n");
	printf("         *    9. 查询学生最高分和不及格成绩  *\n");
	printf("         *    10. 退出                       *\n");
	printf("         *************************************\n");



}
//初始化顺序表
bool InitList(Sqlist *L) {
	L->elems = (struct Student *)malloc(MAX_SIZE * sizeof(struct Student));
	if (!L->elems) return false;
	L->length = 0;
	L->size = MAX_SIZE;
	return true;
}
//在顺序表中增加元素
bool ListAppend(Sqlist* L, struct Student e) {
	if (!L->elems || L->length == L->size) return false;
	L->elems[L->length] = e;
	L->length++;
	return true;
}
//在顺序表中插入元素
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
//查询顺序表中元素信息
bool SearchList(Sqlist *L,int i) {
	if (i<0 || i>L->length - 1) return false;

	return true;
}
//删除顺序表的元素
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
//销毁顺序表
bool DestroyList(Sqlist *L) {
	if (L->elems) delete[] L->elems;
	L->length=0;
	L->size = 0;
	return true;
}
void Update(Sqlist L) {
	printf("请输入需要修改的位置\n");
	int i = 0;
	scanf("%d", &i);
	printf("请输入学生的学号 sno:");
	scanf("%s", &L.elems[i].sno);
	printf("请输入学生的姓名 name:");
	scanf("%s", &L.elems[i].name);
	printf("请输入学生的成绩 score:");
	scanf("%f", &L.elems[i].score);
	printf("请输入学生的年龄 age:");
	scanf("%d", &L.elems[i].age);
}
//输出顺序表中元素信息
void ListPrint(Sqlist L) {
	printf("顺序表元素 size:%d  已保存元素个数 length:%d \n", L.size, L.length);		
	for (int i = 0; i < L.length; i++) {
		printf("第 %d 个同学的 sno:%s name:%s score:%f age:%d\n",i, L.elems[i].sno, L.elems[i].name, L.elems[i].score, L.elems[i].age);
	}
}
void Input(struct Student *stu) {//输入学生信息函数

	printf("请输入学生的学号 sno:");
	scanf("%s", stu->sno);
	printf("请输入学生的姓名 name:");
	scanf("%s", stu->name);
	printf("请输入学生的成绩 score:");
	scanf("%f", &stu->score);
	printf("请输入学生的年龄 age:");
	scanf("%d", &stu->age);
}
void Ave(Sqlist L) {
	int ave = 0;
	for (int i = 0; i < L.length - 1; i++) {
		ave = (L.elems[i].score + L.elems[i + 1].score) / L.length;
	}
	printf("平均成绩为: %d", ave);
}
void MaxFailScore(Sqlist L) {
	int max = 0;
	for (int i = 0; i < L.length; i++) {
		max = L.elems[0].score;
		if (max < L.elems[i].score) {
			max = L.elems[i].score;
		}
		if (L.elems[i].score < 60.0) {
			printf("不及格的学生信息为: %s  %s  %f\n", L.elems[i].sno, L.elems[i].name, L.elems[i].score);
		}
	}
	printf("最高分为: %d\n", max);
}
int main() {
	Sqlist list;
	struct Student stu;
	int tag;
	int count;
	int position;
	printf("初始化成功!");
	InitList(&list);
	while (1) {
		   
			ShowMenu();
			printf("please enter the fuction you selected:");
			scanf("%d", &tag);
		switch (tag) {
		case 1:
			printf("请输入增加的个数:");
			scanf("%d", &count);
			for (int i = 0; i <=count-1; i++) {
				Input(&stu);
				if (ListAppend(&list, stu)) printf("加入成功!\n");				
				else  printf("加入失败!\n");		
			}
			
			break;
		case 2:
			
			printf("请输入插入的个数:");
			scanf("%d", &count);
			for (int i = 0; i <= count - 1; i++) {
				printf("请输入插入的位置:");
				scanf("%d", &position);
				Input(&stu);
				if (ListInsert(&list, stu, position)) printf("插入成功!\n");
				else  printf("插入失败!\n");
			}			
			break;
		case 3:
			printf("请输入你要查询的学生位置:");
			scanf("%d", &position);
			if (SearchList(&list, position)) {
				printf("查询成功!\n");
				printf("第 %d 个同学的 sno:%s name:%s score:%f age:%d\n", 
					position , list.elems[position].sno, list.elems[position].name, list.elems[position].score, list.elems[position].age);
			}
			else printf("查询失败!");
			break;
		case 4:
			printf("请输入删除的个数:");
			scanf("%d", &count);
			for (int i = 0; i <= count - 1; i++) {
				printf("请输入删除的位置:");
				scanf("%d", &position);
				if (DeleteList(&list,position)) printf("删除成功!\n");
				else  printf("删除失败!\n");
			}
			break;
		case 5:
			if (DestroyList(&list)) printf("销毁顺序表成功!\n");
			else printf("销毁顺序表失败!\n");
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