#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int getLuckyPacket(vector<int>& x, int n, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; ++i) {
		sum += x[i];
		multi *= x[i];
		//判断幸运与否
		if (sum > multi) {
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else {
			break;//回溯
		}
		sum -= x[i];
		multi /= x[i];
		//去重
		while (i < n - 1 && x[i] == x[i + 1]) {
			i++;
		}
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	return 0;
}