#include <iostream>
using namespace std;
class LCA
{
public:
	int getLCA(int a, int b)
	{
		while (a != b) {
			if (a > b) {
				a = a / 2;
			}
			else if (a < b) {
				b = b / 2;
			}
		}
			return a;
	}
};
int main()
{
	return 0;
}