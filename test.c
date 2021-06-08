#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu()
{
    printf("*********************\n");
	printf("******1.游戏开始*****\n");
	printf("******0.游戏结束*****\n");
	printf("*********************\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
game()
{
	int toGuess = rand() % 100 + 1;
	while (1)
	{printf("请输入要猜的数字:");
	int input = 0;
	scanf("%d", &input);
	if (input < toGuess)
	{
		printf("低了!\n");
	}
	else if (input>toGuess)
	{
		printf("高了!\n");
	}
	else
	{
		printf("猜对了!\n");
	}
 }
}
int main()
{
		srand(time(0));
		while (1)
		{
			int choice = menu();
			if (choice == 1)
			{
				game();
			}
			else if (choice == 0)
			{
				printf("程序退出,再见!");
				break;
			}
			else
			{
				printf("您的输入有误,请重新输入!\n");
			}
	
	}
	

	system("pause");
	return 0;
}
