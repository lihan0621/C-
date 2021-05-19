#include<iostream>
#include<vector>
using namespace std;
//Õ·×ªÏà³ý·¨
int GCD(int a, int b)
{
	int c;
	while (c = a % b) {
		a = b;
		b = c;
	}
	return b;
}
int getPowerVal(int n, int power)
{
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < n; ++i) {
		if (power >= num[i])
			power += num[i];
		else
			power += GCD(power, num[i]);
	}
	return power;
}
int main()
{
	int n, a, power;
	cin >> n >> a;
	power = getPowerVal(n, a);
	cout << power << endl;
	return 0;
}