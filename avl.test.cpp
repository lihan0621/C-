#include <iostream>
#include <time.h>
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
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//右边的右边高
					//左旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//左边的右边高
					RotateL(cur);
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//保存subRL的bf
					Node* subRL = cur->_left;
					int bf = subRL->_bf;

					//右边的左边高
					RotateR(cur);
					RotateL(parent);

					//修正平衡因子
					if (bf == 1)
					{
						cur->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1)
					{
						cur->_bf = 1;
						parent->_bf = 0;
					}
				}
				break;
			}
		}
		return true;
	}

	//右旋
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

	//左旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}

		parent->_parent = subR;
		parent->_bf = subR->_bf = 0;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}

	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_val << " ";
			_inorder(root->_right);
		}
	}

	int	Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		//查看平衡因子是否和左右子树的高度差一致
		int left = Height(root->_left);
		int right = Height(root->_right);
		if (right - left != root->_bf)
		{
			cout << "Node: " << root->_val << " bf: " << root->_bf << " height gap: " << right - left << endl;
			return false;
		}
		return abs(root->_bf) < 2 && _isBalance(root->_left) && _isBalance(root->_right);
	}

	void isBalance()
	{
		_isBalance(root);
	}
		

private:
	Node* _root = nullptr;
};

void test()
{
	srand((unsigned int)time(nullptr));
	cout << "num: " << endl;
	int num;
	cin >> num;
	AVLTree<int> avl;
	for (int i = 0; i < num; ++i)
	{
		avl.insert(rand());
	}
	avl.inorder();
}

//void test()
//{
//	AVLTree<int> avl;
//	avl.insert(5);
//	avl.insert(3);
//	avl.insert(1); //右旋
//
//	avl.insert(0);
//	avl.insert(2);
//
//	avl.insert(-1); //右旋
//}

int main()
{
	test();
	system("pause");
	return 0;
}