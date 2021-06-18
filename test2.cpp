#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, k;
	while (cin >> m >> n >> k) {
		// 因为地图大小已经确定好了，map直接设置好大小
		vector<vector<int>> map(n + 1, vector<int>(m + 1));
		// 向地图中放入蘑菇
		int row, col;
		while (k--){
			cin >> row >> col;
			map[row][col] = 1;
		}
		vector<vector<double>> dp(n + 1, vector<double>(m + 1));
		dp[1][1] = 1.0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; ++j){
				// 对于每个位置，按照上述转移方程来确定概率
				if (!(i == 1 && j == 1))
					dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);
				// 如果该位置为蘑菇，表示不能到达该位置，则到达该位置的概率一定为0
				if (map[i][j])
					dp[i][j] = 0;
			}
		}
		printf("%.2f\n", dp[n][m]);
	}
	return 0;
}