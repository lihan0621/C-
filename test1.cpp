//Ð¡ºï×Ó·ÖÌÒ
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	if (n == 0)
//		return 0;
//	long total = pow(5, n) - 4;
//	long left = pow(4, n) + n - 4;
//	cout << total << " " << left << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int addInOddEven(vector<int>& arr, int len)
	{
		int i = 0, j = 1;
		while (i < len && j < len) {
			if (arr[len - 1] % 2 == 0) {
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else {
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};
int main()
{
	return 0;
}