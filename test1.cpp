#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		//��s1��s2�ĳ��Ȳ��䵽len2
		//ע��: s1֮��'a', s2֮��'z'+1
		s1.append('a', len2 - s1.size());
		s2.append('z' + 1, len2 - s2.size());
		//ʹ��s2��s1��Ӧλ���ϵ��ַ����������
		vector<int> v(len2);
		for (int i = 0; i < len2; ++i) {
			v[i] = s2[i] - s1[i];
		}
		//������
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