#include <iostream>
using namespace std;

template <class T>
struct AVLNode
{
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	T _val;
	//平衡因子
	int _bf;

	AVLNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _val(val)
		, _bf(0)
	{}
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;

	bool insert(const T& val)
	{
		//二叉搜索树插入
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//调整，从parebt开始
		while (parent)
		{
			//更新parent的平衡因子
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			if(parent->_bf == 0) //parent比较短的子树高度+1
				//结束更新
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
				//继续向上更新
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//左边的左边高
					//右旋
					RotateR(parent);
				}
				break;
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		//判断parent是否为根节点
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		parent->_parent = subL;
		subL->_bf = parent->_bf = 0;
	}

private:
	Node* _root = nullptr;
};

void test()
{
	AVLTree<int> avl;
	avl.insert(5);
	avl.insert(3);
	avl.insert(1); //右旋

	avl.insert(0);
	avl.insert(2);

	avl.insert(-1); //右旋
}

int main()
{
	test();
	system("pause");
	return 0;
}