#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//类
class CGoods
{
public:
	//成员方法
	void InitGoods(const char* n, float p, int c)
	{
		strcpy(name, n);
		price = p;
		count = c;
	}
	void SetName(char n[])
	{
		strcpy(name, n);
	}
	void GetName(char n[])
	{
		strcpy(n, name);
	}
	float GetPrice()
	{
		return price;
	}
	int GetCount()
	{
		return this->count;
	}
	float GetTotal()
	{
		return price * count;
	}
private:
	//数据成员
	char name[20];
	float price;
	int count;
};


void main()
{
	CGoods c1;  //实例对象
	CGoods c2;
	c1.InitGoods("C++.pdf", 56.6, 20);
	c2.InitGoods("JAVA.pdf", 40, 20);

	cout << "c1 count = " << c1.GetCount() << endl;
	cout << "c2 count = " << c2.GetCount() << endl;
}