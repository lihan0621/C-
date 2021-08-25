#include <iostream>
using namespace std;

template <class T>
struct BNode
{
	T _data;
	typedef BNode<T> Node;
	Node* _left;
	Node* _right;
	BNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class T>
class BTree
{
public:
	typedef BNode<T> Node;

	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
	}

	//����ڵ�
	//�������ظ���ֵ
	bool insert(const T& val)
	{
		//������в���
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//�������ҵ����ʵĲ���λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		//����
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	//�������������������
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_data << " ";
			_inorder(root->_right);
		}
	}

	void destroy(Node* root)
	{
		if (root)
		{
			cout << "destroy: " << root->_data << endl;
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	}

	//�������������������ݺͽṹ
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newnode = new Node(root->_data);
		newnode->_left = copy(root->_left);
		newnode->_right = copy(root->_right);
		return newnode;
	}

	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	BTree()
		:_root(nullptr)
	{}

	~BTree()
	{
		if (_root)
		{
			destroy(_root);
			_root = nullptr;
		}
	}

private:
	Node* _root;
};

void test()
{
	BTree<int> b;
	srand((unsigned int)time(nullptr));
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		b.insert(rand());
	}
	b.inorder();

	BTree<int> copy(b);
	copy.inorder();
}

int main()
{
	test();
	system("pause");
	return 0;
}