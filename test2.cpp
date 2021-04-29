#include<iostream>
#include<vector>
using namespace std;
int GetMax(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++)
	{
		cin >> nums[i];
	}
	int sum = nums[0];
	int max = nums[0];
	for (int i = 0; i < size; i++)
	{
		sum = GetMax(sum+nums[i],nums[i]);
		if (sum >= max)
		{
			max = sum;
		}
	}
	cout << max << endl;
	return 0;
}