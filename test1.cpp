#include<iostream>
#include<string>
using namespace std;
//暴力求解
char getFirstOneChar_1(const string& str)
{
	int j = 0;
	for (int i = 0; i < str.size(); ++i) {
		for (j = 0; j < str.size(); ++j) {
			if (j == i)
				continue;
			if (str[j] == str[i])
				break;
		}
		if (j >= str.size())
			return str[i];
	}
	return -1;
}
//hash法
char getFirstOneChar_2(const string& str)
{
	char hash[256] = { 0 };
	for (int i = 0; i < str.size(); ++i)
		hash[str[i]]++;
	for (int i = 0; i < str.size(); ++i) {
		if (hash[str[i]] == 1)
			return str[i];
	}
	return -1;
}
//string类函数查找法
char getFirstOneChar_3(const string& str)
{
	for (int i = 0; i < str.size(); ++i) {
		int index1 = str.find(str[i]);
		int index2 = str.rfind(str[i]);
		if (index1 == index2)
			return str[i];
	}
	return -1;
}
int main()
{
	string str;
	char res;
	getline(cin, str);
	res = getFirstOneChar_3(str);
	if (res == -1)
		cout << -1 << endl;
	else 
		cout << res << endl;
	return 0;
}