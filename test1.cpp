//#include<iostream>
//#define ADD(x, y)  (x + y)
//#define CMP(x, y)  (x > y)
//using namespace std;
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//	//if (a + b > c && a + c > b && b + c > a)
//	if (CMP(ADD(a, b), c) && CMP(ADD(a, c), b) && CMP(ADD(b, c), a))
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	while (num2) {
		int tmp = num1 ^ num2;
		num2 = ((num1 & num2) << 1);
		num1 = tmp;
	}
	cout << num1 << endl;
	return 0;
}