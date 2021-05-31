#include<stdio.h>
#include<string.h>
int main()
{
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));        //16
	//printf("%d\n", sizeof(a + 0));    //4    a + 0得到int *
	//printf("%d\n", sizeof(*a));       //4    *a得到了int
	//printf("%d\n", sizeof(a + 1));    //4   a + 1得到了int*
	//printf("%d\n", sizeof(a[1]));     //4   a[1]得到了int
	//printf("%d\n", sizeof(&a));       //数组指针  &a   int(*)[4]
	//printf("%d\n", sizeof(*&a));	  //16   &a=>int(*)[4] 再解引用就成了数组
	//printf("%d\n", sizeof(&a + 1));	  //&a int(*)[4] 再+1还是数组指针
	//printf("%d\n", sizeof(&a[0]));	  //4 a[0]得到int &得到int*
	//printf("%d\n", sizeof(&a[0] + 1));//4             +1还是4 
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));		//6  数组里有 6 个char
	//printf("%d\n", sizeof(arr + 0));	//4  arr + 0得到了char*
	//printf("%d\n", sizeof(*arr));		//1  *arr得到了一个char
	//printf("%d\n", sizeof(arr[1]));		//1 arr[1]得到了一个char
	//printf("%d\n", sizeof(&arr));		//4   char(*)[6]
	//printf("%d\n", sizeof(&arr + 1));	//4   char(*)[6]
	//printf("%d\n", sizeof(&arr[0] + 1));//4	   a[0]得到char再&得到char*	
	////只要当前字符数组不是字符串, 就不能使用str系列函数
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	////char 和 const char* 不是一个类型
	//printf("%d\n", strlen(*arr));//未定义行为.错的更离谱
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