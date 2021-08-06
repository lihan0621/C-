#include <iostream>
using namespace std;

//listʵ�֣�˫���ͷ��ѭ������

template<class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_data(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

//list���������Զ������ͣ��Խڵ���з�װ��
//ͨ�������ڵ���ɵ������涨�Ĺ���
template<class T>
struct ListIterator
{
	ListIterator(ListNode<T>* node)
		:_node(node)
	{}

	//*��������غ���
	//*iterstor: ��ȡ���ݱ���
	T& operator*()
	{
		return _node->_data;
	}

	//it->_a
	T* operator->()
	{
		return &_node->_data;
	}

	//++iterator
	ListIterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//����++
	ListIterator<T> operator++(int)
	{
		ListIterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	bool operator!=(const ListIterator<T>& it) const
	{
		//�жϳ�Աָ��_node�Ƿ�ָ��ͬһ���ڵ�
		return _node != it._node;
	}

	bool operator==(const ListIterator<T>& it)
	{
		return !(*this != it);
	}

	//��װ�ڵ�
	ListNode<T>* _node;
};

template<class T>
struct ConstListIterator
{
	ConstListIterator(ListNode<T>* node)
		:_node(node)
	{}

	//*��������غ���
	//*iterstor: ��ȡ���ݱ���
	const T& operator*()
	{
		return _node->_data;
	}

	//it->_a
	const T* operator->()
	{
		return &_node->_data;
	}

	//++iterator
	ConstListIterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//����++
	ConstListIterator<T> operator++(int)
	{
		ListIterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	ConstListIterator operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const ConstListIterator<T>& it) const
	{
		//�жϳ�Աָ��_node�Ƿ�ָ��ͬһ���ڵ�
		return _node != it._node;
	}

	bool operator==(const ConstListIterator<T>& it)
	{
		return !(*this != it);
	}

	//��װ�ڵ�
	ListNode<T>* _node;
};


template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> constIterator;

	iterator begin()
	{
		return iterator(_header->_next);
	}

	constIterator begin() const
	{
		return constIterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	constIterator end() const
	{
		return constIterator(_header);
	}

	List()
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
	}

	List(size_t n, const T& val = T())
		:_header(new Node())
	{
		_header->_next = _header->_prev = _header;
		for (size_t i = 0; i < n; ++i)
		{
			pushBack(val);
		}
	}

	template<class inputIterator>
	List(inputIterator first, inputIterator last)
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
		while (first != last)
		{
			pushBack(*first);
			++first;
		}
	}

	void pushBack(const T& val)
	{
		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void insert(iterator pos, const T& val)
	{
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		pNode newNode = new Node(val);
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator erase(iterator pos)
	{
		//�ж��Ƿ�Ϊend������
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			prev->_next = next;
			next->_prev = prev;
			//pos������ʧЧ
			//���µ�������ָ����һ��Ԫ��
			return iterator(next);
		}
		return pos;
	}

	void popFront()
	{
		erase(begin());
	}

	void popBack()
	{
		erase(--end());
	}

	~List()
	{
		if (_header)
		{
			//�ͷ�ÿһ���ڵ�Ŀռ�
			pNode node = _header->_next;
			while (node != _header)
			{
				pNode next = node->_next;
				delete node;
				node = next;
			}
			delete _header;
			_header = nullptr;
		}
	}

	//���
	List(const List<T>& lst)
		:_header(new Node())
	{
		//ѭ���ṹ
		_header->_next = _header->_prev = _header;
		//Ԫ�ؿ���
		//Node* cur = lst._header->_next;
		//while (cur != lst._header)
		//{
		//	pushBack(cur->_data);
		//}
		for (auto& e : lst)
		{
			pushBack(e);
		}
	}

	//List<T>& operator=(const List<T>& lst)
	//{
	//	//�ͷ�ԭ�еĽڵ�
	//	Node* cur = _header->_next;
	//	while (cur != _header)
	//	{
	//		Node* next = cur->_next;
	//		delete cur;
	//		cur = next;
	//	}
	//	_header->_next = _header->_prev = _header;
	//	//����
	//	for (auto& e : lst)
	//	{
	//		pushBack(e);
	//	}
	//}

	List<T>& operator=(List<T> lst)
	{
		swap(_header, lst._header);
		return *this;
	}


private:
	pNode _header;
};

template <class T>
void printList(List<T>& lst)
{
	typename List<T>::iterator cit = lst.begin();
	while (cit != lst.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

template <class T>
void printForList(const List<T>& lst)
{
	for (const auto& e : lst)
	{
		cout << e << " ";
	}
	cout << endl;
}

struct A
{
	A(int a = 1, int b = 2, int c = 3)
		:_a(a)
		,_b(b)
		,_c(c)
	{}

	int _a;
	int _b;
	int _c;
};

void test()
{
	List<A> lst;
	lst.pushBack(A());
	lst.pushBack(A(10, 20, 30));
	lst.pushBack(A(4, 5, 6));
	lst.pushBack(A(7, 8, 9));
	List<A>::iterator it = lst.begin();
	while (it != lst.end())
	{
		//cout << *it << " ";
		cout << it.operator->()->_a << it.operator->()->_b << it.operator->()->_c << " " << endl;
		//��д�Ĵ�����ʽ
		//cout << it->->_a << it->->_b << it->->_c;
		//��д����ȷ��ʽ
		cout << it->_a << it->_b << it->_c << " " << endl;
		++it;
	}
	printList(lst);
}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//
//	List<int> lst2((size_t)10, 5);
//}

int main2()
{
	test();
	system("pause");
	return 0;
}