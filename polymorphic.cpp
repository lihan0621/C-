#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		cout << "Base::f()" << endl;
	}
	virtual void g()
	{
		cout << "Base::g()" << endl;
	}
	virtual void h()
	{
		cout << "Base::h()" << endl;
	}
};

class Base1
{
public:
	virtual void f()
	{
		cout << "Base1::f()" << endl;
	}
	virtual void g()
	{
		cout << "Base1::g()" << endl;
	}
	virtual void h()
	{
		cout << "Base1::h()" << endl;
	}
};
class Base2
{
public:
	virtual void f()
	{
		cout << "Base2::f()" << endl;
	}
	virtual void g()
	{
		cout << "Base2::g()" << endl;
	}
	virtual void h()
	{
		cout << "Base2::h()" << endl;
	}
};

class D :public Base, public Base1, public Base2
{
public:
	virtual void f1()
	{
		cout << "D::f1()" << endl;
	}
	virtual void g1()
	{
		cout << "D::g1()" << endl;
	}
	virtual void h1()
	{
		cout << "D::h1()" << endl;
	}
};
void main()
{
	D d;
}

/*
typedef void(*pFun)();
class Base
{
public:
	virtual void f()
	{
		cout << "Base::f()" << endl;
	}
	virtual void g()
	{
		cout << "Base::g()" << endl;
	}
	virtual void h()
	{
		cout << "Base::h()" << endl;
	}
private:
	int m_a = 0;
	int m_b = 1;
};

void main()
{
	Base b;
	printf("对象的地址：0x%p\n", &b);
	printf("虚表的地址：0x%p\n", *(int*)&b);

	pFun pfun;
	pfun = (pFun)(*((int*)(*(int*)&b) + 0));
	pfun();

	pfun = (pFun)(*((int*)(*(int*)&b) + 1));
	pfun();

	pfun = (pFun)(*((int*)(*(int*)&b) + 2));
	pfun();
}

/*
//抽象类
class A
{
public:
	//接口
	virtual void Eat() = 0;   //纯虚函数
	virtual void Sleep() = 0;
	virtual void Foot() = 0; 
};

class Dog :public A
{
public:
	virtual void Eat()
	{
		cout << "Dog::Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Dog::Sleep()" << endl;
	}
	virtual void Foot()
	{
		cout << "Dog::Foot()" << endl;
	}
};

class Pig :public A
{
public:
	virtual void Eat()
	{
		cout << "Pig::Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Pig::Sleep()" << endl;
	}
	virtual void Foot()
	{
		cout << "Pig::Foot()" << endl;
	}
};
////////////////////////////////////
//运行时的多态
void Active(A& pa)
{
	pa.Eat();
	pa.Foot();
	pa.Sleep();
}

void main()
{
	//A a;
	Dog dog;
	Active(dog);
}

/*
class A
{
public:
	virtual void Eat()
	{
		cout << "A::Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "A::Sleep()" << endl;
	}
	virtual void Foot()
	{
		cout << "A::Foot()" << endl;
	}
};

class Dog :public A
{
public:
	virtual void Eat()
	{
		cout << "Dog::Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Dog::Sleep()" << endl;
	}
	virtual void Foot()
	{
		cout << "Dog::Foot()" << endl;
	}
};

class Pig :public A
{
public:
	virtual void Eat()
	{
		cout << "Pig::Eat()" << endl;
	}
	virtual void Sleep()
	{
		cout << "Pig::Sleep()" << endl;
	}
	virtual void Foot()
	{
		cout << "Pig::Foot()" << endl;
	}
};
////////////////////////////////////
//运行时的多态
void Active(A& pa)
{
	pa.Eat();
	pa.Foot();
	pa.Sleep();
}

void main()
{
	Dog dog;
	Active(dog);
}

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}
/*
class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	}
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
	virtual void list()
	{
		cout << "Base::list()" << endl;
	}
	void print()
	{
		cout << "Base::print()" << endl;
	}
private:
	int m_base = 1;
};

class D :public Base
{
public:
	D()
	{
		cout << "D::D()" << endl;
	}
public:
	virtual void fun()
	{
		cout << "D::fun()" << endl;
	}
	virtual void show()
	{
		cout << "D::show()" << endl;
	}
private:
	int m_d = 2;
};

void main()
{
	D d;
}

/*
class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
		//this->fun();//虚机制在构造函数中不起作用
	}
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
public:
	void list()
	{
		fun();
	}
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
private:
	int m_a = 0;
};

class D :public Base
{
public:
	D()
	{
		cout << "D::D()" << endl;
	}
	virtual ~D()
	{
		cout << "D::~D()" << endl;
	}
public:
	virtual void fun()
	{
		cout << "D::fun()" << endl;
	}
private:
	int m_b = 0;
};

void main()
{
	D d;
	d.list();
}

/*
void main()
{
	Base* pb = new D;
	delete pb;
}

/*
class Base
{
public:
	virtual Base* fun()
	{
		cout << "Base::fun()" << endl;
		return this;
	}
private:
	int m_a = 0;
};

class D :public Base
{
public:
	virtual D* fun()
	{
		cout << "D::fun()" << endl;
		return this;
	}
private:
	int m_a = 0;
};

void main()
{
	Base* pb = new D;
	pb->fun();
}

/*
void main()
{
	Base b;
	cout << sizeof(Base) << endl;
}

/*
class Base
{
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
};

class D :public Base
{
public:
	//重写 
	void fun()
	{
		cout << "D::fun()" << endl;
	}
};

int main()
{
	Base* pb = new D;
	pb->fun();

	system("pause");
	return 0;
}

/*
int main()
{
	D d;
	Base& rb = d;
	rb.fun();

	system("pause");
	return 0;
}

/*
int main()
{
	D d;
	Base* pb = &d;
	pb->fun();

	system("pause");
	return 0;
}

/*
class A
{
public:
	virtual void Eat()
	{
		cout << "A::Eat()" << endl;
	}
	virtual void Foot()
	{
		cout << "A::Foot()" << endl;
	}
	virtual void Sleep()
	{
		cout << "A::Sleep()" << endl;
	}
};

class Person :public A
{
public:
	void Eat()
	{
		cout << "Person::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Person::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Person::Sleep()" << endl;
	}

};

class Bird :public A
{
public:
	void Eat()
	{
		cout << "Bird::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Bird::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Bird::Sleep()" << endl;
	}
};

class Dog :public A
{
public:
	void Eat()
	{
		cout << "Dog::Eat()" << endl;
	}
	void Foot()
	{
		cout << "Dog::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "Dog::Sleep()" << endl;
	}
};

//多态  完成不同的功能
void Active(A* pb)
{
	pb->Eat();
	pb->Foot();
	pb->Sleep();
}

int main()
{
	Person p;
	Bird b;
	Dog d;

	Active(&p);

	system("pause");
	return 0;
}

/*
class A
{
public:
	void Eat()
	{
		cout << "A::Eat()" << endl;
	}
	void Foot()
	{
		cout << "A::Foot()" << endl;
	}
	void Sleep()
	{
		cout << "A::Sleep()" << endl;
	}
};

class Person :public A
{};

class Bird :public A
{};

class Wheel
{};

class Dool
{};

class Car
{
private:
	Wheel tow[2];
	Dool four[4];
};

/*
class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};

class D : public Base
{
public:
	//同名隐藏
	void fun()
	{
		cout << "D::fun(int, int, int)" << endl;
	}
	void fun(int a)
	{
		cout << "D::fun(int)" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
	}
private:
	int m_c = 0;
};

int main()
{
	D d;
	Base* pb = &d;
	pb->fun();
	//pb->fun(1);
	//pb->show();

	system("pause");
	return 0;
}
/*
class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int a)
	{
		cout << "Base::fun(int)" << endl;
	}
	void fun(int a, int b)
	{
		cout << "Base::fun(int, int)" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};

class D : public Base
{
public:
	//同名隐藏
	void fun(int a, int b, int c)
	{
		cout << "D::fun(int, int, int)" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
	}
private:
	int m_c = 0;
};

int main()
{
	D d;
	Base* pb = &d;
	pb->fun();
	system("pause");
	return 0;
}

/*
//赋值兼容规则
int main()
{
	Base b;
	D d;

	b = d;
	Base* pb = &d;
	Base& rb = d;    //初始化

	system("pause");
	return 0;
}

/*
int main()
{
	D d;
	//d.fun();
	//d.fun(1);
	//d.fun(1, 2);
	d.fun(1, 2, 3);
	system("pause");
	return 0;
}
*/