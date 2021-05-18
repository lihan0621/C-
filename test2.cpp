#include<iostream>
#include<string>
using namespace std;
bool strMach(const char* pattern, const char* str)
{
	if (*pattern == '\0' && *str == '\0')
		return true;
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
		return strMach(pattern + 1, str + 1);
	else if (*pattern == '*')
		return strMach(pattern + 1, str + 1) || strMach(pattern, str + 1) || strMach(pattern + 1, str);
	else if (*pattern == *str)
		return strMach(pattern + 1, str + 1);
	else
		return false;
}
int main()
{
	string pattern, str;
	cin >> pattern >> str;
	bool ret = strMach(pattern.c_str(), str.c_str());
	if (ret)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}