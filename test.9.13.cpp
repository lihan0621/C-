#include <iostream>
#include <vector>
#include <string>
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

//k = m/n * ln2  m = k * n * 1.4
//m：需要的bit位大小
//n：元素个数
//k：哈希函数个数
//使用场景：存放各种数据的简单信息
//概率型容器：判断存在，结果不一定正确
//一般没有删除操作：存在误删

template <class T, class Hash1, class Hash2, class Hash3>
class BloomFilter
{
public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		, _bitCount(5 * num)
	{}

	//存储信息：使用多个bit位存储信息
	void Set(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;
		_bit.Set(idx1);
		_bit.Set(idx2);
		_bit.Set(idx3);
	}

	bool test(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;

		if (!_bit.test(idx1))
			return false;
		if (!_bit.test(idx2))
			return false;
		if (!_bit.test(idx3))
			return false;
		return true;  //可能存在
	}

	//封装位图：
private:
	BitSet _bit;
	//bit位的个数
	size_t _bitCount;
};

struct HashFun1
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};

struct HashFun2
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 1313131 + ch;
		}
		return hash;
	}
};

struct HashFun3
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

void test()
{
	BloomFilter<string, HashFun1, HashFun2, HashFun3> bf(10);
	string str1 = "https://zhibo.chaoxing.com/10630331&userId=108880301&rt=0.9&isNotDrag=1&livesetenc=b5c8ea5315325d1d770928965f9e9256&isjob=true&watchingInCourse=1";
	string str2 = "https://zhibo.chaoxing.com/10630331&userId=108880301&rt=0.9&isNotDrag=1&livesetenc=b5c8ea5315325d1d770928965f9e9256&isjob=true&watchingInCourse=2";
	string str3 = "https://zhibo.chaoxing.com/10630331&userId=108880301&rt=0.9&isNotDrag=1&livesetenc=b5c8ea5315325d1d770928965f9e9256&isjob=true&watchingInCourse=3";
	string str4 = "https://zhibo.chaoxing.com/10630331&userId=108880301&rt=0.9&isNotDrag=1&livesetenc=b5c8ea5315325d1d770928965f9e9256&isjob=true&watchingInCourse=4";

	bf.Set(str1);
	bf.Set(str2);
	bf.Set(str3);

	bool ret = bf.test(str1);
	ret = bf.test(str2);
	ret = bf.test(str3);
	ret = bf.test(str4);
}

//void test()
//{
//	BitSet bit(512);
//	bit.Set(1);
//	bit.Set(512);
//	bit.Set(32);
//	bit.Set(64);
//	bit.Set(15);
//	bit.reset(15);
//	bit.Set(47);
//
//	bool ret = bit.test(1);
//	ret = bit.test(47);
//	ret = bit.test(100);
//}

int main()
{
	test();
	system("pause");
	return 0;
}