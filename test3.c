#include<stdio.h>
#include<stdlib.h>
#define N 9
int x[N];
int count = 0;
void dump()
{
	for (int i = 0; i < N; i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
void swap(int a, int b)
{
	int t = x[a];
	x[a] = x[b];
	x[b] = t;
}
void run(int n)
{
	if (N - 1 == n) {
		dump();
		count++;
		return;
	}
	for (int i = n+1; i < N; i++) {
		swap(n, i);
		run(n + 1);
		swap(n +1, i);
	}
}
int main()
{
	for (int i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	run(0);
	printf("* Total:%d\n", count);
	return 0;
}