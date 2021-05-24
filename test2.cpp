#include<iostream>
#include<vector>
using namespace std;
int ROW, COL;
vector<vector<int>> maze;
vector<vector<int>> path_tmp;//��ʱ·��
vector<vector<int>> path_best;//���·��
void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//����i,j�Ѿ��߹���
	path_tmp.push_back({ i,j });
	//�ж��Ƿ񵽴����
	if (i == ROW - 1 && j == COL - 1) {
		//Ѱ�����·��
		if (path_best.empty() || path_best.size() > path_tmp.size())
			path_best = path_tmp;
	}
	//������
	if (j + 1 < COL && maze[i][j + 1] == 0)
		MazeTrack(i, j + 1);	
	//������
	if (j - 1 >= 0 && maze[i][j - 1] == 0)
		MazeTrack(i, j - 1);
	//������
	if (i - 1 >= 0 && maze[i - 1][j] == 0)
		MazeTrack(i - 1, j);
	//������
	if (i + 1 < ROW && maze[i + 1][j] == 0)
		MazeTrack(i + 1, j);
	maze[i][j] = 0;//���ݻָ�·��
	path_tmp.pop_back();
}
int main()
{
	cin >> ROW >> COL;
	maze = vector<vector<int>>(ROW, vector<int>(COL, 0));//�����Թ��ռ�
	path_tmp.clear();
	path_best.clear();
	//���������Թ�
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cin >> maze[i][j];
		}
	}
	MazeTrack(0, 0);//����ʼ��(0,0)��ʼ��
	for (int i = 0; i < path_best.size(); ++i) {
		cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
	}
	return 0;
}