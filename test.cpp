#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
typedef  struct {//树结构
	int weight;//定义权重
	int parent, lchild, rchild;//定义双亲，左孩子，右孩子；
}HTNode, *HuffmanTree;
typedef char * * HuffmanCode;
void select(HuffmanTree HT, int m, int* s1, int* s2) {
	int i;
	int min1 = 100;
	int min2 = 100;
	for (i = 1; i <= m; i++) {
		if (HT[i].parent == 0 && min1 > HT[i].weight) {
			min1 = HT[i].weight;
			*s1 = i;
		}
	}
	for (i = 1; i <= m; i++) {
		if (i != (*s1) && HT[i].parent == 0)
		if (HT[i].weight < min2) {
			min2 = HT[i].weight;
			*s2 = i;
		}
	}
}
void HuffmanCoding(HuffmanTree & HT, HuffmanCode &HC, int *w, int n) //HT为地址传递的存储哈夫曼树的数组，w为存储结点权重值的数组，n为结点个数，并求出n个字符的赫夫曼编码。
{
	int m;
	int i;
	HuffmanTree p;
	int start; int s1; int s2;
	unsigned c, f;
	if (n <= 1)return;//如果只有一个编码，则相当于0；
	m = 2 * n - 1;//哈夫曼树总节点数，n为叶子节点
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元不用
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) *p = { *w, 0, 0, 0 };// 初始化哈夫曼树中所有结点
	for (int i = n + 1; i <= m; ++i, ++p) *p = { 0, 0, 0, 0 }//从数组的下标n+1初始化所有结点。
	;
	for (i = n + 1; i <= m; ++i)//建赫夫曼树
	{
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	printf("下标\t权值\t双亲\t左孩子\t右孩子\n");
	for (i = 1; i <= m; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}

	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//分配n个字符编码的头指针向量
	char* cd = (char*)malloc(n * sizeof(char)); ///存放结点哈夫曼编码的字符串数组
	cd[n - 1] = '\0';//字符串结束符
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//当前结点在数组中的位置；
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//从叶子到根逆向求编码，直到找到根节点
		if (HT[f].lchild == c)    cd[--start] = '0';
		else cd[--start] = '1';//如果该结点是父结点的左孩子则对应路径编码为0，否则为右孩子编码为1；
		HC[i] = (char*)malloc((n - start) * sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);//从cd复制编码（串）到HC 字符串赋值；
	}
	free(cd);//释放工作空间。
}

int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int* w, n, i;
	printf("请输入权值的个数(>1)：");
	scanf("%d", &n);
	w = (int*)malloc(n * sizeof(int));
	printf("请依次输入%d个权值：\n", n);
	for (i = 0; i <= n - 1; i++)
		scanf("%d", w + i);
	HuffmanCoding(HT, HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("第%d个叶子结点的编码：", i);
		printf("%s\n", HC[i]);
	}

	system("pause");
	return 0;
}
