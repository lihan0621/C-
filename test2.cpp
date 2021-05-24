#include<iostream>
#include<vector>
using namespace std;
int ROW, COL;
vector<vector<int>> maze;
vector<vector<int>> path_tmp;//临时路径
vector<vector<int>> path_best;//最佳路径
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//代表i,j已经走过了
	path_tmp.push_back({ i,j });
	//判断是否到达出口
	if (i == ROW - 1 && j == COL - 1) {
		//寻找最短路径
		if (path_best.empty() || path_best.size() > path_tmp.size())
			path_best = path_tmp;
	}
	//向右走
	if (j + 1 < COL && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);	
	//向左走
	if (j - 1 >= 0 && maze[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	//向上走
	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	//向下走
	if (i + 1 < ROW && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	maze[i][j] = 0;//回溯恢复路径
	path_tmp.pop_back();
}
int main()
{
	cin >> ROW >> COL;
	maze = vector<vector<int>>(ROW, vector<int>(COL, 0));//开辟迷宫空间
	path_tmp.clear();
	path_best.clear();
	//首先输入迷宫
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cin >> maze[i][j];
		}
	}
	MazeTrack(0, 0);//从起始点(0,0)开始走
	for (int i = 0; i < path_best.size(); ++i) {
		cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
	}
	return 0;
}