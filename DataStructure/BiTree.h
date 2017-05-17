#ifndef _BITREE_H
#define _BITREE_H

#include <iostream>
#include <queue>
 
using namespace std;

template <class T>
struct BiNode
{
	T data;				//�������ڵ�������
	BiNode<T> * lchild;	//�ڵ�����ָ����
	BiNode<T> * rchild;	//�ڵ��Һ���ָ����
	BiNode() :lchild(nullptr), rchild(nullptr){};
};

enum Order{Pre,In,Post,Level};		//ǰ���С��󡢲���ö��

template <class T>
class BiTree
{
private:
//	void Create(BiNode<T> ** R);	//�ǵݹ鴴�����������û�����ǰ���ַ���
	void Create(BiNode<T> * & R);	//�������������û�������ʾ����ڵ��ַ�
	void Create(BiNode<T> * & R, T data[], int i, int n);	//���� n ���ȵ� T �����λ�� i ������������T �����ǰ��� 2*i �� 2*i+1Ϊ�ӽڵ�ķ�ʽ
	void Create(BiNode<T> * & R, T PreData[], T InData[], int s1, int e1, int s2, int e2);	//����ǰ��������������鴴����������s1,e1,s2,e2�ֱ�Ϊ�����������ʼ���ս��
	void Release(BiNode<T> * R);	//�ͷ����ڵ� R
	int find(T InData[], T e, int s2, int e2);		//�� T ���� [s2,e2]�в���Ԫ�� e
public:
	BiNode<T> * root;				//��������ָ��
	BiTree();						//BiTreeĬ�ϳ�ʼ�����������봴��������
	BiTree(BiTree<T> * t);			//copy constructer
	BiTree(T data[], int n);		//����˳��洢�� �� ���� T ����������
	BiTree(T PreData[], T InData[], int s1, int e1, int s2, int e2);	//��ǰ���������鴴��������
	~BiTree();

	void Print(Order porder);		//������ӡ������
	void PreOrder(BiNode<T> * R);	//ǰ�������ӡ������
	void InOrder(BiNode<T> * R);	//���������ӡ������
	void PostOrder(BiNode<T> * R);	//����������ӡ������
	void LevelOrder(BiNode<T> * R);	//���������ӡ������
	void CopyTree(BiNode<T> * src, BiNode<T> * & dst);	//���ƶ�����
	bool Path(BiNode<T> * R, T e);	//��ȡԪ�� e �ڶ������е�·��
	int Depth(BiNode<T> * R);		//����������ĸ߶�
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

//�ݹ�ǰ�������
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

//�ǵݹ�ǰ�������
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
		if (R->data == e){				//����Ǹ�Ԫ�أ����ӡ����
			cout << R->data;
			return true;
		}
		else if (Path(R->lchild, e)){	//�ݹ������������������ e ��ӡ����
			cout << R->data;
			return true;
		}
		else if (Path(R->rchild, e)){	//�ݹ������������������ e ��ӡ����
			cout << R->data;
			return true;
		}
		else return false;				//�����ڣ����ؿ�
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