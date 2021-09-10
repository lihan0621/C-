#include <iostream>
#include <vector>
using namespace std;

enum class STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//��ϣ�� ����̽��
template <class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = STATE::EMPTY;
};

//˳���ʵ��hash
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
		//0. �������
		checkCapacity();
		//1. �����ϣλ��
		int idx = kv.first % _hTable.size();

		//2. �ж�key�Ƿ����
		while (_hTable[idx]._state != STATE::EMPTY)
		{
			//�����ǰλ��������Ч����key��ͬ������ʧ��
			if (_hTable[idx]._state == STATE::EXIST && kv.first == _hTable[idx]._kv.first)
			{
				return false;
			}

			//��������
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}

		//����
		_hTable[idx]._kv = kv;
		_hTable[idx]._state = STATE::EXIST;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		//��������: < 1
		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= 7)
		{
			//���±�
			int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
			HashTable<K, V> newHt(newC);

			for (int i = 0; i < _hTable.size(); ++i)
			{
				//����״̬Ϊexist������
				if (_hTable[i]._state == STATE::EXIST)
				{
					newHt.insert(_hTable[i]._kv);
				}
			}

			Swap(newHt);
		}
	}

	void Swap(HashTable<K, V>& Ht)
	{
		swap(_hTable, Ht._hTable);
		swap(_size, Ht._size);
	}

	Node* find(const K& key)
	{
		//����λ��
		int idx = key % _hTable.size();
		while (_hTable[idx]._state != STATE::EMPTY)
		{
			if (_hTable[idx]._state == STATE::EXIST && key == _hTable[idx]._kv.first)
			{
				return &_hTable[idx];
			}
			++idx;
			if (idx == _hTable.size())
			{
				idx = 0;
			}
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			//��ɾ��
			--_size;
			node->_state = STATE::DELETE;
			return true;
		}
		return false;
	}

private:
	vector<Node> _hTable;
	size_t _size; //��ЧԪ�صĸ���
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