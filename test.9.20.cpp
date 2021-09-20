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
	//��ʽ����ת��
	a = d;

	int* pa = &a;
	//ǿ������ת��
	a = (int)pa;

	int* p = (int*)malloc(4);

	//C++����ת����
	//1. static_cast: ֧�����е���ʽ����ת��
	//		���⣺Ҳ֧�ָ���ָ��/���õ�����ָ��/���õ�ת��
	//		��֧��������ǿ������ת��
	a = static_cast<int> (d);

	/*B* pb = new B;
	C* pc = (C*)pb;
	C* pc2 = static_cast<C*> (pb);*/

	//��֧��
	//a = static_cast<int> (pa);

	//2. reinterpret_cast: ֧��ǿ������ת��
	a = reinterpret_cast<int>(pa);

	//3. const_cast: ȥ��������const����
	const int c = 10;
	cout << "c: " << c << endl;
	int* ptr = const_cast<int*>(&c);
	*ptr = 20;
	cout << "c: " << c << endl;

	//4. dynamic_cast: ֻ���ڶ�̬�����µĸ�������/ָ������������/ָ��ת��
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