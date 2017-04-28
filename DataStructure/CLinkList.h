#ifndef _CLINKLIST_H
#define _CLINKLIST_H

#include "LinkList.h"
#include <iostream>
using namespace std;

//template <class T>
//struct Node<T>
//{
//	T data;
//	struct Node<T> * next;
//};

template <class T>
class CLinkList
{
private:
	Node<T> * rear;
	int length;
public:
	CLinkList(){ rear = new Node<T>; rear->next = rear; length = 0; }
	CLinkList(T a[], int n);
	~CLinkList();

	Node<T> * GetRear(){ return rear; }//获取头指针
	int GetLength() const;//获取长度
	Node<T> * Get(int i) const;//获取第 i 位置的元素并返回
	int Locate(T x) const; //定位元素 x 的位置（元素位置从 1 开始）
	void Insert(int i, T x);//在第 i 位置上插入元素 x
	void Insert(int i, Node<T> * s);//将 s 所指节点插入到第 i 位置
	T Delete(int i);//删除第i位置节点
	T Delete(Node<T> * s);//删除 s 所指节点
	T DeleteNext(Node<T> * s);//删除 s 直接后继节点
	void PrintList() const;
	T DeletePrior(Node<T> * s);//删除 s 直接前驱节点
};

template <class T>
CLinkList<T>::CLinkList(T a[], int n)
{	
	rear = new Node<T>;
	rear->next = rear;	
	length = 0;
	for (int i = 0; i < n; ++i){//tail insert initial
		Node<T> * s = new Node<T>;
		s->data = a[i];
		s->next = rear->next;
		rear->next = s;
		rear = s;
	}
	length = n;
}
template <class T>
CLinkList<T>::~CLinkList()
{
	Node<T> * p = rear->next;
	Node<T> * q = p->next;
	while (p != rear && q != nullptr ){
		if (q == rear){
			rear = p;
		}
		p->next = q->next;		
		delete q;
		q = p->next;
	}
	length = 0;
}
template <class T>
int CLinkList<T>::GetLength() const
{
	return length;
	/*Node<T> * p = rear->next;
	int length = 0;
	while (p != rear){
		++length;
		p = p->next;
	}
	return length+1;*/
}

template <class T>
Node<T> * CLinkList<T>::Get(int i)const
{
	Node<T> * p = rear->next->next;//获取第 1 元素位置地址
	while (--i > 0)	p = p->next;//到达第 i 元素位置地址
	return p;
}
//获取循环链表中元素值为 x 的第一个节点的位置 i
template <class T>
int CLinkList<T>::Locate(T x)const
{
	Node<T> * p = rear->next;
	if (p == rear)
		throw "Locate Error, argument inexistence";
	int i = 0;	
	while (p != rear)
	{
		++i;
		p = p->next;
		if (x == p->data)
			return i;
	}
	if (p==rear)
		return -1;
	return 0;
}
template <class T>
void CLinkList<T>::Insert(int i, T x)
{	
	if (i <= 0){		
		throw "Insert Error for i <= 0";
	}
	Node<T> * p = rear->next;//头结点		
	for (int j = 0; j < i-1; ++j){
		p = p->next;
	}//到达第i节点的前一节点

	Node<T> * s = new Node<T>;
	s->data = x;
	s->next = p->next;
	p->next = s;
	++length;
	if (p == rear)
		rear = s;
	return;
}

template <class T>
void CLinkList<T>::Insert(int i, Node<T> * s)
{
	Node<T> * p = rear->next;
	int j = 0;
	while (++j < i)
		p = p->next;
	s->next = p->next;
	p->next = s;
	if (p == rear)
		rear = p->next;
	++length;
}

template <class T>
T CLinkList<T>::Delete(int i)
{	
	Node<T> * p = rear->next;//头结点
	Node<T> * q = rear->next->next;//头结点后的第一个节点
	if (i <= 0)
		throw "Delete Error for i <= 0";
	for (int j = 0; j < i - 1; ++j){
		p = q;
		q = q->next;
	}
	T x = q->data;
	p->next = q->next;
	if (q == rear)
		rear = p;
	delete q;
	--length;
	return x;
}

template <class T>
T CLinkList<T>::Delete(Node<T> * s)
{
	Node<T> * p = rear->next;
	while (p != rear&& p->next != s){
		p = p->next;
	}
	if (s == rear)
		rear = p;
	p->next = s->next;
	T ret = s->data;
	delete s;
	--length;
	return ret;
}

template <class T>
void CLinkList<T>::PrintList() const
{
	Node<T> * p = rear->next;
	while (p != rear){
		p = p->next;
		cout << p->data << " ";
	}
	cout <<"\n";
}
//删除节点 S 的直接前驱指针
template<class T>
T CLinkList<T>::DeletePrior(Node<T> * S)
{
	Node<T> * p = rear->next;
	Node<T> * q = p->next;
	if (S == rear){
		T ret = q->data;
		p->next = q->next;
		if (rear == q)
			rear = p;
		delete q;
		--length;
		return ret;
	}
	while ( p != rear && q->next != S){
		p = q;
		q = q->next;
	}
	T ret = q->data;
	p->next = q->next;
	if (q == rear)
		rear = p;
	delete q;
	--length;
	return ret;
}

template<class T>
T CLinkList<T>::DeleteNext(Node<T> * p)
{
	Node<T> * q = p->next;
	T ret = q->data;
	p->next = p->next->next;
	if (q == rear)
		rear = p;
	delete q;
	--length;
	return ret;
}

#endif