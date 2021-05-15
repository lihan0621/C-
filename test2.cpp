#include<iostream>
#include<vector>
using namespace std;
class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		int sum = 0;
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (left[i] * right[i] == 0) {
				sum += left[i] + right[i];
			}
			else {
				left_sum += left[i];
				left_min = left_min < left[i] ? left_min : left[i];
				right_sum += right[i];
				right_min = right_min < right[i] ? right_min : right[i];
			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> left = { 0, 7, 1, 6 };
	vector<int> right = { 1, 5, 0, 6 };
	Gloves a;
	cout << a.findMinimum(n, left, right);
	return 0;
}