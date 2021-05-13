#include<iostream>
#include<vector>
#include<limits>
#include<math.h>
using namespace std;
void get_div_num(int v, vector<int>& a)
{
	for (int i = 2; i <= sqrt(v); ++i) {
		if (v % i == 0) {
			a.push_back(i);
			if (v / i != i)
				a.push_back(v / i);
		}
	}
}
int Jump(int n, int m)
{
	vector<int> step(m + 1, INT_MAX);//int_max表示不可到达
	step[n] = 0;//当前的位置初始化
	for (int i = 0; i < m; ++i) {
		if (step[i] == INT_MAX)
			continue;
		//获取i的约数并保存
		vector<int> a;
		get_div_num(i, a);
		for (int j = 0; j < a.size(); ++j) {
			if (a[j] + i <= m && step[a[j] + i] != INT_MAX) {
				//需要挑选一个最小值
				step[a[j] + i] = step[a[j] + i] < step[i] + 1 ? step[a[j] + i] : step[i] + 1;
			}
			else if (a[j] + i <= m) {
				step[a[j] + i] = step[i] + 1;
			}
		}
	}
	return step[m] == INT_MAX ? -1 : step[m];
}
int main()
{
	int n, m, min_step;
	cin >> n >> m;
	min_step = Jump(n, m);
	cout << min_step << endl;
	return 0;
}