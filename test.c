//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//char *my_strstr(char* dest, char * src)
//{
//	assert(dest);
//	assert(src);
//	char *p = NULL;
//	char *np = NULL;
//	char *q = NULL;
//	p = dest;
//	//当*p!='\0'时，循环一直成立
//	while (*p)
//	{
//		np = p; //np指向p;
//		q = src; //q指向src;
//		for (; (*np && *q) && (*np == *q); np++, q++)
//		{
//			;
//		}
//		if (*q == '\0')//说明已经找到字符串“bbcd”
//		{
//			return p;
//		}
//		if (*np == '\0')
//		{
//			break;
//		}
//		p++;//可以得到原始位置的下一个位置；
//	}
//	return NULL;//not find
//}
//int main()
//{
//	char str1[32] = "abbbcdefg";
//	char str2[10] = "bbcd";
//	printf("%s\n", my_strstr(str1, str2));
//	system("pause");
//	return 0;
//}
