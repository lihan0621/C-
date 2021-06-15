#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
#define DIGROW 5
#define DIGCOL 5
#define VIEWNUM 65
typedef char Array[DIGROW][DIGCOL];
static const int dig[10][20] = {
	{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1 }
};
void InitArray(Array ar)
{
	memset(ar, ' ', sizeof(Array));
	for (int i = 0; i < DIGROW; ++i)
	{
		ar[i][DIGCOL - 1] = '\0';
	}
}
void ShowArray(Array ar,int num)
{
	InitArray(ar);
	for (int i = 0; i < 20; ++i)
	{
		if (dig[num][i] == 1)
		{
			ar[i / (DIGCOL-1)][i % (DIGCOL-1)] = VIEWNUM;
		}
	}
	system("cls");
	for (int i = 0; i < DIGROW; ++i)
	{
		for (int j = 0; j < DIGCOL - 1; ++j)
		{
			printf("%c", ar[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	Array ar;
	int num;
	do
	{
		scanf_s("%d", &num);
		ShowArray(ar, num);
	} while (1);
	system("pause");
	return 0;
}