#include<iostream>
#include<vector>
using namespace std;
int FindIndex(int n)
{
	//先产生n行的类杨辉三角
	int m = 2 * n - 1;//第n行具有的元素个数
	vector<vector<int>> ivv(n, vector<int>(m, 0));
	ivv[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		ivv[i][0] = ivv[i][2 * i] = 1;//第一列和第二列
		for (int j = 1; j < 2 * i; ++j) {
			if (j == 1) {//第二列
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
			else if (j == 2 * i - 1) {//倒数第二列
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1];
			}
			else {
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
		}
	}
	//查询第n行的偶数所在的位置
	for (int k = 0; k < m; ++k) {
		if (ivv[n - 1][k] % 2 == 0) {
			return k + 1;
		}
	}
	return -1;
}
int main()
{
	int n, index;
	cin >> n;
	index = FindIndex(n);
	cout << index << endl;
	return 0;
}