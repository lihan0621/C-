#include<iostream>
#include<cmath>
using namespace std;
bool Is_prime(int num)
{
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	int num;
	cin >> num;
	for (int i = num / 2; i >= 0; i--) {
		if (Is_prime(i) && Is_prime(num - i)) {
			cout << i << endl << num - i << endl;
			break;
		}
	}
	return 0;
}