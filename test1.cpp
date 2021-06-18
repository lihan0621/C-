#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>

#define INF 1000000
using namespace std;

int main() {
	unordered_map<char, char> dic;
	dic.emplace('A', 2);
	dic.emplace('B', 2);
	dic.emplace('C', 2);
	dic.emplace('D', 3);
	dic.emplace('E', 3);
	dic.emplace('F', 3);
	dic.emplace('G', 4);
	dic.emplace('H', 4);
	dic.emplace('I', 4);
	dic.emplace('J', 5);
	dic.emplace('K', 5);
	dic.emplace('L', 5);
	dic.emplace('M', 6);
	dic.emplace('N', 6);
	dic.emplace('O', 6);
	dic.emplace('P', 7);
	dic.emplace('Q', 7);
	dic.emplace('R', 7);
	dic.emplace('S', 7);
	dic.emplace('T', 8);
	dic.emplace('U', 8);
	dic.emplace('V', 8);
	dic.emplace('W', 9);
	dic.emplace('X', 9);
	dic.emplace('Y', 9);
	dic.emplace('Z', 9);
	int n;
	while (cin >> n && n > 0) {
		set<string> hs;
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			string p = "";
			for (auto& c : s) {
				if (isdigit(c)) {
					p += c;
				}
				else if (isupper(c)) {
					p += dic[c];
				}
			}
			if (p.size() != 7) {
				continue;
			}
			p = p.substr(0, 3) + "-" + p.substr(3);
			hs.emplace(p);
		}
		for (auto& phone : hs) {
			cout << phone << endl;
		}
		cout << endl;
	}
	return 0;
}
