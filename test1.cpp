#include <stdio.h>

int Max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int(*p)(int a, int b) = Max;

	return 0;
}