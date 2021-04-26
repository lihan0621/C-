//#include<iostream>
//#include<string>
//using namespace std;
//class A
//{
//	friend long fun(A  s) {
//		if (s.x < 3) {
//			return 1;
//		}
//		return s.x + fun(A(s.x - 1));
//	}
//public:
//	A(long a) {
//		x = a--;
//	}
//private:
//	long x;
//};
//int main()
//{
//	int sum = 0;
//	for (int i = 0; i < 5; i++) {
//		sum += fun(A(i));
//	}
//	cout << sum;
//	return 0;
//}
#include<iostream>
using namespace std;
class parent
{
	int i;
protected:
	int x;
public:
	parent()
	{
		x = 0;
		i = 0;
	}
	void change()
	{
		x++;
		i++;
	}
	void display();
};
class son :public parent
{
public:
	void modify();
};
void parent::display()
{
	cout << "x=" << x << endl;
}
void son::modify()
{
	x++;
}
int main()
{
	son A; parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();
	return 0;
}