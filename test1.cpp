#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		int num = numbers[0];
		int flag = 1;
		if (size == 0) {
			return 0;
		}
		for (int i = 1; i < size; ++i) {
			if (num == numbers[i]) {
				flag++;
			}
			else {
				flag--;
			}
			if (flag == 0) {
				num = numbers[i];
				flag = 1;
			}
		}
		flag = 0;
		for (int i = 0; i < size; ++i) {
			if (num == numbers[i]) {
				flag++;
			}
		}
		if (flag * 2 > size) {
			return num;
		}
		return 0;
	}
};
int main() {
	Solution a;
	vector<int> numbers;
	for (int i = 0; i < numbers.size(); ++i) {
		cin >> numbers[i];
	}
	a.MoreThanHalfNum_Solution(numbers);
	return 0;
}