#include<iostream>
using namespace std;
int main()
{
	int f, f1 = 0, f2 = 1;
	int N, left = 0, right = 0;
	cin >> N;
	while (1) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		if (f < N) {
			left = f;
		}
		else {
			right = f;
			break;
		}
	}
	cout << min(N - left, right - N) << endl;
	return 0;
}