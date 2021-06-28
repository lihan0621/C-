#include <stdio.h>
#include <assert.h>

const char* myStrstr(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != '\0');
	assert(*str2 != '\0');
	/*if (*str1 == '\0')
		return "";*/
	const char* black = str1;
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		while (*red != '\0' && *sub != '\0' && *red == *sub) {
			red++;
			sub++;
		}
		//if (*red == '\0' || *red == *sub)
		//	continue;
		if(*sub == '\0')
			return black;
		black++;
	}
	return NULL;
	
}

void* myMemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != NULL);
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	for (size_t i = 0; i < num; i++) {
		cdest[i] = csrc[i];
	}
	return dest;
}
int main() {

	//int arr[] = { 1,2,3,4 };
	//int arr2[100] = { 0 };
	//myMemcpy(arr2, arr, sizeof(arr));
	//for (int i = 0; i < 4; i++) {
	//	printf("%d\n", arr2[i]);
	//}

	//int a = 10;
	//int b = 0;
	//myMemcpy(&a, &b, sizeof(a));
	//printf("b = %d", a);

	//const char* str1 = "hello world";
	//const char* str2 = "llo";
	//const char* ret = myStrstr(str1, str2);
	//printf("%s", ret);
	return 0;
}