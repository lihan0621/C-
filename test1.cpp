#include<iostream>
#define ADD(x, y)  (x + y)
#define CMP(x, y)  (x > y)
using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	//if (a + b > c && a + c > b && b + c > a)
	if (CMP(ADD(a, b), c) && CMP(ADD(a, c), b) && CMP(ADD(b, c), a))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}