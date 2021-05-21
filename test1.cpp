#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string cmd;
	cin >> n >> cmd;
	//将n首歌进行编号1~n,其中num代表当前光标所在的歌曲编号,first代表当前页的第一首歌曲的编号
	int num = 1, first = 1;
	if (n <= 4) {//歌曲总数 <= 4
		for (int i = 0; i < cmd.size(); ++i) {
			//解析命令
			if (num == 1 && cmd[i] == 'U') {
				num = n;
			}
			else if (num == n && cmd[i] == 'D') {
				num = 1;
			}
			else if (cmd[i] == 'D') {
				num--;
			}
			else {
				num++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << i << " ";
		}
		cout << endl;
		cout << num << endl;
	}
	else {//歌曲总数 > 4
		for (int i = 0; i < cmd.size(); ++i) {
			//解析命令
			if (first == 1 && num == 1 && cmd[i] == 'U') {
				first = n - 3;
				num = n;
			}
			else if (first == n - 3 && num == n && cmd[i] == 'D')
				first = num = 1;
			else if (first != 1 && num == first && cmd[i] == 'U') {
				first--;
				num--;
			}
			else if (first != n - 3 && num == first + 3 && cmd[i] == 'D') {
				first++;
				num++;
			}
			else if (cmd[i] == 'U')
				num--;
			else
				num++;
		}
		for (int i = first; i <= first + 3; ++i) {
			cout << i << " ";
		}
		cout << endl;
		cout << num << endl;
	}

	return 0;
}