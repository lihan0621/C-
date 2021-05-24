#include<iostream>
#include<vector>
using namespace std;
class Bonus
{
public:
	int getMost(vector< vector<int>> board)
	{
		int row = board.size();
		int col = board[0].size();
		vector<vector<int>> allPrice(row, vector<int> (col, 0));
		allPrice[0][0] = board[0][0];
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == 0 && j == 0)
					continue;
				if (i == 0)//在第一行只能往右走
					allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
				else if (j == 0)
					allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
				else
					allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j] + board[i][j]);
			}
		}
		return allPrice[row - 1][col - 1];
	}
};
int main()
{
	return 0;
}