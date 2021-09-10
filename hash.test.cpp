#include <iostream>
#include <vector>
using namespace std;

enum class STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//哈希表： 线性探测
template <class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = STATE::EMPTY;
};

//顺序表实现hash
template <class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;

	HashTable(size_t n = 10)
		:_hTable(n)
		, _size(0)
	{}

	bool insert(const pair<K, V>& kv)
	{
		//1. 计算哈希位置
		int idx = kv.first % _hTable.size();

		//2. 判断key是否存在
		while (_hTable[idx]._state != STATE::EMPTY)
		{
			//如果当前位置数据有效，且key相同，插入失败
			if (_hTable[idx]._state == STATE::EXIST && kv.first == _hTable[idx]._kv.first)
			{
				return false;
			}

			//继续搜索
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}

		//插入
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = STATE::EXIST;
		++_size;
		return true;
	}

private:
	vector<Node> _hTable;
	size_t _size; //有效元素的个数
};

void test()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(14, 14));
	ht.insert(make_pair(16, 16));
	ht.insert(make_pair(11, 11));
	ht.insert(make_pair(14, 140));
}

int main()
{
	test();
	system("pause");
	return 0;
}