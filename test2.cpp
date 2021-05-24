#include<iostream>
#include<vector>
#include <map>
#include<algorithm>
using namespace std;
class Gift
{
public:
	/*
	int getValue(vector<int> gifts, int n)
	{
		map<int, int> val_count_map;
		for (const auto& e : gifts)
			val_count_map[e]++;
		for (const auto& e : val_count_map) {
			if (e.second > n / 2)
				return e.first;
		}
		return 0;
	}*/
	int getValue(vector<int> gifts, int n)
	{
		sort(gifts.begin(), gifts.end());
		int mid_val = gifts[n / 2];
		int count = 0;
		for (const auto& e : gifts) {
			if (e == mid_val)
				count++;
		}
		if (count > n / 2)
			return mid_val;
		return 0;
	}
};
int main()
{
	Gift a;
	vector<int> gifts = { 1,2,3,2,2 };
	cout << a.getValue(gifts, 5) << endl;
	return 0;
}