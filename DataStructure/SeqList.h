#ifndef _SEQLIST_H
#define _SEQLIST_H
#include <iostream>
using namespace std;
#define MAXSIZE 1000

template <class T>
class SeqList
{
private:
	T data[MAXSIZE];
	int length;
public:
	SeqList() { length = 0; }
	SeqList(const T a[], int n);

	int GetLength(){ return length; }
	void PrintList() const;
	void Insert(int i, T x);
	T Delete(int i);
	T Get(int i);
	int Locate(T x);
	void Swap();
};

template <class T>
SeqList<T>::SeqList(const T a[], int n)
{
	if (n > MAXSIZE)
		throw "array length n over the MAXSIZE";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<class T>
void SeqList<T>::PrintList() const
{
	cout << "Print The SeqList:\n";
	for (int i = 0; i < length; ++i){
		cout << data[i] << " ";
	}
	cout << endl;
}

template <class T>
void SeqList<T>::Insert(int i, T x)
{
	if (length >= MAXSIZE)
		throw "length overflow";
	if (i<1 || i>MAXSIZE)
		throw "locate i error";
	for (int j = length; j >= i; --j)
		data[j] = data[j - 1];
	data[i - 1] = x;
	++length;
}

template <class T>
T SeqList<T>::Delete(int i)
{
	if (length <= 0)
		throw "length underflow";
	if (i<1 || i>MAXSIZE)
		throw "locate i error";
	T ret = data[i - 1];
	for (int j = i; j < length; ++j)
		data[j - 1] = data[j];
	--length;
	return ret;
}

template <class T>
T SeqList<T>::Get(int i)
{
	if (i<1 || i>length)
		throw "locate i error";
	return data[i - 1];
}
template <class T>
int SeqList<T>::Locate(T x)
{
	for (int i = 0; i < length; ++i)
		if (x == data[i])
			return i + 1;
	return 0;
}

template <class T>
void SeqList<T>::Swap()
{
	/*int i = 0, j = length-1;
	while (i != j){
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		++i;
		--j;
	}*/
	//上面是普通交换,下面是就地（使用附加空间最少的）交换
	for (int i = 0; i < length / 2; ++i){
		data[i] += data[length - 1 - i];
		data[length - 1 - i] = data[i] - data[length - 1 - i];
		data[i] = data[i] - data[length - 1 - i];
	}
}
#endif