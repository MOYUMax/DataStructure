#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#include <iostream>
//#include "SeqList.h"

using namespace std;

const int StackSize = 1024;
/*顺序栈模板类定义
 *栈最大容量 StackSize
 */
template <class T>
class SeqStack
{
private:
	T data[StackSize];	//栈数据空间
	int top;	//栈顶
public:
	SeqStack(){ top = -1; }	//无参初始化
	void Push(T x);		//入栈
	T Pop();	//出栈
	T GetTop();	//获取栈顶元素（不出栈）
	bool Empty();		//判断栈是否为空栈
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