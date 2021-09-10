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

//哈希表的前置声明
template <class K, class V, class KeyOfValue>
class HTable;


//哈希表迭代器： 自定义类型
//通过封装单链表的节点实现
template <class K, class V, class KeyOfValue>
struct HashIterator
{
	typedef HashIterator<K, V, KeyOfValue> Self;
	typedef HTable<K, V, KeyOfValue> HT;
	//成员： 节点指针, 哈希表指针
	typedef HashNode<V> Node;
	HT* _hPtr;

	Node* _node;

	HashIterator(Node* node, HT* hPtr)
		:_node(node)
		, _hPtr(hPtr)
	{}

	V& operator*()
	{
		return _node->_val;
	}

	V* operator->()
	{
		return &_node->_val;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//查找下一个非空链表的头结点
			//计算当前节点在哈希表中的位置
			KeyOfValue kov;
			size_t idx = kov(_node->_val) % _hPtr->_ht.size();
			//从下一个哈希位置开始查找
			++idx;
			for (; idx < _hPtr->_ht.size(); ++idx)
			{
				if (_hPtr->_ht[idx])
				{
					//找到下一个非空链表
					_node = _hPtr->_ht[idx];
					break;
				}
			}
			//没有有效的节点
			if (idx == _hPtr->_ht.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}
};

template <class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue> iterator;

	//把迭代器声明为友元类
	template <class K, class V, class KeyOfValue>
	friend struct HashIterator;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//第一个非空链表的头结点
		for (size_t i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
			{
				return iterator(_ht[i], this);
			}
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	pair<iterator, bool> insert(const V& val)
	//bool insert(const V& val)
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
				//return false;
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}

		//3. 插入: 头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		//return true;
		return make_pair(iterator(cur, this), true);
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
			for (size_t i = 0; i < _ht.size(); ++i)
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

	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& key)
	{
		return _ht.insert(key);
	}
private:
	HTable<K, K, SetKeyOfValue> _ht;
};

template <class K, class V>
class Map
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}

	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _ht.insert(val);
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}


private:
	HTable<K, pair<K, V>, MapKeyOfValue> _ht;
};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m[20] = 20;
	m[30] = 30;
	m[1] = 100;

	Map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	for (const auto& p : m)
	{
		cout << p.first << "--->" << p.second << endl;
	}
}

//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(13);
//	s.insert(44);
//	s.insert(45);
//	s.insert(17);
//	s.insert(6);
//	s.insert(16);
//	s.insert(11);
//
//	Set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

int main()
{
	test();
	system("pause");
	return 0;
}