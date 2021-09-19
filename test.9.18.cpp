#include <iostream>
using namespace std;

class HeapObj
{
public:
	//调用构造函数创建对象
	static HeapObj* getObj()
	{
		//HeapObj* p = new HeapObj();
		//return *p;
		return new HeapObj;
	}
	//禁止构造函数的调用： 私有
private:
	HeapObj()
	{}

	//防拷贝
	//只声明，不实现
	//HeapObj(const HeapObj&);

	//或者声明为delete函数
	HeapObj(const HeapObj&) = delete;

};

void test()
{
	//HeapObj h;
	HeapObj* ptr = HeapObj::getObj();
	//HeapObj copy(*ptr);
}

int main()
{
	test();
	system("pause");
	return 0;
}