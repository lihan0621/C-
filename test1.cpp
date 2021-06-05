#include <iostream>
#include <string>
using namespace std;

int cut(string s, string t) {
	int i = s.find(t);
	if (i == string::npos) {
		return 0;
	}
	return 1 + cut(s.substr(i + t.size()), t);
}
int main() {
	string s, t;
	cin >> s >> t;
	int ans = cut(s, t);
	cout << ans << endl;
	return 0;
}