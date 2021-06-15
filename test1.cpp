#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		//将s1和s2的长度补充到len2
		//注意: s1之后补'a', s2之后补'z'+1
		s1.append('a', len2 - s1.size());
		s2.append('z' + 1, len2 - s2.size());
		//使用s2和s1对应位置上的字符相减并保存
		vector<int> v(len2);
		for (int i = 0; i < len2; ++i) {
			v[i] = s2[i] - s1[i];
		}
		//计算结果
		long long result = 0;
		for (int i = len1; i <= len2; ++i) {
			for (int j = 0; j < i; ++j) {
				result += v[j] * pow(26, i - j - 1);
			}
		}
		cout << (result - 1) % 1000007 << endl;
	}
	return 0;
}