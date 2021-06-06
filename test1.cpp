#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		getchar();
		string name;
		for (int i = 0; i < n; ++i) {
			getline(cin, name);
			if (name.find(',') == string::npos || name.find(' ') == string::npos) {
				cout << "\"" << name << "\"";
			}
			else {
				cout << name;
			}
			if (i != n - 1) {
				cout << ", ";
			}
			else {
				cout << endl;
			}
		}
	}

	return 0;
}