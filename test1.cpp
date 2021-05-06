#include<iostream>
#include<stack>
using namespace std;
class Parenthesis
{
public:
	bool ChkParenthesis(string A, int n)
	{
		stack<char> sc;
		for (auto ch : A) {
			switch (ch) {
			case'(':
				sc.push(ch);
				break;
			case')':
				if (sc.empty()) {
					return false;
				}
				sc.pop();
			default:
				return false;
			}
		}
		return sc.empty();
	}
};
void test()
{
	Parenthesis s;
	s.ChkParenthesis("()()()",6);
}
int main()
{
	test();
	return 0;
}