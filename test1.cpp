#include <iostream>
#include <string>
#include <set>
using namespace std;

int main1() {
	int n;
	while (cin >> n) {
		string id, op;
		set<string> s;
		size_t maxCon = 0;
		while (n--) {
			cin >> id >> op;
			if (op == "connect") {
				s.insert(id);
			}
			else {
				s.erase(id);
			}
			maxCon = max(maxCon, s.size());
		}
		cout << maxCon << endl;
	}
	return 0;
}