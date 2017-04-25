#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>

using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node<T> * next;
};

template <class T>
class LinkList
{
private:
	Node<T> * front;

public:
	LinkList(){ front = new Node <T>; front->next = nullptr; }
	LinkList(T a[], int n);
	~LinkList();

	void PrintList() const;
	int GetLength() const;
	Node<T> * Get(int i) const;
	int Locate(T x) const;
	void Insert(int i, T x);
	T Delete(int i);
};

template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	//head insert
	/*front = new Node<T>;
	front->next = nullptr;
	for (int i = 0; i < n; ++i){
		Node<T> * s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;		
	}*/

	//tail insert init
	front = new Node<T>;
	front->next = nullptr;
	Node<T> * r = front;
	for (int i = 0; i < n; ++i){
		Node<T> * s = new Node<T>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = nullptr;
}
template <class T>
LinkList<T>::~LinkList()
{
	Node<T> * p = front;
	while (p){
		front = p;
		p = p->next;
		delete front;
	}
}
template <class T>
void LinkList<T>::PrintList()const
{
	Node<T> * p = front->next;
	while (p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
template <class T>
int LinkList<T>::GetLength() const
{
	int n = 0;
	Node<T> * p = front->next;
	while (p){
		++n;
		p = p->next;
	}
	return n;
}
template <class T>
Node<T> * LinkList<T>::Get(int i) const
{
	Node<T> * p = front->next;
	int j = 1;
	while (p && j != i){
		p = p->next;
		++j;
	}
	return p;
}
template <class T>
int LinkList<T>::Locate(T x) const
{
	Node<T> * p = front->next;
	int i = 1;
	while (p && x != p->data){
		p = p->next;
		++i;
	}
	if (!p)
		return -1;
	else
		return i;
}
template <class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T> * p = front;
	if (i != 1) p = Get(i - 1);
	if (p){
		Node<T> * s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else
		throw "Insert error for locate";
}
template <class T>
T LinkList<T>::Delete(int i)
{
	Node<T> * p = front->next;
	if (i != 1)
		p = Get(i - 1);
	
	Node<T> * s = p->next;
	T ret = s->data;
	p->next = s->next;
	delete s;
	return ret;
}

#endif