#ifndef _CLINKQUEUE_H
#define _CLINKQUEUE_H

#include "CLinkList.h"
#include <iostream>

using namespace std;

template <class T>
class CLinkQueue
{
private:
//	Node<T> * front;
	Node<T> * rear;
	//Node<T> * GetRear()const{ return rear = cq.GetRear() };
protected:
	CLinkList<T> cq;
public:
	CLinkQueue(){ rear = cq.GetRear(); }

	~CLinkQueue();
	void EnQueue(T x);
	T DeQueue();	
	void SetNull();
	int GetLength();
	bool isEmpty();
};

template <class T>
CLinkQueue<T>::~CLinkQueue()
{
	rear = cq.GetRear()->next;
	cq.~CLinkList();	
}

template <class T>
void CLinkQueue<T>::EnQueue(T x)
{
	int i = cq.GetLength();
	cq.Insert(i + 1, x);
}
template <class T>
T CLinkQueue<T>::DeQueue()
{
	Node<T> * p = cq.GetRear()->next;
	T ret = cq.DeleteNext(p);
	return ret;
}
template <class T>
void CLinkQueue<T>::SetNull()
{
	rear = cq.GetRear()->next;
	cq.~CLinkList();
}
template <class T>
int CLinkQueue<T>::GetLength()
{
	return cq.GetLength();
}
template <class T>
bool CLinkQueue<T>::isEmpty()
{
	return cq.GetLength() <= 0 ? true : false;
}

#endif