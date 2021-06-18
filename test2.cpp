#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, k;
	while (cin >> m >> n >> k) {
		// ��Ϊ��ͼ��С�Ѿ�ȷ�����ˣ�mapֱ�����úô�С
		vector<vector<int>> map(n + 1, vector<int>(m + 1));
		// ���ͼ�з���Ģ��
		int row, col;
		while (k--){
			cin >> row >> col;
			map[row][col] = 1;
		}
		vector<vector<double>> dp(n + 1, vector<double>(m + 1));
		dp[1][1] = 1.0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; ++j){
				// ����ÿ��λ�ã���������ת�Ʒ�����ȷ������
				if (!(i == 1 && j == 1))
					dp[i][j] = dp[i - 1][j] * (j == m ? 1 : 0.5) + dp[i][j - 1] * (i == n ? 1 : 0.5);
				// �����λ��ΪĢ������ʾ���ܵ����λ�ã��򵽴��λ�õĸ���һ��Ϊ0
				if (map[i][j])
					dp[i][j] = 0;
			}
		}
		printf("%.2f\n", dp[n][m]);
	}
	return 0;
}