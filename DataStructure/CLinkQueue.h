#ifndef _CLINKQUEUE_H
#define _CLINKQUEUE_H

#include "CLinkList.h"
#include <iostream>

using namespace std;
/*循环队列的链式存储
 *带头结点，使用尾指针 rear
 */
template <class T>
class CLinkQueue
{
private:
//	Node<T> * front;
	Node<T> * rear;		//尾指针
	//Node<T> * GetRear()const{ return rear = cq.GetRear() };
protected:
	CLinkList<T> cq;	//以循环链表对象作为数据基础
public:
	CLinkQueue(){ rear = cq.GetRear(); }	//无参构造函数

	~CLinkQueue();		//队列类析构函数
	void EnQueue(T x);	//队列入队
	T DeQueue();		//队列出队
	void SetNull();		//队列置空
	int GetLength();	//获取队列长度并返回
	bool isEmpty();		//判断队列是否为空
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