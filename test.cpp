#include <iostream>
#include <stack>
using namespace std;

void test()
{
	stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	cout << st.size() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}