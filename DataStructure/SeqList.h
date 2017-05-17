#ifndef _SEQLIST_H
#define _SEQLIST_H
#include <iostream>
using namespace std;
#define MAXSIZE 1000 //默认最大表长度
/*顺序表模板类定义
 *默认最大表长度 MAXSIZE = 1000
 */
template <class T>
class SeqList
{
private:
	T data[MAXSIZE];	//顺序表存储数组
	int length;			//顺序表表长
public:
	SeqList() { length = 0; }			//默认无参构造函数
	SeqList(const T a[], int n);		//带参构造函数，参数为有 n 个元素的数组 a

	int GetLength(){ return length; }	//获取表长
	void PrintList() const;				//正序打印顺序表
	void Insert(int i, T x);			//将元素 x 插入到表第 i 位（表第 i 位从 1 开始计数，第 1 位在数组中下标为 0）
	T Delete(int i);					//删除表第 i 位元素并返回值
	T Get(int i);						//获取表第 i 位元素并返回值
	int Locate(T x);					//定位元素 x 在表中的位置并返回
	void Reverse();						//反转表中元素，新表是原表的逆序
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
		data[j] = data[j - 1];		//将第 i 位以后的元素后移一位
	data[i - 1] = x;				//将 x 插入到位置 i
	++length;						//表长加一
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
		data[j - 1] = data[j];//将第 i 位后面的元素前移
	--length;//表长减一
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
	//上面是普通交换,下面是就地（使用附加空间最少的）交换
	for (int i = 0; i < length / 2; ++i){
		data[i] += data[length - 1 - i];
		data[length - 1 - i] = data[i] - data[length - 1 - i];
		data[i] = data[i] - data[length - 1 - i];
	}
}
#endif