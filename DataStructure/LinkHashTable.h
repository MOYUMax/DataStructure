#ifndef _LINKHASHTABLE_H
#define _LINKHASHTABLE_H

#include <iostream>

using namespace std;

//template <class T>
//struct Node
//{
//	T data;
//	Node<T> * next;
//};

template <class T>
class LinkHashTable
{
private:
	Node<T> ** HeadTable;
	int N;
public:
	LinkHashTable(int n) :N(n){};
	~LinkHashTable();
	int hash(T x){ return x % 13; }
	void CreateHashTable(T r[], int n);
	bool Find(T key);
	double ASL(bool success, int n);
	bool Delete(T key);
};

template <class T>
void LinkHashTable<T>::CreateHashTable(T r[], int n)
{
	HeadTable = new Node<T>*[N];
	memset(HeadTable, 0, sizeof(Node<T> *)* N);
	for (int i = 0; i < n; ++i){
		Node<T> * s = new Node<T>;
		s->data = r[i];
		s->next = HeadTable[hash(r[i])];
		HeadTable[hash(r[i])] = s;
	}
}

template <class T>
bool LinkHashTable<T>::Find(T key)
{
	Node<T> * p = HeadTable[hash(key)];
	while (p != nullptr){
		if (key == p->data)
			return true;
		p = p->next;
	}
	return false;
}

template <class T>
double LinkHashTable<T>::ASL(bool success, int n)
{
	double sum = 0;
	Node<T> * p = nullptr;
	if (success){
		for (int i = 0; i < N; ++i){
			p = HeadTable[i];
			int c = 0;
			while (p != nullptr){
				++c;
				sum += c;
				p = p->next;
			}
		}
		return sum / n;
	}
	else{
		for (int i = 0; i < N; ++i){
			p = HeadTable[i];
			int c = 0;
			while (p != nullptr){
				++c;
				p = p->next;
			}
			sum = sum + c;
		}
		return sum / N;
	}
}

template <class T>
LinkHashTable<T>::~LinkHashTable()
{
	for (int i = 0; i < N; ++i){
		Node<T> * p = HeadTable[i];
		while (p != nullptr){
			Node<T> * q = p->next;
			delete p;
			p = q;
		}
	}
	delete HeadTable;
}

template <class T>
bool LinkHashTable<T>::Delete(T key)
{
	//if (!Find(key))
	//	return false;
	Node<T> * p = HeadTable[hash(key)];
	if (nullptr == p)
		return false;
	else if (key == p->data){
		Node<T> * q = p->next;
		delete p;
		HeadTable[hash(key)] = q;
		return true;
	}
	else{
		Node<T> * q = p->next;
		while (nullptr != q){
			if (key == q->data){
				p->next = q->next;
				delete q;
				return true;
			}
			p = q;
			q = q->next;
		}
	}
	return false;
}

#endif