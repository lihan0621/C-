#include <iostream>
#include <vector>
using namespace std;

//位图: 使用场景--->存放不重复数据的简单信息，不需要存放数据本身
//优点: 节省空间，查找效率高 O(1)
class BitSet
{
public:
	//位图的内存大小和数据范围有关系
	BitSet(size_t range)
		:_bit(range / 32 + 1)
	{}

	//存储信息
	void Set(size_t num)
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
	bool test(size_t num)
	{
		int idx = num / 32;
		int bitIdx = num % 32;
		return (_bit[idx] >> bitIdx) & 1;
	}

	//删除信息
	void reset(size_t num)
	{
		int idx = num / 32;
		int bitIdx = num % 32;
		_bit[idx] &= ~(1 << bitIdx);
	}

private:
	//整数数组
	vector<int> _bit;
};

void test()
{
	BitSet bit(512);
	bit.Set(1);
	bit.Set(512);
	bit.Set(32);
	bit.Set(64);
	bit.Set(15);
	bit.reset(15);
	bit.Set(47);

	bool ret = bit.test(1);
	ret = bit.test(47);
	ret = bit.test(100);
}

int main()
{
	test();
	system("pause");
	return 0;
}