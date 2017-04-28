#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <iostream>
//#include "SeqList.h"

using namespace std;

const int StackSize = 1024;

template <class T>
class SeqStack
{
private:
	T data[StackSize];
	int top;
public:
	SeqStack(){ top = -1; }
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty();
};

template<class T>
void SeqStack<T>::Push(T x)
{
	if (top >= StackSize - 1)
		throw "Push error for Stack full";
	data[++top] = x;
}

template <class T>
T SeqStack<T>::Pop()
{
	if (Empty())
		throw "Pop error for Stack empty";
	T ret = data[top];
	--top;
	return ret;
}

template <class T>
T SeqStack<T>::GetTop()
{
	if (Empty())
		throw "GetTop Error for Stack empty";
	return data[top];
}

template <class T>
bool SeqStack<T>::Empty()
{
	return top < 0 ? true : false;
}

#endif