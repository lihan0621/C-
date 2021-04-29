#include<iostream>
#include<string>
using namespace std;
bool IsCircle(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		++begin;
		--end;
	}
	return true;
}
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;
	for (int i = 0; i < str1.size(); i++) {
		string str = str1;
		str.insert(i, str2);
		if (IsCircle(str))
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}