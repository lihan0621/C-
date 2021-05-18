#include<iostream>
using namespace std;
/*
//迭代法求解
int RabbitNums(int n)
{
	int sum = 0;
	if (n <= 2) return 1;
	int f, f1 = 1, f2 = 1;
	for (int i = 3; i <= n; ++i) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	return f;
}*/
//递归
int Fib(int n) 
{
	if (n <= 2) return 1;
	return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int month = 0;
	cin >> month;
	int ret = Fib(month);
	cout << ret << endl;
	return 0;
}