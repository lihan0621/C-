#include <iostream>

using namespace std;

class Person
{
public:
	string _name; // 姓名
};

class Student : virtual public Person
{
protected:
	int _num; //学号
};

class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};

void test()
{
	cout << sizeof(Assistant) << endl; // 92byte
	Assistant ass;
	//菱形继承： 二义性，数据冗余
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
//	//父类成员必须调用父类的构造函数完成初始化
//	//父类构造在初始化列表中调用
//	B(int a, int b)
//		:A(a)
//		,_b(b)
//	{
//		cout << "B(int, int)" << endl;
//	}
//
//	//显示定义的拷贝构造，默认调用A的默认构造
//	B(const B& b)
//		:A(b)
//		,_b(b._b)
//	{
//		cout << "B(const B&)" << endl;
//	}
//
//	//显示定义的赋值运算符，不会自动调用父类的赋值运算符
//	B& operator=(const B& b)
//	{
//		if (this != &b)
//		{
//			//调用父类赋值运算符，需要加上父类的作用域
//			// 父类和子类的operator=是同名隐藏
//			A::operator=(b);
//			//_a = b._a;
//			_b = b._b;
//		}
//		cout << "B& operator=" << endl;
//		return *this;
//	}
//
//	//显示定义的析构函数，在函数体执行完成的时候，也会自动调用父类析构
//	~B()
//	{
//		cout << "~B()" << endl;
//		//不需要显示调用析构，编译器在任何情况下，都会自动调用父类析构
//		//A::~A();
//	}
//
//protected:
//	int _b;
//};
//
//void test()
//{
//	//子类默认的构造函数，自动调用父类的构造函数
//	//完成父类成员的初始化
//	B b(10, 100);
//
//	cout << "copy(b)" << endl;
//	//子类默认的拷贝构造，自动调用父类的拷贝构造
//	B copy(b);
//
//	cout << "b = copy" << endl;
//	//子类的赋值运算符，自动调用父类的赋值运算符
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
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
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
//		//同名隐藏：子类定义了和父类名称相同的成员
//		cout << _name << _age << endl;
//		cout << _stuId << endl;
//		cout << "Student::Print" << endl;
//		//父类的私有成员在子类中不可见
//		//cout << _id << endl;
//	}
//protected:
//	int _stuId = 100;
//};
//
//void test()
//{
//	Student stu;
//	//函数同名隐藏：只要函数名相同，就会构成同名隐藏
//	//调用父类成员
//	stu.Person::Print();
//	//调用子类带参成员
//	stu.Print(10);
//}

//void test()
//{
//	Person p;
//	Student stu;
//	//切片：子类对象，指针，引用赋值给父类对象，指针，引用
//	//		子类------>父类
//	p = stu;
//	Person& rs = stu;
//	Student& rs2 = stu;
//	Person& rs3 = rs2;
//	Person* ps = &stu;
//	Student* ps2 = &stu;
//
//	//不能把父类对象赋值给子类对象
//	//stu = p;
//	//父类指针、引用不能直接赋值给子类指针引用
//	//ps2 = ps;
//	//但是可以通过强制类型转换进行赋值
//	ps2 = (Student*)ps;
//
//	int a = 10;
//	float f = 1.1;
//	a = f; //隐式类型转换
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