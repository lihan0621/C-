#include <iostream>
using namespace std;

class B
{
public:
	virtual	void fun(){}
};

class C : public B
{};

void test()
{
	int a = 10;
	double d = 1.2;
	//隐式类型转换
	a = d;

	int* pa = &a;
	//强制类型转换
	a = (int)pa;

	int* p = (int*)malloc(4);

	//C++类型转换：
	//1. static_cast: 支持所有的隐式类型转换
	//		特殊：也支持父类指针/引用到子类指针/引用的转换
	//		不支持其他的强制类型转换
	a = static_cast<int> (d);

	/*B* pb = new B;
	C* pc = (C*)pb;
	C* pc2 = static_cast<C*> (pb);*/

	//不支持
	//a = static_cast<int> (pa);

	//2. reinterpret_cast: 支持强制类型转换
	a = reinterpret_cast<int>(pa);

	//3. const_cast: 去除变量的const属性
	const int c = 10;
	cout << "c: " << c << endl;
	int* ptr = const_cast<int*>(&c);
	*ptr = 20;
	cout << "c: " << c << endl;

	//4. dynamic_cast: 只用于多态场景下的父类引用/指针向子类引用/指针转换
	B* pb = new B;
	C* pc = dynamic_cast<C*>(pb);
	C* pc2 = static_cast<C*>(pb);
	cout << pc << endl;
	cout << pc2 << endl;

	B* pb2 = new B;
	pc = dynamic_cast<C*>(pb2);
	pc2 = static_cast<C*>(pb2);
	cout << pc << endl;
	cout << pc2 << endl;


}

int main()
{
	test();
	system("pause");
	return 0;
}