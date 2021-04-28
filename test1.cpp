#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789abcdef";
	int m, n;
	cin >> m >> n;
	bool flag = false;
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}
	while (m != 0)
	{
		s += table[m % n];
		m /= n;
	}
	if (flag == true)
	{
		s += "-";
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}