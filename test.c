//#include<stdio.h>
//#include<stdlib.h>
//char * reverse_string(char *str){
//	/*char *start = str;
//	char *end = str + strlen(str) - 1;
//	for (; start < end; start++, end--){
//		char ch = *start;
//		*start = *end;
//		*end = ch;
//	}
//	return str;*/
//	if (strlen(str) < 2){
//		return str;
//	}
//	char ch = *str;
//	int len = strlen(str) - 1;
//	*str = *(str + len);
//	*(str + len) = '\0';
//	reverse_string(str + 1);
//	*(str + len) = ch;
//	return str;
//}
//int main(){
//	char tmp[] = "hello bit!";
//	reverse_string(tmp);
//	printf("%s\n",tmp );
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int Digitsum(int n)
//{
//	if (n < 9){
//		return n;
//	}
//	return (n % 10) + Digitsum(n / 10);
//}
//int main()
//{
//	int num;
//	scanf_s("%d", &num);
//	int ret = Digitsum(num);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int  index(int num, int k)
//{
//	k--;
//	if (k == 0)
//		return num;
//	else
//		return num* index(num, k);
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf_s("%d %d", &n, &k);
//	printf("%d\n", index(n, k));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int fun(int n)      //n代表第几项。特别指出：0是第0项，不是第1项。
//{
//	if (n <= 1)
//		return n;
//	else
//		return fun(n - 1) + fun(n - 2);
//}
//
//int main()
//{
//	int n;
//	printf("请输入要输出多少项（自然数）斐波那契数列：");
//	scanf_s("%d", &n);
//	//int *a = (int *)malloc((n+1)*sizeof(int));//如需存储，使用动态内存分配n+1个空间进行存储
//	int i;
//	for (i = 0; i < n + 1; i++)         //输出所有项
//	{
//		printf("%d, ", fun(i));
//		if (i != 0 && i % 5 == 0)     //每五项进行一次换行（第一行多一个第0项）
//			printf("\n");
//	}
//	printf("第 %d 项是：%d\n", n, fun(n)); //输出要求的项
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int fib(int n){
//	if (n == 1){
//		return 1;
//	}
//	if (n == 2){
//		return 1;
//	}
//	//int num1 = 1;
//	//int num2 = 1;
//	//int cur = 0;
//	//for (int i = 3; i <= n; i++){
//	//	cur = num1 + num2;
//	//	num2 = num1;
//	//	num1 = cur;
//	//}
//	//return cur;
//	return fib(n - 1) + fib(n - 2);
//}
//int main(){
//	int num = 0;
//	scanf_s("%d",&num);
//	int result = fib(num);
//	printf("%d\n",result);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	int money = 20;
//	int total = money;;
//	int tmp = money;
//	while (tmp > 1){
//		total = total + tmp / 2;
//		tmp = tmp / 2 + tmp % 2;
//	}
//	printf("%d\n", total);
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main(){
	int num = 0;
	int sum = 0;
	for (int num=0; num < 5; num++){
		sum = 2 + sum * 10;
		printf("%d+%d\n",sum,sum);
	}
	
	system("pause");
	return 0;
}