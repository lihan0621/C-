#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
int Mod(int a, int b)
{
	return a % b;
}
int main()
{
	int select = 1;
	int op1, op2, result;
	/// <summary>
	system("title ���׼�����");
	system("color 64");
	/// </summary>
	/// <returns></returns>
	while (select) {
		printf("***************************\n");
		printf("*[1]Add       [2]Sub      *\n");
		printf("*[3]Mul       [4]Div      *\n");
		printf("*[5]Mod       [0]Quit     *\n");
		printf("***************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0) 
			break;
		printf("��ѡ��op1,op2:>");
		scanf("%d,%d", &op1, &op2);
		switch (select) {
			case 1:
				result = Add(op1, op2);
				break;
			case 2:
				result = Sub(op1, op2);
				break;
			case 3:
				result = Mul(op1, op2);
				break;
			case 4:
				result = Div(op1, op2);
				break;
			case 5:
				result = Mod(op1, op2);
				break;
			default:
				printf("�����cmd��������������......\n");
				break;
		}
		printf("result = %d\n", result);
		system("cls");
	}
	printf("ϵͳ�˳�\n");
	return 0;
}