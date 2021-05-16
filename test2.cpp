#include<iostream>
using namespace std;
int Count_Of_Perfect_Number(int n)
{
	int count = 0, sum = 0;
	for (int i = 2; i < n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			count++;
		}
		sum = 0;
	}
	return count;
}
int main()
{
	int n;
	int count;
	cin >> n;
	count = Count_Of_Perfect_Number(n);
	cout << count << endl;
	return 0;
}