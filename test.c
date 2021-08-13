#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define infinity 65535 /*定义一个无限大的值*/
/*哈夫曼树类型定义*/
typedef struct
{
	 int weight;
	 int parent, lchild, rchild;
}HTNode, *HuffmanTree;
typedef char** HuffmanCode; /*存放哈夫曼编码*/
int Min(HuffmanTree t, int n);
void Select(HuffmanTree* t, int n, int* s1, int* s2);
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n);
void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int* w, n, i;
	printf("请输入叶子结点的个数: ");
	scanf("%d", &n);
	w = (int*)malloc(n * sizeof(int)); /*为n个结点的权值分配内存空间*/
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个结点的权值:", i + 1);
		scanf("%d", w + i);
	}
	HuffmanCoding(&HT, &HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("哈夫曼编码:");
		puts(HC[i]);
	}
	/*释放内存空间*/
	for (i = 1; i <= n; i++)
		free(HC[i]);
	free(HC);
	free(HT);
	system("pause");
	return 0;
}
/*构造哈夫曼树HT*/
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n)
/*构造哈夫曼树HT，并从根结点到叶子结点求哈夫曼编码并保存在HC中*/
{
	int s1, s2, i, m;
	unsigned int r, cdlen;
	char* cd;
	HuffmanTree p;
	if (n <= 1)
		return;
	m = 2 * n - 1;
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	for (p = *HT + 1, i = 1; i <= n; i++, p++, w++)
	{
		(*p).weight = *w;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
		(*p).parent = 0;
	/*构造哈夫曼树HT*/
	for (i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1, &s1, &s2);
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	/*从根结点到叶子结点求哈夫曼编码并保存在HC中*/
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	cd = (char*)malloc(n * sizeof(char));
	r = m; /*从根结点开始*/
	cdlen = 0; /*编码长度初始化为0*/
	for (i = 1; i <= m; i++)
		(*HT)[i].weight = 0; /*将weight域作为状态标志*/
	while (r)
	{
		if ((*HT)[r].weight == 0) /*如果weight域等于零，说明左孩子结点没有遍历*/
		{
			(*HT)[r].weight = 1; /*修改标志*/
			if ((*HT)[r].lchild != 0) /*如果存在左孩子结点，则将编码置为0*/
			{
				r = (*HT)[r].lchild;
				cd[cdlen++] = '0';
			}
			else if ((*HT)[r].rchild == 0) /*如果是叶子结点，则将当前求出的编码保存到HC中*/
			{
				(*HC)[r] = (char*)malloc((cdlen + 1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy((*HC)[r], cd);
			}
		}
		else if ((*HT)[r].weight == 1) /*如果已经访问过左孩子结点，则访问右孩子结点*/
		{
			(*HT)[r].weight = 2; /*修改标志*/
			if ((*HT)[r].rchild != 0)
			{
				r = (*HT)[r].rchild;
				cd[cdlen++] = '1';
			}
		}
		else /*如果左孩子结点和右孩子结点都已经访问过，则退回到双亲结点*/
		{
			r = (*HT)[r].parent;
			--cdlen; /*编码长度减1*/
		}
	}
	free(cd);
}
int Min(HuffmanTree t, int n)
/*返回树中n个结点中权值最小的结点序号*/
{
	int i, flag;
	int f = infinity; /*f为一个无限大的值*/
	for (i = 1; i <= n; i++)
	if (t[i].weight < f && t[i].parent == 0)
		f = t[i].weight, flag = i;
	t[flag].parent = 1; /*给选中的结点的双亲结点赋值1，避免再次查找该结点*/
	return flag;
}
void Select(HuffmanTree* t, int n, int* s1, int* s2)
/*在n个结点中选择两个权值最小的结点序号，其中s1最小，s2次小*/
{
	int x;
	*s1 = Min(*t, n);
	*s2 = Min(*t, n);
	if ((*t)[*s1].weight > (*t)[*s2].weight)/*若序号s1的权值大于s2的权值，将两者交换，使s1最小，s2
											次小*/
	{
		x = *s1;
		*s1 = *s2;
		*s2 = x;
	}
}