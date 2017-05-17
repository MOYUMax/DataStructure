#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>

using namespace std;
//单链表模板结构体
template <class T>
struct Node
{
	T data;		//结点值域
	struct Node<T> * next;		//下一结点指针
};
template <class T> class LinkList;		//单链表模板类声明
template <class T> int compare(LinkList<T> & A, LinkList<T> & B);//单链表比较模板函数定义
/* 单链表模板类定义
 * 带表头结点的单链表
 */
template <class T>
class LinkList
{
private:
	Node<T> * front;//表头结点指针

public:
	LinkList(){ front = new Node <T>; front->next = nullptr; }	//无参构造函数
	LinkList(T a[], int n);		//有参构造函数
	~LinkList();		//析构函数
	//成员函数
	Node<T> * GetFront(){ return front; }	//获取头结点指针
	void PrintList() const;		//遍历打印单链表
	int GetLength() const;		//获取单链表表长
	Node<T> * Get(int i) const;	//获取单链表第 i 位的结点指针（位从 1 起始）
	int Locate(T x) const;		//定位元素 x 在单链表的的位次并返回（位 1 起计）
	void Insert(int i, T x);	//将元素 x 插入到单链表第 i 位上
	T Delete(int i);			//删除单链表第 i 位上的元素
	void Reverse();				//反转单链表使新表为原表的逆序
	//友元模板函数
	friend int compare<T>( LinkList<T> & A,LinkList<T> & B);	//比较两个单链表
	template <class T>		
	friend void Mearge(LinkList<T> & A, LinkList<T> & B,LinkList<T> & C);	//合并两个单链表A,B到C（A,B会被破坏）
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
		Node<T> * s = new Node<T>;//为新结点分配内存空间
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
	if (i < 1)
		return nullptr;
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
	if (i != 1) p = Get(i - 1);//获取 i 前一结点的指针，如果是第一位，前结点就是 front,可以直接插入
	if (p){		//在 p 的后面插入新结点 s
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
	if (i != 1)			//如果删除第一个结点，则直接使用 p = front->next
		p = Get(i - 1);	//获取 i 前一结点的指针给 p .
	if (p){
		Node<T> * s = p->next;
		T ret = s->data;
		p->next = s->next;
		delete s;
		return ret;
	}
	else
		throw "Delete Error for locate";
}

template <class T>
void LinkList<T>::Reverse()
{
	if (front->next == nullptr)
		throw "Empty LinkList";

	Node<T> * p = front->next;
	front->next = nullptr;
	Node<T> * temp;
	while (p){//head insert
		temp = p->next;		
		p->next = front->next;
		front->next = p;
		p = temp;
	}
}

template <class T>
int compare(LinkList<T> & A, LinkList<T> & B)
{
	Node<T> * p = A.front->next;
	Node<T> * q = B.front->next;
	
	while (p && q ){
		if (p->data != q->data){
			return (p->data < q->data) ? -1 : 1;
		}
		p = p->next;
		q = q->next;
	}
	if (p)return 1;
	else if (q)return -1;
	else return 0;
}

template <class T>
void Mearge(LinkList<T> & A, LinkList<T> & B, LinkList<T> & C)
{
	Node<T> * c = C.GetFront();
	Node<T> * a = A.GetFront()->next;
	A.GetFront()->next = nullptr;
	Node<T> * b = B.GetFront()->next;
	B.GetFront()->next = nullptr;
	Node<T> * temp;
	while (a && b){
		if (a->data < b->data){
			temp = a->next;
			a->next = c->next;
			c->next = a;
			a = temp;
		}
		else{
			temp = b->next;
			b->next = c->next;
			c->next = b;
			b = temp;
		}
	}
	while (a){
		temp = a->next;
		a->next = c->next;
		c->next = a;
		a = temp;
	}
	while (b){
		temp = b->next;
		b->next = c->next;
		c->next = b;
		b = temp;
	}
	
	return;
}
#endif