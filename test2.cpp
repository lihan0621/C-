#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> path(n);
		for (int i = 0; i < n; ++i) {
			cin >> path[i];
		}
		sort(path.begin(), path.end());
		vector<bool> flag(n, true);
		for (int i = 0; i < n - 1; ++i) {
			if (path[i] == path[i + 1]) {
				flag[i] = false;
			}
			if (path[i].size() < path[i + 1].size() && (path[i + 1].substr(0, path[i].size()) == path[i]
				&& path[i + 1][path[i].size()] == '/')) {
				flag[i] = false;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (flag[i]) {
				cout << "mkdir -p" << path[i] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}