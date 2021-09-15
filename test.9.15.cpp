#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef int(*ptr)(int);
void test()
{
	//lambda表达式：[捕捉列表] (参数列表) (mutable可选)->返回值类型 {函数体}
	//捕捉列表：捕捉父作用域中的变量
	int a = 10;
	int b = 20;
	[a, b] {return a + b; };
	//参数列表：类似于函数的参数列表
	[a, b](int c, int d, int e) {return a + b + c; };
	//返回值：类似于函数的返回值
	[a, b](int c)->int {return a + b + c; };
	//函数体：类似于函数的函数体：可以有多句指令
	//mutable：修改捕捉列表中变量的属性为非const，默认为const属性
	//[a, b] (int c)->{a = 10; }; //a,b的属性默认为const
	[a, b](int c) mutable->int {a = 10; b = 200; };
	//参数列表和返回值可以省略
	[] {};
	//返回值类型一般不用写，编译器会自动推导
	[a, b] {return a + b; };
	//如果有mutable, 即使参数列表为空，也需要显示写出来
	[a, b]()mutable {return a + b; };

	auto f = [a, b](int c) {return a + b + c; };
	//以上都为定义，上面的指令都不会运行
	int e = f(10);
	cout << e << endl;
	//[=]: 以值的形式捕捉父作用域中的所有变量
	auto f2 = [=]() {return a + b + e; };
	//[&]: 以引用的形式捕捉父作用域中的所有变量
	auto f3 = [&]() {a = 1; b = 1000; };
	f3();
	//[=, &变量x]: x以引用的形式捕捉，其他以值的形式捕捉
	//[&, 变量x]: x以值的形式捕捉，其他的以引用形式捕捉
	//错误的捕捉方式: [=, 变量x]，[&, &变量x]
	auto f4 = [&, a]() {return a + b; };
	auto f5 = [=, &a, &e]() {return a + b + e; };
	//[this]: 捕捉成员函数中的this指针

	//lambda表达式之间不能相互赋值
	auto f = [](int a) {return a; };
	auto f2 = [](int a) {return a; };
	//f = f2;
	//允许拷贝
	auto f3(f);
	ptr f4 = f;
	f4();
}

struct A
{
	void fun(int a)
	{
		auto f = [this]() {return this->_a; };
	}
	int _a;
};

//在块作用域以外的lambda函数捕捉列表必须为空
int g = 10;
auto f = [] {};

//struct A
//{
//public:
//	A(int age = 1, int id = 1, string name = "")
//		:_age(age)
//		, _id(id)
//		, _name(name)
//	{}
//
//	bool operator<(const A& a)
//	{
//		return _age < a._age;
//	}
//
//	int _age;
//	int _id;
//	string _name;
//};
//
//struct Less
//{
//	bool operator()(const A& a, const A& b)
//	{
//		return a._id > b._id;
//	}
//};
//
//void test()
//{
//	vector<A> vec = { {18,1,"a"},{29,3,"b"},{13,25,"c"} };
//	sort(vec.begin(), vec.end());
//	sort(vec.begin(), vec.end(), Less());
//	sort(vec.begin(), vec.end(),
//		[](const A& a, const A& b)
//		{ return a._name > b._name; });
//}

//void test()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//
//	// 默认按照小于比较，排出来结果是升序
//	sort(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 如果需要降序，需要改变元素的比较规则
//	sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//}

//void Fun(int& x) { cout << "lvalue ref" << endl; }
//void Fun(int&& x) { cout << "rvalue ref" << endl; }
//void Fun(const int& x) { cout << "const lvalue ref" << endl; }
//void Fun(const int&& x) { cout << "const rvalue ref" << endl; }
////T&&：未定引用类型
////具体类型&&：右值引用
//template<typename T>
//void PerfectForward(T&& t) { Fun(std::forward<T>(t)); }
////void PerfectForward(const T& t) { Fun(t); }
//
//void test()
//{
//	PerfectForward(10); // rvalue ref
//	int a;
//	PerfectForward(a); // lvalue ref
//	PerfectForward(move(a)); // rvalue ref
//	const int b = 8;
//	PerfectForward(b); // const lvalue ref
//	PerfectForward(move(b)); // const rvalue ref
//}

int main()
{
	test();
	system("pause");
	return 0;
}