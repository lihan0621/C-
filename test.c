#include<stdio.h>
#include<string.h>
int main()
{
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));        //16
	//printf("%d\n", sizeof(a + 0));    //4    a + 0�õ�int *
	//printf("%d\n", sizeof(*a));       //4    *a�õ���int
	//printf("%d\n", sizeof(a + 1));    //4   a + 1�õ���int*
	//printf("%d\n", sizeof(a[1]));     //4   a[1]�õ���int
	//printf("%d\n", sizeof(&a));       //����ָ��  &a   int(*)[4]
	//printf("%d\n", sizeof(*&a));	  //16   &a=>int(*)[4] �ٽ����þͳ�������
	//printf("%d\n", sizeof(&a + 1));	  //&a int(*)[4] ��+1��������ָ��
	//printf("%d\n", sizeof(&a[0]));	  //4 a[0]�õ�int &�õ�int*
	//printf("%d\n", sizeof(&a[0] + 1));//4             +1����4 
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));		//6  �������� 6 ��char
	//printf("%d\n", sizeof(arr + 0));	//4  arr + 0�õ���char*
	//printf("%d\n", sizeof(*arr));		//1  *arr�õ���һ��char
	//printf("%d\n", sizeof(arr[1]));		//1 arr[1]�õ���һ��char
	//printf("%d\n", sizeof(&arr));		//4   char(*)[6]
	//printf("%d\n", sizeof(&arr + 1));	//4   char(*)[6]
	//printf("%d\n", sizeof(&arr[0] + 1));//4	   a[0]�õ�char��&�õ�char*	
	////ֻҪ��ǰ�ַ����鲻���ַ���, �Ͳ���ʹ��strϵ�к���
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	////char �� const char* ����һ������
	//printf("%d\n", strlen(*arr));//δ������Ϊ.��ĸ�����
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr + 0));
	//printf("%d\n", sizeof(*arr));
	//printf("%d\n", sizeof(arr[1]));
	//printf("%d\n", sizeof(&arr));
	//printf("%d\n", sizeof(&arr + 1));
	//printf("%d\n", sizeof(&arr[0] + 1));
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", sizeof(*p));
	//printf("%d\n", sizeof(p[0]));
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", sizeof(&p[0] + 1));
	//printf("%d\n", strlen(p));
	//printf("%d\n", strlen(p + 1));
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));
	//printf("%d\n", strlen(&p[0] + 1));
	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof(a[0][0]));
	//printf("%d\n", sizeof(a[0]));
	//printf("%d\n", sizeof(a[0] + 1));
	//printf("%d\n", sizeof(*(a[0] + 1)));
	//printf("%d\n", sizeof(a + 1));
	//printf("%d\n", sizeof(*(a + 1)));
	//printf("%d\n", sizeof(&a[0] + 1));
	//printf("%d\n", sizeof(*(&a[0] + 1)));
	//printf("%d\n", sizeof(*a));
	//printf("%d\n", sizeof(a[3]));
	return 0;
}