#include<iostream>
#include<string>
using namespace std;
void strReverse(string& str)
{
	int start = 0;
	int end = str.size() - 1;
	while (start < end) {
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
int main()
{
	string str;
	cin >> str;
	strReverse(str);
	cout << str << endl;
	return 0;
}