//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); ++itor)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); ++itor)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string a = "hello world";
//	string b = a;
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	string c = b;
//	c = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	a = "";
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
class Sample
{
public:
	Sample(int x)
	{
		p = new int(x);
		//p = &x;
		//*p = x;
	}
	~Sample()
	{
		if (p) delete p;
	}
	int show()
	{
		return *p;
	}
private:
	int* p;
};
int main()
{
	Sample s(5);
	cout << s.show() << endl;
	return 0;
}