#include<stdio.h>
#include<stdlib.h>
void Statistics(int num) {
	int count = 0;
	while (num) {
		if (num & 1) {
			count++;
		}
		num = num >> 1;
	}
	printf("%d\n", count);
}
int main() {
	Statistics(7);
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//void Statistics(int num) {
//	int count = 0;
//	while (num) {
//		num = num & num - 1;
//		count++;
//	}
//	printf("%d\n", count);
//}
//int main() {
//	int num = 0;
//	scanf_s("%d", &num);
//	Statistics(num);
//	system("pause");
//	return 0;
//}