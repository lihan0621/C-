#include<stdio.h>
void Swap1(int num1, int num2)
{
	int tmp = 0;
	tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void Swap2(int *num1, int *num2)
{
	int tmp = 0;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	Swap1(num1, num2);
	printf("%d %d\n", num1, num2);
	Swap2(&num1, &num2);
	printf("%d %d\n", num1, num2);
	return 0;
}