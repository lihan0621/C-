#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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
	while (select) {
		printf("***************************\n");
		printf("*[1]Add       [2]Sub      *\n");
		printf("*[3]Mul       [4]Div      *\n");
		printf("*[5]Mod       [0]Quit     *\n");
		printf("***************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0) 
			break;
		printf("请选择op1,op2:>");
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
				printf("输入的cmd有误，请重新输入......\n");
				break;
		}
		printf("result = %d\n", result);
	}
	printf("系统退出\n");
	return 0;
}