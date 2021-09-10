#include <iostream>
#include <vector>
using namespace std;

//开散列

//单链表的节点
template <class V>
struct HashNode
{
	V _val;
	HashNode<V>* _next;

	HashNode(const V& val)
		:_val(val)
		, _next(nullptr)
	{}
};

template <class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashNode<V> Node;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	bool insert(const V& val)
	{
		//0. 检查容量
		checkCapacity();

		//1. 计算hash位置
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();

		//2. 查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key重复
				return false;
			}
			cur = cur->_next;
		}

		//3. 插入: 头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;

			//创建新的指针数组
			vector<Node*> newHt(newC);

			KeyOfValue kov;

			//遍历旧表
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				//遍历单链表
				while (cur)
				{
					Node* next = cur->_next;
					//计算新的位置
					int idx = kov(cur->_val) % newHt.size();
					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;
					cur = next;
				}

				//旧表指针置空
				_ht[i] = nullptr;
			}
			
			//新表旧表交换
			swap(_ht, newHt);
		}
	}

private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};

template <class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	bool insert(const K& key)
	{
		return _ht.insert(key);
	}
private:
	HTable<K, K, SetKeyOfValue> _ht;
};

void test()
{
	Set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(13);
	s.insert(44);
	s.insert(45);
	s.insert(17);
	s.insert(6);
	s.insert(16);
	s.insert(11);
}

int main()
{
	test();
	system("pause");
	return 0;
}