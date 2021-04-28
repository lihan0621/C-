#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (b - d) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2) cout << "NO";
	else cout << A << " " << B1 << " " << C << endl;
	return 0;
}