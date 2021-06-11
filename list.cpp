#include<iostream>
#include<vector>
#include<string>
using namespace std;
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
//ListIterator<T,T&,T*>
//ListIterator<T,const T&,const T*>
template<class T,class Ref,class Ptr>
struct ListIterator
{
	typedef ListIterator<T, Ref, Ptr>Self;
	ListIterator(ListNode<T>* node)
		:_node(node)
	{}
	//*iterator:获取数据本身
	Ref operator*()
	{
		return _node->_data;
	}
	//it->a
	Ptr operator->()
	{
		return &_node->_data;
	}
	//++iterator
	//ListIterator<T>& operator++()
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	//后置++
	//ListIterator<T>& operator++(int)
	Self operator++(int)
	{
		ListIterator<T> tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	Self operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	//bool operator!=(const ListIterator<T>& IT)
	bool operator!=(const Self& it)const
	{
		//判断成员指针_node是否指向同一个节点
		return _node != it._node;
	}
	//bool operator==(const ListIterator<T>& it)
	bool operator==(const Self& it)
	{
		return !(*this != it);
	}
	//封装节点
	ListNode<T>* _node;
};
//template<class T>
//struct ConstListIterator
//{
//	typedef ConstListIterator<T> Self;
//	ConstListIterator(ListNode<T>* node)
//		:_node(node)
//	{}
//	//*iterator：获取数据本身
//	const T& operator*()
//	{
//		return _node->_data;
//	}
//	//it->_a
//	const T* operator->()
//	{
//		return &_node->_data;
//	}
//	//++iterator
//	//ListIterstor<T>& operator++()
//	Self& operator++()
//	{
//		_node = _node->_next;
//		return *this;
//	}
//	//后置++
//	//ListItrator<T> operator++(int)
//	Self operator++(int)
//	{
//		ListIterator<T> tmp(*this);
//		_node = _node->_next;
//		return tmp;
//	}
//	//bool operator!=(const ListIterator<T>& it)
//	bool operator!=(const Self& it)
//	{
//		//判断成员指针_node是否指向同一个节点
//		return _node != it._node;
//	}
//	//bool operator==(const ListIterator<T>& it)
//	bool operator==(const Self& it)
//	{
//		return !(*this != it);
//	}
//	//封装节点
//	ListNode<T>* _node;
//};
//list实现：底层是双向带头循环链表
template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
	iterator begin()
	{
		return iterator(_header->_next);
	}
	const_iterator begin()
	{
		return const_iterator(_header->_next);
	}
	iterator end()
	{
		return iterator(_header);
	}
	const_iterator end()
	{
		return const_iterator(_header);
	}
	List()
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
	}
	List(int n, const T& val = T())
		:_header(new Node())
	{
		//循环结构
		_header->_next = _header->_prev = _header;
		for (int i = 0; i < n; ++i)
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
void printList(const List<T>& lst)
{
	typename List<T>::const_iterator cit = lst.begin();
	while (cit != lst.end())
	{
		cout << *cit << " ";
		//*cit = T();
		++cit;
	}
	cout << endl;
}
template <class T>
void printList2(List<T>& lst)
{
	typename List<T>::iterator cit = lst.begin();
	while (cit != lst.end())
	{
		cout << *cit << " ";
		*cit = T();
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
template <class T>
void printForList2(List<T>& lst)
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

}
//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//	printList(lst);
//	printList2(lst);
//	printForList(lst);
//	printForList2(lst);
//}
//void test()
//{
//	List<A> lst;
//	lst.pushBack(A());
//	lst.pushBack(A(10, 20, 30));
//	lst.pushBack(A(4, 5, 6));
//	lst.pushBack(A(7, 8, 9));
//	lst.pushBack(A(12, 13, 14));
//	lst.pushBack(A(10, 11, 12));
//	List<A>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}
//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	lst.pushBack(5);
//	List<int>::iterator it = lst.begin();
//	while (it != lst.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}
int main()
{
	test();
	return 0;
}