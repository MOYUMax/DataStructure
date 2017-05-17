#ifndef _BST_H
#define _BST_H

#include <iostream>

using namespace std;

//template <class T>
//struct BiNode
//{
//	T data;				//二叉树节点数据域
//	BiNode<T> * lchild;	//节点左孩子指针域
//	BiNode<T> * rchild;	//节点右孩子指针域
//	BiNode() :lchild(nullptr), rchild(nullptr){};
//};
//template <class T>
//extern struct BiNode<T>;

template <class T>
class BST
{
private:
	void destory(BiNode<T> * s);
public:	
	BiNode<T> * rootBST;
	BST(T r[], int n);
	~BST();
	BiNode<T> * Search(BiNode<T> * R, T key);
	void InsertBST(BiNode<T> * &R, BiNode<T> * s);
	void Delete(BiNode<T> * & R);
	bool DeleteBST(BiNode<T> * & R, T key); 
	int FindKeyLevel(BiNode<T> * R, T key, int i);
	int FindKeyLevel(BiNode<T> * R, T key);
	bool IsSorted(BiNode<T> * R) const;
};

template <class T>
void BST<T>::destory(BiNode<T> * s)
{
	if (nullptr == s)
		return;
	else{
		destory(s->lchild);
		destory(s->rchild);
		delete s;
	}
}

template <class T>
BST<T>::BST(T r[], int n)
{
	rootBST = nullptr;
	for (int i = 0; i < n; ++i){
		BiNode<T> * s = new BiNode<T>;
		s->data = r[i];
		InsertBST(rootBST, s);
	}
}

template <class T>
BST<T>::~BST()
{
	destory(rootBST);
}

template <class T>
void BST<T>::InsertBST(BiNode<T> * & R, BiNode<T> * s)
{
	if (nullptr == R)
		R = s;
	else if (s->data < R->data)
		InsertBST(R->lchild, s);
	else
		InsertBST(R->rchild, s);
}

template <class T>
BiNode<T> * BST<T>::Search(BiNode<T> * R, T key)
{
	if (nullptr == R)
		return nullptr;
	if (key == R->data)
		return R;
	else if (key < R->data)
		return Search(R->lchild, key);
	else
		return Search(R->rchild, key);
}

template <class T>
bool BST<T>::DeleteBST(BiNode<T> * & R, T key)
{
	if (nullptr == R) return false;
	else{
		if (key == R->data){
			Delete(R);
			return true;
		}
		else if (key < R->data){
			return DeleteBST(R->lchild, key);
		}
		else
			return DeleteBST(R->rchild, key);
	}
}

template <class T>
void BST<T>::Delete(BiNode<T> * & R)
{
	BiNode<T> * q, *s;
	if (nullptr == R->lchild){
		q = R;
		R = R->rchild;
		delete q;
	}
	else if (nullptr == R->rchild){
		s = R;
		R = R->lchild;
		delete s;
	}
	else{
		q = R;
		s = R->lchild;
		while (nullptr != s->rchild){
			q = s;
			s = s->rchild;
		}
		R->data = s->data;
		if (q != R)
			q->rchild = s->lchild;
		else
			R->lchild = s->lchild;
		delete s;
	}
}

template <class T>
int BST<T>::FindKeyLevel(BiNode<T> * R, T key, int i)
{
	if (nullptr == R)
		return 0;
	if (key == R->data)
		return i;
	else if (key < R->data)
		return FindKeyLevel(R->lchild, key, i + 1);
	else
		return FindKeyLevel(R->rchild, key, i + 1);
}

template <class T>
int BST<T>::FindKeyLevel(BiNode<T> * R, T key)
{
	int i = 1;
	while (R != nullptr){
		if (key == R->data)
			return i;
		else if (key < R->data)
		{
			R = R->lchild;
			++i;
		}
		else{
			R = R->rchild;
			++i;
		}
	}
	return 0;
}

template <class T>
bool BST<T>::IsSorted(BiNode<T> * R) const
{
	if (nullptr != R){
		BiNode<T> * p = R->lchild;
		BiNode<T> * q = R->rchild;
		if (nullptr != p && R->data < p->data)
			return false;
		else
			return IsSorted(R->lchild);
		if (nullptr != q && R->data > q->data)
			return false;
		else
			return IsSorted(R->rchild);
	}
	return true;
}

#endif