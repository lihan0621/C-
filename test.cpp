#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;
typedef  struct {//���ṹ
	int weight;//����Ȩ��
	int parent, lchild, rchild;//����˫�ף����ӣ��Һ��ӣ�
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
void HuffmanCoding(HuffmanTree & HT, HuffmanCode &HC, int *w, int n) //HTΪ��ַ���ݵĴ洢�������������飬wΪ�洢���Ȩ��ֵ�����飬nΪ�������������n���ַ��ĺշ������롣
{
	int m;
	int i;
	HuffmanTree p;
	int start; int s1; int s2;
	unsigned c, f;
	if (n <= 1)return;//���ֻ��һ�����룬���൱��0��
	m = 2 * n - 1;//���������ܽڵ�����nΪҶ�ӽڵ�
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0�ŵ�Ԫ����
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w) *p = { *w, 0, 0, 0 };// ��ʼ���������������н��
	for (int i = n + 1; i <= m; ++i, ++p) *p = { 0, 0, 0, 0 }//��������±�n+1��ʼ�����н�㡣
	;
	for (i = n + 1; i <= m; ++i)//���շ�����
	{
		select(HT, i - 1, &s1, &s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	printf("�±�\tȨֵ\t˫��\t����\t�Һ���\n");
	for (i = 1; i <= m; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}

	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));//����n���ַ������ͷָ������
	char* cd = (char*)malloc(n * sizeof(char)); ///��Ž�������������ַ�������
	cd[n - 1] = '\0';//�ַ���������
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//��ǰ����������е�λ�ã�
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)//��Ҷ�ӵ�����������룬ֱ���ҵ����ڵ�
		if (HT[f].lchild == c)    cd[--start] = '0';
		else cd[--start] = '1';//����ý���Ǹ������������Ӧ·������Ϊ0������Ϊ�Һ��ӱ���Ϊ1��
		HC[i] = (char*)malloc((n - start) * sizeof(char));//Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);//��cd���Ʊ��루������HC �ַ�����ֵ��
	}
	free(cd);//�ͷŹ����ռ䡣
}

int main(void)
{
	HuffmanTree HT;
	HuffmanCode HC;
	int* w, n, i;
	printf("������Ȩֵ�ĸ���(>1)��");
	scanf("%d", &n);
	w = (int*)malloc(n * sizeof(int));
	printf("����������%d��Ȩֵ��\n", n);
	for (i = 0; i <= n - 1; i++)
		scanf("%d", w + i);
	HuffmanCoding(HT, HC, w, n);
	for (i = 1; i <= n; i++)
	{
		printf("��%d��Ҷ�ӽ��ı��룺", i);
		printf("%s\n", HC[i]);
	}

	system("pause");
	return 0;
}
