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
//	//��*p!='\0'ʱ��ѭ��һֱ����
//	while (*p)
//	{
//		np = p; //npָ��p;
//		q = src; //qָ��src;
//		for (; (*np && *q) && (*np == *q); np++, q++)
//		{
//			;
//		}
//		if (*q == '\0')//˵���Ѿ��ҵ��ַ�����bbcd��
//		{
//			return p;
//		}
//		if (*np == '\0')
//		{
//			break;
//		}
//		p++;//���Եõ�ԭʼλ�õ���һ��λ�ã�
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
