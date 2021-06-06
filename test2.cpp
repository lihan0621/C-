#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		long long f0 = 1;
		long long f1 = 1;
		long long ret = 0;
		for (int i = 2; i <= n; i++) {
			ret = f0 + f1;
			f0 = f1;
			f1 = ret;
		}
		cout << ret << endl;
	}
	return 0;
}