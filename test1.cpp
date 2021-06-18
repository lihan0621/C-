/*
	DFS问题
*/
#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
void dfs(vector<vector<char>>& map, int row, int col, vector<vector<bool>>& flag, size_t& count) {
	//如果该位置已经遍历过了,则不用遍历
	if (flag[row][col]) {
		return;
	}
	//遍历该位置
	flag[row][col] = true;
	//如果该位置是白色瓷砖,则停止搜索
	if (map[row][col] == '#') {
		return;
	}
	//否则为黑瓷砖
	count++;
	//然后继续向该位置的其他四个方向进行遍历
	for (int i = 0; i < 4; ++i) {
		int x = row + direct[i][0];
		int y = col + direct[i][1];
		if ((x >= 0 && x < map.size()) && (y >= 0 && y < map[0].size())) {
			dfs(map, x, y, flag, count);
		}
	}
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m * n == 0) {
			continue;
		}
		//接收矩阵,并记录起点的位置
		vector<vector<char>> map(m, vector<char>(n));
		vector<vector<bool>> flag(m, vector<bool>(n, false));
		int row = 0;
		int col = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					row = i;
					col = j;
				}
			}
		}
		//开始遍历
		size_t count = 0;
		dfs(map, row, col, flag, count);
		cout << count << endl;
	}
	return 0;
}
//=========================================================================
//优化: 标记数组可以不用给出,每走出一步,直接在地图上进行标记

#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
void dfs(vector<vector<char>>& map, int row, int col, size_t& count) {
	if (map[row][col] == '#') {
		return;
	}
	map[row][col] = '#';
	//否则为黑色瓷砖
	count++;
	//然后继续向该位置的其他四个方向进行遍历
	for (int i = 0; i < 4; ++i) {
		int x = row + direct[i][0];
		int y = col + direct[i][1];
		if ((x >= 0 && x < map.size()) && (y >= 0 && y < map[0].size())) {
			dfs(map, x, y, count);
		}
	}
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m * n == 0) {
			continue;
		}
		//接收矩阵,并记录起点的位置
		vector<vector<char>> map(m, vector<char>(n));
		int row = 0;
		int col = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					row = i;
					col = j;
				}
			}
		}
		//开始遍历
		size_t count = 0;
		dfs(map, row, col, count);
		cout << count << endl;
	}
	return 0;
}
