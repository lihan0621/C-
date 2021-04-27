#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int sum = 0;
	int n = 0;
	cin >> n;
	vector<int> arr;
	arr.resize(3 * n);
	for (int i = 0; i < (3 * n); ++i)
	{
		cin >> arr[i];
	}
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < n; ++i)
	{
		sum = sum + arr[arr.size() - (2 *  (i + 1))];
	}
	cout << sum << endl;
	return 0;
}