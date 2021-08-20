#include <iostream>

using namespace std;

class Person
{
public:
	string _name; // ����
};

class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};

class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

void test()
{
	cout << sizeof(Assistant) << endl; // 92byte
	Assistant ass;
	//���μ̳У� �����ԣ���������
	ass._name = "a";
	ass.Student::_name = "b";
	ass.Person::_name = "b";
}

//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	A(const A& a)
//		:_a(a._a)
//	{
//		cout << "A(const A&)" << endl;
//	}
//
//	A& operator=(const A& a)
//	{
//		if (this != &a)
//		{
//			_a = a._a;
//		}
//		cout << "A& operator=" << endl;
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//protected:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	//�����Ա������ø���Ĺ��캯����ɳ�ʼ��
//	//���๹���ڳ�ʼ���б��е���
//	B(int a, int b)
//		:A(a)
//		,_b(b)
//	{
//		cout << "B(int, int)" << endl;
//	}
//
//	//��ʾ����Ŀ������죬Ĭ�ϵ���A��Ĭ�Ϲ���
//	B(const B& b)
//		:A(b)
//		,_b(b._b)
//	{
//		cout << "B(const B&)" << endl;
//	}
//
//	//��ʾ����ĸ�ֵ������������Զ����ø���ĸ�ֵ�����
//	B& operator=(const B& b)
//	{
//		if (this != &b)
//		{
//			//���ø��ำֵ���������Ҫ���ϸ����������
//			// ����������operator=��ͬ������
//			A::operator=(b);
//			//_a = b._a;
//			_b = b._b;
//		}
//		cout << "B& operator=" << endl;
//		return *this;
//	}
//
//	//��ʾ����������������ں�����ִ����ɵ�ʱ��Ҳ���Զ����ø�������
//	~B()
//	{
//		cout << "~B()" << endl;
//		//����Ҫ��ʾ�������������������κ�����£������Զ����ø�������
//		//A::~A();
//	}
//
//protected:
//	int _b;
//};
//
//void test()
//{
//	//����Ĭ�ϵĹ��캯�����Զ����ø���Ĺ��캯��
//	//��ɸ����Ա�ĳ�ʼ��
//	B b(10, 100);
//
//	cout << "copy(b)" << endl;
//	//����Ĭ�ϵĿ������죬�Զ����ø���Ŀ�������
//	B copy(b);
//
//	cout << "b = copy" << endl;
//	//����ĸ�ֵ��������Զ����ø���ĸ�ֵ�����
//	b = copy;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//		cout << "Person::Print" << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//	int _stuId = 50;
//private:
//	int _id = 10;
//};
//
//class Student : public Person
//{
//public:
//	void Print(int a)
//	{
//		//ͬ�����أ����ඨ���˺͸���������ͬ�ĳ�Ա
//		cout << _name << _age << endl;
//		cout << _stuId << endl;
//		cout << "Student::Print" << endl;
//		//�����˽�г�Ա�������в��ɼ�
//		//cout << _id << endl;
//	}
//protected:
//	int _stuId = 100;
//};
//
//void test()
//{
//	Student stu;
//	//����ͬ�����أ�ֻҪ��������ͬ���ͻṹ��ͬ������
//	//���ø����Ա
//	stu.Person::Print();
//	//����������γ�Ա
//	stu.Print(10);
//}

//void test()
//{
//	Person p;
//	Student stu;
//	//��Ƭ���������ָ�룬���ø�ֵ���������ָ�룬����
//	//		����------>����
//	p = stu;
//	Person& rs = stu;
//	Student& rs2 = stu;
//	Person& rs3 = rs2;
//	Person* ps = &stu;
//	Student* ps2 = &stu;
//
//	//���ܰѸ������ֵ���������
//	//stu = p;
//	//����ָ�롢���ò���ֱ�Ӹ�ֵ������ָ������
//	//ps2 = ps;
//	//���ǿ���ͨ��ǿ������ת�����и�ֵ
//	ps2 = (Student*)ps;
//
//	int a = 10;
//	float f = 1.1;
//	a = f; //��ʽ����ת��
//}

//class Student : public Person
//{
//public:
//	int _stuid;
//	int _major;
//};
//
//class Empty
//{};
//
//void test()
//{
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}