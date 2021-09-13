#include <iostream>
#include <vector>
using namespace std;

//位图: 
class BitSet
{
public:
	//位图的内存大小和数据范围有关系
	BitSet(size_t range)
		:_bit(range / 32 + 1)
	{}

	//存储信息
	void set(size_t num)
	{
		//计算位置
		//1.计算整数位置： / 32
		int idx = num / 32;
		//2.计算bit位置： % 32
		int bitIdx = num % 32;
		//把对应的bit位置1
		//按位或运算
		_bit[idx] |= 1 << bitIdx;
	}
	//查找信息

	//删除信息

private:
	//整数数组
	vector<int> _bit;
};

void test()
{
	BitSet bit(512);
	bit.set(1);
	bit.set(512);
	bit.set(32);
	bit.set(64);
	bit.set(15);
	bit.set(47);
}

int main()
{
	test();
	system("pause");
	return 0;
}