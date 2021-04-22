#include<stdio.h>
#include<stdlib.h>
char * reverse_string(char *str){
	char *start = str;
	char *end = str + strlen(str )- 1;
	for (; start < end; start++,end--){
		char ch = *start;
		*start = *end;
		*end = ch;
	}
	return str;
}
int main(){
	char tmp[] = "hello bit!";
	printf("%s\n", reverse_string(tmp));
	system("pause");
	return 0;
}