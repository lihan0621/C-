#include <iostream>
using namespace std;

int main() {
	long long arr[100000];
	int border = -1;
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < 100000; ++i) {
		long long next = arr[i - 1] + arr[i - 2];
		if (border == -1 && next >= 100000) {
			border = i + 1;
		}
		arr[i] = next % 1000000;
	}
	int n;
	cin >> n;
	long long f = arr[n - 1];
	if (n >= border) {
		printf("%06lld\n", f);
	}
	else {
		printf("%lld\n", f);
	}
	return 0;
}