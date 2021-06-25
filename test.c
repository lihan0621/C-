#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person{
	char name[1024];
	char tel[1024];
}Person;
#define MAX_PERSON 1024
typedef struct AddressBook{
	Person persons[MAX_PERSON];
	int size;
}AddressBook;
int menu(){
	printf("========================\n");
	printf("===1.������ϵ��=========\n");
	printf("===2.������ϵ��=========\n");
	printf("===3.ɾ����ϵ��=========\n");
	printf("===4.�޸���ϵ��=========\n");
	printf("===5.�鿴������ϵ��=====\n");
	printf("===6.���������ϵ��=====\n");
	printf("===0.�˳�===============\n");
	printf("========================\n");
	printf("����������ѡ��:");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}
void init(AddressBook* addressBook){
	addressBook->size = 0;
}
void addPerson(AddressBook* addressBook){
	printf("������ϵ��\n");
	int currentsize = addressBook->size;
	if (currentsize >= MAX_PERSON){
		printf("ͨѶ¼����,����ʧ��\n");
		return;
	}
	Person* p = &addressBook->persons[addressBook->size];
	printf("����������ϵ�˵�����: ");
	scanf("%s", p->name);
	printf("����������ϵ�˵ĵ绰: ");
	scanf("%s",p->tel);
	printf("������ϵ�˳ɹ�\n");
	addressBook->size++;
}
void findPerson(AddressBook* addressBook){
	print("��������������ϵ��\n");
	printf("������Ҫ���ҵ���ϵ��\n");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->persons[i];
		if (strcmp(name, p->name) == 0){
			printf("[%d]\t%s\t%s\n",i,p->name,p->tel);
		}
	}
	printf("������ϵ�����\n");
}
void delPerson(AddressBook* addressBook){
	printf("ɾ����ϵ��\n");
	printf("������Ҫɾ������ϵ�˵ı��: ");
	int id = 0;
	scanf("%d",&id);
	if (id < 0 || id >= addressBook->size){
		printf("������������\n");
		return;
	}
	if (id == addressBook->size){
		addressBook->size--;
		printf("ɾ���ɹ�\n");
		return;
	}
	else{
		addressBook->persons[id] = addressBook->persons[addressBook->size - 1];
		addressBook->size--;
		printf("ɾ���ɹ�\n");
	}
}
void updatePerson(AddressBook* addressBook){
}
void printPerson(AddressBook* addressBook){
	printf("��ӡ������ϵ��\n");
	for (int i = 0; i < addressBook->size; i++){
		Person* p = &addressBook->persons[i];
		printf("[%d]\t%s\t%s\n",i,p->name,p->tel);
	}
	printf("���� %d ����¼\n", addressBook->size);
}
void clearPerson(AddressBook* addressBook){
	printf("ȷ����Ҫ�����?(Y/N)\n");
	char Choice = 0;
	scanf("%s",&Choice);
	if (Choice == 'Y'){
		addressBook->size = 0;
	}
	return;
}
typedef void(*Func)(AddressBook*);
AddressBook addressBook;
int main(){
	Func funcs[] = {
		NULL,
		addPerson,
		findPerson,
		delPerson,
		updatePerson,
		printPerson,
		clearPerson
	};
	init(&addressBook);
	while (1){
		int choice = menu();
		if (choice < 0 || choice >= sizeof(funcs) / sizeof(funcs[0])){
			printf("������������\n");
			continue;
		}
		if (choice == 0){
			printf("goodbye\n");
			break;
		}
		funcs[choice](&addressBook);
	}
	system("pause");
	return 0;
}