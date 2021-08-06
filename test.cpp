#include <iostream>
using namespace std;

//list实现：双向带头的循环链表

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

//list迭代器：自定义类型，对节点进行封装，
//通过操作节点完成迭代器规定的功能
template<class T>
struct ListIterator
{
	ListIterator(ListNode<T>* node)
		:_node(node)
	{}

	//*运算符重载函数
	//*iterstor: 获取数据本身
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

	//后置++
	ListIterator<T> operator++(int)
	{
		ListIterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	bool operator!=(const ListIterator<T>& it) const
	{
		//判断成员指针_node是否指向同一个节点
		return _node != it._node;
	}

	bool operator==(const ListIterator<T>& it)
	{
		return !(*this != it);
	}

	//封装节点
	ListNode<T>* _node;
};

template<class T>
struct ConstListIterator
{
	ConstListIterator(ListNode<T>* node)
		:_node(node)
	{}

	//*运算符重载函数
	//*iterstor: 获取数据本身
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

	//后置++
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
		//判断成员指针_node是否指向同一个节点
		return _node != it._node;
	}

	bool operator==(const ConstListIterator<T>& it)
	{
		return !(*this != it);
	}

	//封装节点
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
		//循环结构
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
		//循环结构
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
		//判断是否为end迭代器
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			prev->_next = next;
			next->_prev = prev;
			//pos迭代器失效
			//更新迭代器：指向下一个元素
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
			//释放每一个节点的空间
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

	//深拷贝
	List(const List<T>& lst)
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
		//元素拷贝
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
	//	//释放原有的节点
	//	Node* cur = _header->_next;
	//	while (cur != _header)
	//	{
	//		Node* next = cur->_next;
	//		delete cur;
	//		cur = next;
	//	}
	//	_header->_next = _header->_prev = _header;
	//	//拷贝
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
		//简写的错误形式
		//cout << it->->_a << it->->_b << it->->_c;
		//简写的正确形式
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