#ifndef _BITREE_H
#define _BITREE_H

#include <iostream>
#include <queue>
 
using namespace std;

template <class T>
struct BiNode
{
	T data;				//二叉树节点数据域
	BiNode<T> * lchild;	//节点左孩子指针域
	BiNode<T> * rchild;	//节点右孩子指针域
	BiNode() :lchild(nullptr), rchild(nullptr){};
};

enum Order{Pre,In,Post,Level};		//前、中、后、层序枚举

template <class T>
class BiTree
{
private:
//	void Create(BiNode<T> ** R);	//非递归创建二叉树，用户输入前序字符串
	void Create(BiNode<T> * & R);	//创建二叉树，用户根据提示输入节点字符
	void Create(BiNode<T> * & R, T data[], int i, int n);	//根据 n 长度的 T 数组的位置 i 创建二叉树，T 数组是按照 2*i 和 2*i+1为子节点的方式
	void Create(BiNode<T> * & R, T PreData[], T InData[], int s1, int e1, int s2, int e2);	//根据前序数组和中序数组创建二叉树，s1,e1,s2,e2分别为两个数组的起始、终结点
	void Release(BiNode<T> * R);	//释放树节点 R
	int find(T InData[], T e, int s2, int e2);		//在 T 数组 [s2,e2]中查找元素 e
public:
	BiNode<T> * root;				//二叉树根指针
	BiTree();						//BiTree默认初始化，根据输入创建二叉树
	BiTree(BiTree<T> * t);			//copy constructer
	BiTree(T data[], int n);		//根据顺序存储的 树 数组 T 创建二叉树
	BiTree(T PreData[], T InData[], int s1, int e1, int s2, int e2);	//由前序、中序数组创建二叉树
	~BiTree();

	void Print(Order porder);		//遍历打印二叉树
	void PreOrder(BiNode<T> * R);	//前序遍历打印二叉树
	void InOrder(BiNode<T> * R);	//中序遍历打印二叉树
	void PostOrder(BiNode<T> * R);	//后续遍历打印二叉树
	void LevelOrder(BiNode<T> * R);	//层序遍历打印二叉树
	void CopyTree(BiNode<T> * src, BiNode<T> * & dst);	//复制二叉树
	bool Path(BiNode<T> * R, T e);	//获取元素 e 在二叉树中的路径
	int Depth(BiNode<T> * R);		//计算二叉树的高度
	int Leaf(BiNode<T> * R);		//
	int CountNode(BiNode<T> * R);	//
};

//template <class T>
//void BiTree<T>::Create(BiNode<T> ** R)
//{
//	BiNode<T> ** Stack[MAXSIZE];
//	int top = -1;
//	char ch;
//	do
//	{
//		cin >> ch;
//		while (ch != '#')
//		{
//			*R = new BiNode<T>;
//			(*R)->data = ch;
//			(*R)->lchild = (*R)->rchild = nullptr;
//			Stack[++top] = R;
//			R = &((*R)->lchild);
//			cin >> ch;
//		}
//		R = &( (*Stack[top])->rchild );
//		top--;
//	} while (top != -1 || ([i]))
//}

template <class T>
void BiTree<T>::Create(BiNode<T> * & R)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		R = nullptr;
	else{
		R = new BiNode<T>;
		R->data = ch;
		Create(R->lchild);
		Create(R->rchild);
	}
}

template <class T>
void BiTree<T>::Create(BiNode<T> * & R, T data[],int i, int n)
{
	if (i <= n){
		R = new BiNode<T>;
		R->data = data[i - 1];
		Create(R->lchild, data, 2 * i, n);
		Create(R->rchild, data, 2 * i + 1, n);
	}
	else
		R = nullptr;
}

template <class T>
int BiTree<T>::find(T InData[], T e, int s2, int e2)
{
	for (int i = s2; i <= e2; ++i){
		if (e == InData)
			return i;
	}
	return -1;
}

template <class T>
void BiTree<T>::Create(BiNode<T> * & R, T PreData[], T InData[], int s1, int e1, int s2, int e2)
{
	if (s1 <= e1){
		R = new BiNode<T>;
		R->data = PreData[s1];
		R->lchild = R->rchild = nullptr;
		int pos = find(InData, PreData[s1], s2, e2);
		if (pos < 0)
			return;
		Create(R->lchild, PreData, InData, s1 + 1, s1 + pos - s2, s2, pos - 1);
		Create(R->rchild, PreData, InData, s1 + pos - s2 + 1, e1, pos + 1, e2);
	}
}

template <class T>
BiTree<T>::BiTree(BiTree<T> * t)
{
	CopyTree(t->root,this->root);
}

template <class T>
BiTree<T>::BiTree()
{
	Create(root);
}


template <class T>
BiTree<T>::BiTree(T Data[], int n)
{
	Create(root, Data, 1, n);
}

template <class T>
BiTree<T>::BiTree(T PreData[], T InData[], int s1, int e1, int s2, int e2)
{
	Create(root, PreData, InData, s1, e1, s2, e2);
}

template <class T>
void BiTree<T>::Release(BiNode<T> * R)
{
	/*if (R->lchild == nullptr && R->rchild == nullptr)
		delete R;
	else {
		if (R->lchild != nullptr)
			Release(R->lchild);
		if (R->rchild != nullptr)
			Release(R->rchild);
	}	*/
	if (nullptr != R){
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}

template <class T>
BiTree<T>::~BiTree()
{
	Release(root);
}

template <class T>
void BiTree<T>::Print(Order porder)
{
	switch (porder)
	{
	case Pre:
		PreOrder(root);
		break;
	case In:
		InOrder(root);
		break;
	case Post:
		PostOrder(root);
		break;
	case Level:
		LevelOrder(root);
		break;
	default:
		cerr << "Print BiTree Error" << endl;
		break;
	}
	cout << endl;
}

//递归前序遍历树
//template <class T>
//void BiTree<T>::PreOrder(BiNode<T> * R)
//{
//	if (R == nullptr)
//		return;
//	else{
//		cout << R->data;
//		PreOrder(R->lchild);
//		PreOrder(R->rchild);
//	}
//}

//非递归前序遍历树
template <class T>
void BiTree<T>::PreOrder(BiNode<T> * R)
{
	BiNode<T> * Stack[100];
	int top = -1;
	while ((top != -1) || R != nullptr){
		if (R != nullptr){
			cout << R->data;
			Stack[++top] = R;
			R = R->lchild;
		}
		else{
			R = Stack[top--];
			R = R->rchild;
		}
	}	
}

template <class T>
void BiTree<T>::InOrder(BiNode<T> * R)
{
	if (R == nullptr)
		return;
	else{
		InOrder(R->lchild);
		cout << R->data;
		InOrder(R->rchild);
	}
}

template <class T>
void BiTree<T>::PostOrder(BiNode<T> * R)
{
	if (nullptr == R)
		return;
	else{
		PostOrder(R->lchild);
		PostOrder(R->rchild);
		cout << R->data;
	}
}

template <class T>
void BiTree<T>::LevelOrder(BiNode<T> * R)
{
	queue< BiNode<T> * > q;
	BiNode<T> * front;
	if (nullptr != R)
	{
		q.push(R);
		while (!q.empty()){
			front = q.front();
			cout << front->data;
			if (nullptr != front->lchild)
				q.push(front->lchild);
			if (nullptr != front->rchild)
				q.push(front->rchild);
			q.pop();
		}
	}
}

template <class T>
void BiTree<T>::CopyTree(BiNode<T> *  src, BiNode<T> * & dst)
{
	if (nullptr == src)
		dst = nullptr;
	else{
		dst = new BiNode<T>;
		dst->data = src->data;
		CopyTree(src->lchild, dst->lchild);
		CopyTree(src->rchild, dst->rchild);
	}
}

template <class T>
bool BiTree<T>::Path(BiNode<T> * R, T e)
{
	if (R == NULL)
		return false;
	else{
		if (R->data == e){				//如果是该元素，则打印返回
			cout << R->data;
			return true;
		}
		else if (Path(R->lchild, e)){	//递归查找左子树，若存在 e 打印返回
			cout << R->data;
			return true;
		}
		else if (Path(R->rchild, e)){	//递归查找右子树，若存在 e 打印返回
			cout << R->data;
			return true;
		}
		else return false;				//不存在，返回空
	}
}

template <class T>
int BiTree<T>::Depth(BiNode<T> * R)
{
	if (R == nullptr)
		return 0;
	else{
		int m = Depth(R->lchild);
		int n = Depth(R->rchild);
		return m > n ? m + 1 : n + 1;
	}
}

template <class T>
int BiTree<T>::CountNode(BiNode<T> * R)
{
	if (R == nullptr)
		return 0;
	else{
		int count = 1;
		count += CountNode(R->lchild);
		count += CountNode(R->rchild);
		return count;
	}
}

template <class T>
int BiTree<T>::Leaf(BiNode<T> * R)
{
	if (R->lchild == nullptr && R->rchild == nullptr)
		return  1;
	else {
		int leaf = 0;
		leaf += Leaf(R->lchild);
		leaf += Leaf(R->rchild);
		return leaf;
	}
}

#endif