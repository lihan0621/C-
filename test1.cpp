#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
size_t addItem(size_t a, size_t b, size_t& sign)
{
	size_t sum = a + b + sign;
	if (sum >= 10) {
		sum -= 10;
		sign = 1;
	}
	else 
		sign = 0;
	return sum;
}
string addString(string& num1, string& num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	size_t i, j;
	i = j = 0;
	string res = "";
	size_t sum, sign = 0;
	while (i < num1.size() && j < num2.size()) {
		sum = addItem(num1[i] - '0', num2[j] - '0', sign);
		//sum = num1[i] - '0' + num2[j] - '0' + sign;
		//if (sum >= 10) {
		//	sum -= 10;
		//	sign = 1;
		//}
		//else
		//	sign = 0;
		res += (sum + '0');
		i++;
		j++;
	}
	while (i < num1.size()) {
		sum = addItem(num1[i] - '0', 0, sign);
		//sum += num1[i] - '0' + sign;
		//if (sum >= 10) {
		//	sum -= 10;
		//	sign = 1;
		//}
		//else
		//	sign = 0;
		res += (sum + '0');
		i++;
	}
	while (j < num2.size()) {
		sum = addItem(0, num2[j] - '0', sign);
		//sum += num2[j] - '0' + sign;
		//if (sum >= 10) {
		//	sum -= 10;
		//	sign = 1;
		//}
		//else
		//	sign = 0;
		res += (sum + '0');
		j++;
	}
	if (sign)
		res += (sign + '0');
	reverse(res.begin(), res.end());
	return res;
}
bool isValid(const string& num)
{
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < '0' || num[i]>'9') {
			return false;
		}
	}
	return true;
}
int main()
{
	string num1, num2, res;
	cin >> num1 >> num2;
	if (isValid(num1) && isValid(num2)) {
		res = addString(num1, num2);
		cout << res << endl;
	}
	else
		cout << "error" << endl;
	return 0;
}