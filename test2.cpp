#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(const string& m, const string& n) {
	int mlen = m.size();
	int nlen = n.size();
	vector<vector<int>> dp(mlen + 1, vector<int> (nlen + 1));
	for (int i = 1; i <= mlen; ++i) {
		for (int j = 1; j <= nlen; ++j) {
			if (m[i - 1] == n[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[mlen][nlen];
}
int main() {
	string m, n;
	while (cin >> m >> n) {
		cout << LCS(m, n) << endl;
	}
	return 0;
}