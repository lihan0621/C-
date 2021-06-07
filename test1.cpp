#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	string name;
	unordered_set<string> s;
	while (getline(cin, name)) {
		int i = 0, end = 0;
		while (i < name.size()) {
			if (name[i] == '\"') {
				end = name.find('"', i + 1);
				s.insert(name.substr(i + 1, end - i - 1));
				i = end + 2;
			}
			else {
				end = name.find(',', i + 1);
				if (end == string::npos) {
					s.insert(name.substr(i, name.size()));
					break;
				}
				s.insert(name.substr(i, end - i));
				i = end + 1;
			}
		}
		getline(cin, name);
		if (s.find(name) == s.end()) {
			cout << "Important" << endl;
		}
		else {
			cout << "Ignore" << endl;
		}
	}
	return 0;
}

