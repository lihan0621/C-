#include<iostream>
#include<math.h>
using namespace std;
int Factornum(int n)
{
	int count = 0;
	for (int i = 2; i < sqrt(n); ++i) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			count++;
		}
	}
	if (n != 1)
		count++;
	return count;
}
int main()
{
	int n;
	cin >> n;
	int ret = Factornum(n);
	cout << ret << endl;
	return 0;
}