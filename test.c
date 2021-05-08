//#include<stdio.h>
//#include<stdlib.h>
//const char* mystrstr(const char* str1, const char* str2){
//	if (str1 == NULL || str2 == NULL){
//		return NULL;
//	}
//	const char* blackptr = str1;
//	while (*blackptr != '\0'){
//		const char* redptr = blackptr;
//		const char* subptr = str2;
//		while (*redptr != '\0'&&*subptr != '\0'&&*redptr == *subptr){
//			redptr++;
//			subptr++;
//		}
//		if (*subptr == '\0'){
//			return blackptr;
//		}
//		blackptr++;
//	}
//	return NULL;
//}
//char* mystrcat(char* dest,char* src){
//	if (dest == NULL || src == NULL){
//		return dest;
//	}
//	char* p = dest;
//	while (*p != '\0'){
//		p++;
//	}
//	while (*src != '\0'){
//		*p = *src;
//		p++;
//		src++;
//	}
//	*p = '\0';
//	return dest;
//}
//int mystrcmp(const char* str1, const char* str2){
//	assert(str1 != NULL && str2 != NULL);
//	while (*str1 != '\0' && *str2 != '\0'){
//		if (*str1 < *str2){
//			return -1;
//		}
//		else if (*str1 > *str2){
//			return 1;
//		}
//		else {
//			str1++;
//			str2++;
//		}
//	}
//	if (*str1 < *str2){
//		return -1;
//	}
//	else if (*str1 > *str2){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//char* mystrcpy(char* dest, char* src){
//	if (dest == NULL || src == NULL){
//		return 0;
//	}
//	char* ret = dest;
//	while (*src != '\0'){
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = '\0';
//	return ret;
//}
//size_t mystrlen(const char* str){
//	if (str == NULL){
//		return NULL;
//	}
//	size_t len = 0;
//	while (str[len] != '\0'){
//		len++;
//	}
//	return len;
//}
//void* mymemcpy(void* dest, const void* src, size_t num){
//	char* pDest = (char*)dest;
//	char* pSrc = (char*)src;
//	for (int i = 0; i < num; i++){
//		*(pDest + i) = *(pSrc + i);
//	}
//	return dest;
//}
//void* mymemmove(void* dest, const void* src, size_t num){
//	char* pDest = (char*)dest;
//	char* pSrc = (char*)src;
//	if (pSrc <= pDest && pDest <= pSrc + num){
//		for (int i = num - 1; i >= 0; i--){
//			*(pDest + i) = *(pSrc + i);
//		}
//	}
//	else{
//		return mymemcpy(dest, src, num);
//	}
//}
//int main(){
//	/*char* str1 = "hello word";
//	char* str2 = "llo";
//	mystrstr(str1,str2);
//		printf("%s",*blackptr);*/
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	//struct tagTest1
	//{
	//	short a;
	//	char d;
	//	long b;
	//	long c;
	//};
	//struct tagTest2
	//{
	//	long b;
	//	short c;
	//	char d;
	//	long a;
	//};
	//struct tagTest3
	//{
	//	short c;
	//	long b;
	//	char d;
	//	long a;
	//};
	//struct A
	//{
	//	int a;
	//	short b;
	//	int c;
	//	char d;
	//};
	//struct B
	//{
	//	int a;
	//	short b;
	//	char c;
	//	int d;
	//};
	//struct tagTest1 stT1;
	//struct tagTest2 stT2;
	//struct tagTest3 stT3;
	//struct A num1;
	//struct B num2;
	typedef struct A{
		int a;
		char b;
		short c;
		short d;
	}AA_t;
	 struct A num1;
	printf("%d", sizeof(num1));
	system("pause");
	return 0;
}