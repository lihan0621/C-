#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	//cin >> str1;
	//cin >> str2;  这里不能用cin，cin遇到空格就退出了
	getline(cin, str1);
	getline(cin, str2);
	int hash[256] = { 0 };
	string ret = "";
	for (int i = 0; i < str2.size(); i++)
	{
		hash[str2[i]]++;
	}
	for (int i = 0; i < str1.size(); i++)
	{
		if (hash[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}