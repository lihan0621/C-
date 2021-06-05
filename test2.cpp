#include <iostream>
using namespace std;

int main() {
	long long fib[80];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 80; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int from, to;
	cin >> from >> to;
	long long count = 0;
	for (int i = from - 1; i <= to - 1; ++i) {
		count += fib[i];
	}
	cout << count << endl;	

	return 0;
}		