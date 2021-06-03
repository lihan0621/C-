#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void factorization(int a, vector<int>& factors)
{
	factors.clear();
	for (int i = 2; a > 1 && i <= sqrt(a); ++i) {
		while (a % i == 0) {
			factors.push_back(i);
			a /= i;
		}
	}
	if (a > 1)
		factors.push_back(a);
}
int main()
{
	int a;
	vector<int> factors;
	while (cin >> a) {
		factorization(a, factors);
		cout << a << " = ";
		for (vector<int>::const_iterator p = factors.begin(); p != factors.end(); ++p) {
			cout << *p;
			if (p != factors.end() - 1)
				cout << " * ";
		}
		printf("\n");
	}
	return 0;
}