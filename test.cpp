#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char ch;
	cin >> ch;
	if (isalpha(ch))
		cout << "yes" << endl;
	system("pause");
	return 0;
}