#ifndef _SORT_H
#define _SORT_H

#include <iostream>

using namespace std;
#define MAX_LENGHT_INSERT_SORT 50

template <class T>
class Sort
{
private:
	
	void MSort(T S[], T D[], int start, int end);
	void Merge(T S[], T D[], int start, int mid, int end);
	void QSort(T a[], int low, int high);
	
public:
	int Partition(T a[], int low, int high);
	void HeapAdjust(T a[], int start, int end);
	void BestSort(T a[], int n);
	void BubbleSort(T a[], int n);
	void SelectSort(T a[], int n);
	void InsertSort(T a[], int n);
	void ShellSort(T a[], int n);
	void HeapSort(T a[], int n);
	void MergeSort(T a[], int n);
	void QuickSort(T a[], int n);
	void Print(T a[], int n);

	//test
	void bidBubbleSort(T a[], int n);
	void InsertForMerge(T a[], int start, int end);
	void MergeSortBest(T a[], int start, int end);
	void MergeBest(T a[], int start,int mid, int end);
};
template <class T>
void Sort<T>::BubbleSort(T a[], int n)
{
	bool flag = true;
	for (int i = 1; i < n && flag; ++i){
		flag = false;
		for (int j = n; j > i; --j){
			if (a[j] < a[j - 1]){
				a[0] = a[j];
				a[j] = a[j - 1];
				a[j - 1] = a[0];
				flag = true;
			}
		}
	}
}
template <class T>
void Sort<T>::SelectSort(T a[], int n)
{
	for (int i = 1; i < n; ++i){
		int min = i;
		for (int j = i + 1; j <= n; ++j){
			if (a[j] < a[min]){
				min = j;
			}			
		}
		if (min != i){
			a[0] = a[i];
			a[i] = a[min];
			a[min] = a[0];
		}
	}
}
template <class T>
void Sort<T>::InsertSort(T a[], int n)
{
	int i,j;
	for (i = 2; i <= n; ++i){
		if (a[i] < a[i - 1]){
			a[0] = a[i];
			for (j = i - 1; a[j] > a[0]; --j)
				a[j + 1] = a[j];
			a[j+1] = a[0];
		}
		/*j = i - 1;
		a[0] = a[i];
		while (j>0 && a[j] > a[i] ){
			a[j + 1] = a[j];
			--j;
		}
		if (a[i] != a[0]){
			a[j] = a[0];
		}*/
	}
}
template <class T>
void Sort<T>::ShellSort(T a[], int n)
{
	int i, j, d;
	for (d = n / 2; d >= 1; d /= 2){
		for (i = d + 1; i <= n; ++i){
			if (a[i] < a[i - d]){
				a[0] = a[i];
				for (j = i - d; j > 0 &&a[j] > a[0]; j -= d){
					a[j + d] = a[j];
				}
				a[j + d] = a[0];
			}
		}
	}
}
template <class T>
void Sort<T>::HeapSort(T a[], int n)
{
	for (int i = n / 2; i >= 1; --i){
		HeapAdjust(a, i, n);
	}
	for (int i = n; i >= 1;--i){
		a[0] = a[i];
		a[i] = a[1];
		a[1] = a[0];
		HeapAdjust(a, 1, i-1);
	}
}
template <class T>
void Sort<T>::HeapAdjust(T a[], int start, int end)
{
	a[0] = a[start];
	for (int i = 2 * start; i <= end; i *= 2){
		if (i < end&& a[i] < a[i + 1])++i;
		if (a[0] >= a[i])break;
		a[start] = a[i];
		start = i;
	}
	a[start] = a[0];
	/*int i = start;
	int j = 2 * i;
	while (j <= end){
		if (j < end && a[j] < a[j + 1])++j;
		if (a[i] > a[j])break;
		else{
			a[0] = a[i];
			a[i] = a[j];
			a[j] = a[0];
			i = j;
			j = 2 * i;
		}
	}*/
}
template <class T>
void Sort<T>::MergeSort(T a[], int n)
{
	MSort(a, a, 1, n);
}
template <class T>
void Sort<T>::MSort(T S[], T D[], int start, int end)
{
	int m;
	T temp[MAXSIZE + 1];
	if (start == end)
		D[start] = S[start];
	else{
		m = (start + end) / 2;
		MSort(S, temp, start, m);
		MSort(S, temp, m + 1, end);
		Merge(temp, D, start, m, end);
	}
}
template <class T>
void Sort<T>::Merge(T S[], T D[], int start, int mid, int end)
{
	int i = start;
	int j = mid+1;
	int k = start;
	while (i <= mid && j <= end){
		if (S[i] < S[j])
			D[k++] = S[i++];
		else
			D[k++] = S[j++];
	}
	while (i <= mid)
		D[k++] = S[i++];
	while (j <= end)
		D[k++] = S[j++];
}
template <class T>
void Sort<T>::QuickSort(T a[], int n)
{
	QSort(a, 1, n);
}
template <class T>
void Sort<T>::QSort(T a[], int low, int high)
{
	int pivot;
	if (low < high){
		pivot = Partition(a, low, high);
		QSort(a, low, pivot);
		QSort(a, pivot + 1, high);
	}
}
template <class T>
int Sort<T>::Partition(T a[], int low, int high)
{
	int pivot = low;
	a[0] = a[pivot];
	//
	while (low < high){
		while (low<high && a[high] >= a[0])
			--high;
		a[low] = a[high];
		while (low<high && a[low] <= a[0])
			++low;
		a[high] = a[low];
		pivot = low;
	}
	a[pivot] = a[0];
	return pivot;
}
template <class T>
void Sort<T>::BestSort(T a[], int n)
{
	if (n <= MAX_LENGHT_INSERT_SORT)
		InsertSort(a, n);
	else
		QuickSort(a, n);
}
template <class T>
void Sort<T>::Print(T a[], int n)
{
	cout << "Array:\t";
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << endl;
}
template <class T>
void Sort<T>::bidBubbleSort(T a[], int n)
{	
	int left = 1;
	int right = n;
	int min = 1;
	int max = n;
	while (left < right){
		min = left;
		a[0] = a[left];
		for (int i = left + 1; i <= right; ++i){
			if (a[min]>a[i])
				min = i;
		}
		a[left] = a[min];
		a[min] = a[0];
		++left;

		max = right;
		a[0] = a[right];
		for (int j = right; j >= left; --j){
			if (a[max] < a[j])
				max = j;
		}
		a[right] = a[max];
		a[max] = a[0];
		--right;
	}	
}
template <class T>
void Sort<T>::InsertForMerge(T a[], int start, int end)
{	
	int i, j;
	for (int i = start + 1; i <= end; ++i){
		if (a[i] < a[i - 1]){
			a[0] = a[i];
			for (j = i-1; j >= start && a[j]>a[0]; --j)
				a[j+1] = a[j];
			a[j + 1] = a[0];
		}
	}
}
template <class T>
void Sort<T>::MergeSortBest(T a[], int start, int end)
{
	if (end - start + 1 <= 7)
		InsertForMerge(a, start, end);
	else{
		int mid = (start + end) / 2;
		MergeSortBest(a, start, mid);
		MergeSortBest(a, mid + 1, end);
		MergeBest(a, start, mid, end);
	}	
}
template <class T>
void Sort<T>::MergeBest(T a[], int start,int mid, int end)
{
	T temp[MAXSIZE];
	for (int i = start; i <= end; ++i)
		temp[i] = a[i];
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end){
		if (temp[i] < temp[j])
			a[k++] = temp[i++];
		else
			a[k++] = temp[j++];
	}
	while (i <= mid)a[k++] = temp[i++];
	while (j <= end)a[k++] = temp[j++];
}
#endif