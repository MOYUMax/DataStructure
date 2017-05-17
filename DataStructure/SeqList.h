#ifndef _SEQLIST_H
#define _SEQLIST_H
#include <iostream>
using namespace std;
#define MAXSIZE 1000 //Ĭ��������
/*˳���ģ���ඨ��
 *Ĭ�������� MAXSIZE = 1000
 */
template <class T>
class SeqList
{
private:
	T data[MAXSIZE];	//˳���洢����
	int length;			//˳����
public:
	SeqList() { length = 0; }			//Ĭ���޲ι��캯��
	SeqList(const T a[], int n);		//���ι��캯��������Ϊ�� n ��Ԫ�ص����� a

	int GetLength(){ return length; }	//��ȡ��
	void PrintList() const;				//�����ӡ˳���
	void Insert(int i, T x);			//��Ԫ�� x ���뵽��� i λ����� i λ�� 1 ��ʼ�������� 1 λ���������±�Ϊ 0��
	T Delete(int i);					//ɾ����� i λԪ�ز�����ֵ
	T Get(int i);						//��ȡ��� i λԪ�ز�����ֵ
	int Locate(T x);					//��λԪ�� x �ڱ��е�λ�ò�����
	void Reverse();						//��ת����Ԫ�أ��±���ԭ�������
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
		data[j] = data[j - 1];		//���� i λ�Ժ��Ԫ�غ���һλ
	data[i - 1] = x;				//�� x ���뵽λ�� i
	++length;						//����һ
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
		data[j - 1] = data[j];//���� i λ�����Ԫ��ǰ��
	--length;//����һ
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
void SeqList<T>::Reverse()
{
	/*int i = 0, j = length-1;
	while (i != j){
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		++i;
		--j;
	}*/
	//��������ͨ����,�����Ǿ͵أ�ʹ�ø��ӿռ����ٵģ�����
	for (int i = 0; i < length / 2; ++i){
		data[i] += data[length - 1 - i];
		data[length - 1 - i] = data[i] - data[length - 1 - i];
		data[i] = data[i] - data[length - 1 - i];
	}
}
#endif