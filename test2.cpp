#include <iostream>
using namespace std;
int main() {
	long long d[21] = { 0 ,0 ,1 };
	long long f[21] = { 1, 1, 2 };
	for (int i = 3; i <= 20; i++) {
		d[i] = (i - 1) * (d[i] - 1 + d[i - 2]);
		f[i] = f[i - 1] * i;
	}
	int n;
	while (cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
	}
	return 0;
}