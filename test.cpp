//#include<iostream>
//#include <stack>
//using namespace std;
//int main()
//{
//	stack<char>S;
//	char x, y;
//	x = 'n';
//	y = 'g';
//	S.push(x);
//	S.push('i');
//	S.push(y);
//	S.pop();
//	S.push('r');
//	S.push('t');
//	S.push(x);
//	S.pop();
//	S.push('s');
//	while (!S.empty())
//	{
//		x = S.top();
//		S.pop();
//		cout << x;
//	}
//	cout << y;
//	return 0;
//}
//#include<iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//int main()
//{
//	queue<char>S;
//	char x, y;
//	x = 'n';
//	y = 'g';
//	S.push(x);
//	S.push('i');
//	S.push(y);
//	S.pop();
//	S.push('r');
//	S.push('t');
//	S.push(x);
//	S.pop();
//	S.push('s');
//	while (!S.empty())
//	{
//		x = S.front();
//		S.pop();
//		cout << x;
//	}
//	cout << y;
//	return 0;
//}
#include<iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	priority_queue<int>a;
	priority_queue<int, vector<int>, greater<int>>c;
	priority_queue<string>b;
	for (int i = 0; i < 5; ++i)
	{
		a.push(i);
		c.push(i);
	}
	while (!a.empty())
	{
		cout << a.top() << " ";
		a.pop();
	}
	cout << endl;
	while (!c.empty())
	{
		cout << c.top() << " ";
		c.pop();
	}
	cout << endl;
	b.push("abc");
	b.push("abcd");
	b.push("cbd");
	while (!b.empty())
	{
		cout << b.top() << " ";
		b.pop();
	}
	cout << endl;
	return 0;
}