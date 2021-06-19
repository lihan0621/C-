#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '_') {
				continue;
			}
			if (i > 0 && s[i - 1] == '_') {
				cout << (char)toupper(s[i]);
			}
			else {
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}