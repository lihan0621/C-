//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o %o\n", m, n);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}
#include<iostream>
using namespace std;
int f(int n)
{
	if (n == 1)
		return 1;
	else
		return (f(n - 1) + n * n * n);
}
int main()
{
	int s = f(3);
	cout << s << endl;
	return 0;
}