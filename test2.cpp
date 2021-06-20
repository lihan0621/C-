#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isBrother(string res, string s) {
	if (res == s) {
		return false;
	}
	sort(res.begin(), res.end());
	sort(s.begin(), s.end());
	if (res == s) {
		return true;
	}
	return false;
}
int main() {
	int num;
	while (cin >> num) {
		string str;
		string word, s;
		vector<string> vs;
		int index;
		for (int i = 0; i < num; ++i) {
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());
		cin >> word;
		cin >> index;
		int count = 0;
		for (int i = 0; i < num; ++i) {
			if (isBrother(word, vs[i])) {
				count++;
			}
			if (count == index) {
				s = vs[i];
			}
		}
		if (!vs.empty()) {
			cout << count << endl;
		}
		if (count >= index) {
			cout << s << endl;
		}
	}
	return 0;
}