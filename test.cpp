#include<stdio.h>
int count = 0;
int fun(int n)
{
	count++;
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	else
		return fun(n - 1) + fun(n - 2);
}
int main()
{
	fun(8);
	printf("%d\n", count);
	return 0;
}