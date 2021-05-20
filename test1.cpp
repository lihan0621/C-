#include<iostream>
#include<string>
#include<vector>
using namespace std;
int getMaxComSubstr(const string& str1, const string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int max_len = 0;
	vector<vector<int>> msc(len1, vector<int>(len2, 0));
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (str2[j] == str1[i]) {
				if (i >= 1 && j >= 1)
					msc[i][j] = msc[i - 1][j - 1] + 1;
				else
					msc[i][j] = 1;
				if (msc[i][j] > max_len)
					max_len = msc[i][j];
			}
		}
	}
	return max_len;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int max_len = getMaxComSubstr(str1, str2);
	cout << max_len << endl;
	return 0;
}