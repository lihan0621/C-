//#include<iostream>
//using namespace std;
//int main()
//{
//	double n, a;
//	cin >> n >> a;
//	if (a >= (n * 2 * 3.14))
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
int Jump(int num)
{
	if (num == 1)
		return 1;
	else
		return 2 * Jump(num - 1);
}
int main()
{
	int num;
	cin >> num;
	int ret = Jump(num);
	cout << ret << endl;
	return 0;
}