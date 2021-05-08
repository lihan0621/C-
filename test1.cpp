//#include<iostream>
//using namespace std;
//void func(const int& a, const int& b)
//{
//	cout << a << " ";
//	cout << b << " ";
//}
//int main()
//{
//	int i = 0;
//	func(++i, i++);
//	return 0;
//}
//#include<iostream>
//#define SQR(A) A*A
//using namespace std;
//int main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= SQR(y + z) / SQR(y + z);
//	int a = SQR(y + z) / SQR(y + z);
//	int b = SQR(y + z);
//	cout << x << endl;
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}
//#include<stdio.h>
//#include<cstdint>
//#include<string.h>
//struct st_task
//{
//	uint16_t id;
//	uint32_t value;
//	uint64_t timestamp;
//};
//int main()
//{
//	st_task task = {};
//	uint64_t a = 0x00010001;
//	memcpy(&task, &a, sizeof(uint64_t));
//	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n[][3] = { 10,20,30,40,50,60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
//	return 0;
//}
#include <iostream>
using namespace std;
class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived :public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main()
{
	Derived Obj;
	Base* pObj = &Obj;
	cout << pObj->Bar((char)(100)) << endl;
	cout << pObj->Bar(100) << endl;
	return 0;
}