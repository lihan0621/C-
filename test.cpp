#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	int m_a = 1;
};

class B : virtual public A
{
public:
	int m_b = 2;
};

class C : virtual public A
{
public:
	int m_c = 3;
};

class D :public B, public C
{
public:
	int m_d = 4;
};

void main()
{
	D d;
	cout << d.m_d << endl;
	cout << d.m_c << endl;
	cout << d.m_b << endl;
	cout << d.m_a << endl;
	cout << d.B::m_a << endl;
	cout << d.C::m_a << endl;
	//cout << d.A::m_a << endl;
}

#if 0
class Person
{
public:
	Person() { ++_count; }
protected:
	string _name; // ����
public:
	static int _count; // ͳ���˵ĸ�����
};


int Person::_count = 0;


class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};


class Graduate : public Student
{
protected:
	string _seminarCourse; // �о���Ŀ
};


void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " ���� :" << Person::_count << endl;
	Student::_count = 0;
	cout << " ���� :" << Person::_count << endl;
}

int main()
{
	TestPerson();
	return 0;
}


class Student;

class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};

class Student : public Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	int _stuNum; // ѧ��
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
int main()
{
	Person p;
	Student s;
	Display(p, s);
	return 0;
}


class A
{
public:
	A(int a) :m_a(a) {
		cout << "A::A()" << endl;
	}
	~A() {
		cout << "A::~A()" << endl;
	}
private:
	int m_a;
};
class B
{
public:
	B(int b) :m_b(b) {
		cout << "B::B()" << endl;
	}
	~B() {
		cout << "B::~B()" << endl;
	}
private:
	int m_b;
};
class C
{
public:
	C(int c) :m_c(c) {
		cout << "C::C()" << endl;
	}
	~C() {
		cout << "C::~C()" << endl;
	}
private:
	int m_c;
};

class D :public A, public B, public C
{
public:
	D(int d = 0) :m_d(d), A(1), B(2), C(3), a(10), b(20), c(30) {
		cout << "D::D()" << endl;
	}
	~D() {
		cout << "~D::D()" << endl;
	}
private:
	int m_d;
	A a;
	B b;
	C c;
};

int main()
{
	D d;
	
	return 0;
}

class Base
{
public:
	Base(int a) :m_a(a) {
		cout << "Base::Base()" << endl;
	}
	Base(const Base& b) {
		cout << "Base::Base(const Base&)" << endl;
	}
	Base& operator=(const Base& b) {
		//cout << "+++++++++++++++++++++++" << endl;
		if (this != &b)
		{
			m_a = b.m_a;
		}
		return *this;
	}
	~Base() {
		cout << "Base::~Base()" << endl;
	}
private:
	int m_a;
};

class D : public Base
{
public:
	D(int d = 0) :m_d(d), Base(d) {
		cout << "D::D()" << endl;
	}
	D(const  D& d) :Base(d) {
		cout << "D::D(const D&)" << endl;
	}
	D& operator=(const D& d) {
		//cout << "--------------" << endl;
		if (this != &d)
		{
			Base::operator=(d);
			m_d = d.m_d;
		}
		return *this;
	}
	~D() {
		cout << "D::~D()" << endl;
	}
private:
	int m_d;
};

int main()
{
	D d;
	D d1 = d;
	D d2;
	d2 = d;

	return 0;
}


class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};

int main()
{
	B b;
	b.fun(0);
}


class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
};

int main()
{
	Student s;
	s.Print();
}




//��ֵ���ݹ���
class Base
{
public:
	Base(int a = 0) :m_a(a) {
		//cout << "Base::Base()" << endl;
	}
	~Base() {
		//cout << "Base::~Base()" << endl;
	}
public:
	void fun() {
		cout << "Base::fun()" << endl;
	}

	void fun(int a) {
		cout << "Base::fun(int)" << endl;
	}

	void list() {
		cout << "Base::list()" << endl;
	}

private:
	int m_a;
};

class D : public Base
{
public:
	D(int d = 0) :m_d(d) {
		//cout << "D::D()" << endl;
	}
	~D() {
		//cout << "D::~D()" << endl;
	}
public:
	void show() {
		cout << "D::show()" << endl;
	} 
	//ͬ������
	void fun()  {
		cout << "D::fun()" << endl;
	}
private:
	int m_d;
};

void main()
{
	Base b;
	D d;

	//Base* pb = &d;
	//pb->show();

	d.fun();
	//d.fun(0);
	d.Base::fun(0);
}


void main()
{
	Base b;
	D d;
	//b = d;
	//b.fun();  //���������ֵ��������󣬸�����õ��Ǹ��෽��

	//Base* pb = &d;
	//pb->fun();

	//Base& rb = d;
	//rb.fun();
}

void main()
{
	Base b;
	D d;
	b.fun();
	//b.show();
	d.show();
	d.fun();
}

void main()
{
	D d;
	Base b;
	b = d;         //1.���������Ը��������ֵ
	Base* pb = &d; //2.�������ĵ�ַ���Ը���������ָ�븳ֵ
	Base& rb = d;  //3.���������Ը������������ø�ֵ
}

class Base
{
public:
	void Call_fun()
	{
		fun();
	}
private:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
};

//��ֹ����
class D : private Base
{};

void main()
{
	D d;
	//d.Call_fun();
}


//����
class A
{
public:
	A(int a = 0) : m_a(a)
	{
		cout << "A::A()" << endl;
	}
public:
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
protected:
	void show()
	{
		cout << "This is A::show()" << endl;
	}
private:
	void print()
	{
		cout << "This is A::print()" << endl;
	}
private:
	int m_a;
};

//������
class D : private A
{
public:
	D(int d = 0) : m_d(d)
	{
		cout << "D::D()" << endl;
	}
public:
	void list()
	{
		fun();
		show();
		//print();
	}
private:
	int m_d;
};

class D1 : public D
{
public:
	void fun1()
	{
		//fun();
		//show();
	}
};

void main()
{
	D d;
	//d.fun();
	system("pause");
}



//����
class A
{
public:
	A(int a = 0) : m_a(a)
	{
		cout << "A::A()" << endl;
	}
public:
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
protected:
	void show()
	{
		cout << "This is A::show()" << endl;
	}
private:
	void print()
	{
		cout << "This is A::print()" << endl;
	}
private:
	int m_a;
};

//������
class D : protected A
{
public:
	D(int d = 0) : m_d(d)
	{
		cout << "D::D()" << endl;
	}
public:
	void list()
	{
		show();
		//print();
	}
private:
	int m_d;
};

void main()
{
	D d;
	//d.fun();
	system("pause");
}


//����
class A
{
public:
	A(int a = 0) : m_a(a)
	{
		cout << "A::A()" << endl;
	}
public:
	void fun()
	{
		cout << "This is A::fun()" << endl;
	}
protected:
	void show()
	{
		cout << "This is A::show()" << endl;
	}
private:
	void print()
	{
		cout << "This is A::print()" << endl;
	}
private:
	int m_a;
};

//������
class D : public A
{
public:
	D(int d = 0) : m_d(d)
	{
		cout << "D::D()" << endl;
	}
public:
	void list()
	{
		show();
		//print();
	}
private:
	int m_d;
};

void main()
{
	//cout << sizeof(A) << endl;
	//cout << sizeof(D) << endl;
	D d;
	d.fun();
	d.list();
	system("pause");
}


class Person
{
public:
	void Prite()
	{
		cout << m_name << " : " << m_age << endl;
	}
private:
	string m_name = "bite";
	int m_age = 5;
};

class Student : public Person
{
public:
	Student(string name, int age)
		:m_name(name)
		, m_age(age)
	{}
};


int main()
{
	Student s("xxx", 20);
	s.Prite();
	system("pause");
	return 0;
}

int main()
{
	Person p;
	p.Prite();
	Student s;
	s.Prite();
	system("pause");
	return 0;
}
#endif
