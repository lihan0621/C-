#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T >> n >> k;
	int num = 2 * n;
	vector<int> card(num);
	for (int i = 0; i < num; ++i)
		cin >> card[i];
	for (int i = 0; i < k; ++i) {
		vector<int> tmp(card.begin(), card.end());
		for (int j = 0; j < n; ++j) {
			card[2 * j] = tmp[j];//左手的牌排放的位置
			card[2 * j + 1] = tmp[j + n];//右手的牌排放的位置
		}
	}
	//输出洗牌的顺序
	for (int i = 0; i < num - 1; ++i) {
		cout << card[i] << " ";
	}
	cout << card[num - 1] << endl;//最后一张牌后面不能有空格
	return 0;
}