#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	//翻转整个句子
	reverse(s.begin(), s.end());
	//翻转整个单词
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		reverse(start, end);
		if (end != s.end())
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	cout << s << endl;
	return 0;
}