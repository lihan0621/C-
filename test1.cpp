/*
	DFS����
*/
#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
void dfs(vector<vector<char>>& map, int row, int col, vector<vector<bool>>& flag, size_t& count) {
	//�����λ���Ѿ���������,���ñ���
	if (flag[row][col]) {
		return;
	}
	//������λ��
	flag[row][col] = true;
	//�����λ���ǰ�ɫ��ש,��ֹͣ����
	if (map[row][col] == '#') {
		return;
	}
	//����Ϊ�ڴ�ש
	count++;
	//Ȼ��������λ�õ������ĸ�������б���
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
		//���վ���,����¼����λ��
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
		//��ʼ����
		size_t count = 0;
		dfs(map, row, col, flag, count);
		cout << count << endl;
	}
	return 0;
}
//=========================================================================
//�Ż�: ���������Բ��ø���,ÿ�߳�һ��,ֱ���ڵ�ͼ�Ͻ��б��

#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
void dfs(vector<vector<char>>& map, int row, int col, size_t& count) {
	if (map[row][col] == '#') {
		return;
	}
	map[row][col] = '#';
	//����Ϊ��ɫ��ש
	count++;
	//Ȼ��������λ�õ������ĸ�������б���
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
		//���վ���,����¼����λ��
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
		//��ʼ����
		size_t count = 0;
		dfs(map, row, col, count);
		cout << count << endl;
	}
	return 0;
}
