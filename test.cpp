
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<thread>
using namespace std;
#define ROWSIZE 23
#define COLSIZE 62
#define LETSIZE 26
#define MAXLET  10
typedef char Array[ROWSIZE][COLSIZE];
typedef struct
{
	int tag;
	int row;
	int col;
}LetNode;
typedef struct
{
	LetNode data[LETSIZE];
	int curnum;
	int maxnum;
}LetTable;
void InitArray(Array ar)
{
	memset(ar, ' ', sizeof(Array));
	memset(ar[0], '_', sizeof(char)*COLSIZE);
	memset(ar[ROWSIZE - 1], '_', sizeof(char)*COLSIZE);
	for (int i = 0; i < ROWSIZE; ++i)
	{
		ar[i][COLSIZE - 2] = '\n';
		ar[i][COLSIZE - 1] = '\0';
	}
}
void InitLetTable(LetTable *plet, int m)
{
	srand(unsigned int(time(NULL)));
	int i = 0;
	//int let[26] = { 0 };
	int col[COLSIZE] = { 0 };
	memset(plet->data, 0, sizeof(LetNode)*LETSIZE);
	plet->curnum = m;
	plet->maxnum = MAXLET;
	while (i < m)
	{
		int index = rand() % 26;
		int c = rand() % (COLSIZE - 2);
		if (plet->data[index].tag == 0 && col[c] == 0)
		{
			plet->data[index].tag = 1;
			col[c] = 1;
			plet->data[index].col = c;
			plet->data[index].row = 1;
			++i;
		}
	}
}
void PrintArray(Array ar, LetTable *plet)
{
	system("cls");
	InitArray(ar);
	for (int i = 0; i < LETSIZE; ++i)
	{
		if (plet->data[i].tag==1)
		{
			ar[plet->data[i].row][plet->data[i].col] = i + 'a';
		}
	}
	for (int i = 0; i < ROWSIZE; ++i)
	{
		printf("%s", ar[i]);
	}
}
void LetDown(LetTable *plet)
{
	for (int i = 0; i < LETSIZE; ++i)
	{
		if (plet->data[i].tag == 1)
		{
			plet->data[i].row += 1;
		}
	}
}
bool Romvex(char ch, LetTable *plet)
{
	bool res = false;
	/*for (int i = 0; i < LETSIZE; ++i)
	{
	if (x[i].ch == ch)
	{
	x[i].ch = '\0';
	x[i].ch = rand() % 26 + 'a';
	x[i].row = 1;
	x[i].col = rand() % (COLSIZE - 2);
	}
	}*/
	//x[ch - 'a'].ch = 0;
	int index = ch - 'a';
	if (plet->data[index].tag == 0) return true;
	plet->data[index].tag = 0;
	while (1)
	{
		index = rand() % 26;
		if (plet->data[index].tag == 0)
		{
			plet->data[index].tag = 1;
			plet->data[index].row = 1;
			plet->data[index].col = rand() % (COLSIZE - 2);
			break;
		}
	
	}
	return res;
}
bool is_Down(LetTable *plet)
{
	bool flag = false;
	for (int i = 0; i < LETSIZE; ++i)
	{
		if (plet->data[i].tag == 1 && plet->data[i].row >= ROWSIZE)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
int main()
{
	int num = 0;
	Array ar;
	LetTable x;
	char ch;
	InitLetTable(&x, 5);
	int wait = 1000;
	while (1)
	{
		PrintArray(ar,&x);
		LetDown(&x);
		if (is_Down(&x))
		{
			break;
		}
		if (_kbhit())
		{
			ch = _getch();
			if (Romvex(ch, &x))
			{
				num += 1;
				if (num % 5 == 0)
				{
					if (x.curnum >= x.maxnum)
					{
						wait = wait / 2;
					}
					//else
					//{

					//}
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(wait));
	}
	system("pause");
	return 0;
}
