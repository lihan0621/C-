#include <iostream>
#include <vector>
using namespace std;

void test()
{
	try
	{
		vector<int> v;
		v.at(3) = 10;
		//v.reserve(10000000);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "..." << endl;
	}
}

//void fun()
//{
//	//抛异常
//	throw "string error";
//}
//
//void test()
//{
//	try
//	{
//		fun();
//	}
//	catch (int err)
//	{
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (double d)
//	{
//	}
//	//catch (...)
//	//{
//	//	//捕获任意类型的异常
//	//	cout << "..." << endl;
//	//}
//}

int main()
{
	test();
	system("pause");
	return 0;
}