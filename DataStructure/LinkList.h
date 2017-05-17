#ifndef _LINKLIST_H
#define _LINKLIST_H
#include <iostream>

using namespace std;
//������ģ��ṹ��
template <class T>
struct Node
{
	T data;		//���ֵ��
	struct Node<T> * next;		//��һ���ָ��
};
template <class T> class LinkList;		//������ģ��������
template <class T> int compare(LinkList<T> & A, LinkList<T> & B);//������Ƚ�ģ�庯������
/* ������ģ���ඨ��
 * ����ͷ���ĵ�����
 */
template <class T>
class LinkList
{
private:
	Node<T> * front;//��ͷ���ָ��

public:
	LinkList(){ front = new Node <T>; front->next = nullptr; }	//�޲ι��캯��
	LinkList(T a[], int n);		//�вι��캯��
	~LinkList();		//��������
	//��Ա����
	Node<T> * GetFront(){ return front; }	//��ȡͷ���ָ��
	void PrintList() const;		//������ӡ������
	int GetLength() const;		//��ȡ�������
	Node<T> * Get(int i) const;	//��ȡ������� i λ�Ľ��ָ�루λ�� 1 ��ʼ��
	int Locate(T x) const;		//��λԪ�� x �ڵ�����ĵ�λ�β����أ�λ 1 ��ƣ�
	void Insert(int i, T x);	//��Ԫ�� x ���뵽������� i λ��
	T Delete(int i);			//ɾ��������� i λ�ϵ�Ԫ��
	void Reverse();				//��ת������ʹ�±�Ϊԭ�������
	//��Ԫģ�庯��
	friend int compare<T>( LinkList<T> & A,LinkList<T> & B);	//�Ƚ�����������
	template <class T>		
	friend void Mearge(LinkList<T> & A, LinkList<T> & B,LinkList<T> & C);	//�ϲ�����������A,B��C��A,B�ᱻ�ƻ���
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
		Node<T> * s = new Node<T>;//Ϊ�½������ڴ�ռ�
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
	if (i != 1) p = Get(i - 1);//��ȡ i ǰһ����ָ�룬����ǵ�һλ��ǰ������ front,����ֱ�Ӳ���
	if (p){		//�� p �ĺ�������½�� s
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
	if (i != 1)			//���ɾ����һ����㣬��ֱ��ʹ�� p = front->next
		p = Get(i - 1);	//��ȡ i ǰһ����ָ��� p .
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