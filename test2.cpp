#include<iostream>
#include<vector>
using namespace std;
int FindIndex(int n)
{
	//�Ȳ���n�е����������
	int m = 2 * n - 1;//��n�о��е�Ԫ�ظ���
	vector<vector<int>> ivv(n, vector<int>(m, 0));
	ivv[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		ivv[i][0] = ivv[i][2 * i] = 1;//��һ�к͵ڶ���
		for (int j = 1; j < 2 * i; ++j) {
			if (j == 1) {//�ڶ���
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
			else if (j == 2 * i - 1) {//�����ڶ���
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1];
			}
			else {
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1] + ivv[i - 1][j];
			}
		}
	}
	//��ѯ��n�е�ż�����ڵ�λ��
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