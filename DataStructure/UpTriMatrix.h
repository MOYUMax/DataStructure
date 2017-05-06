#ifndef _UPTRIMATRIX_H
#define _UPTRIMATRIX_H

#include <iostream>

using namespace std;

enum MTXSAVETYPE {ROW, COL};

template <class T>
class UpTriMatrix
{
private:
	int n;					//上三角矩阵的阶数 n
	T * a;	//矩阵元素存储数组
	int length;
	MTXSAVETYPE savetype;
public:
	UpTriMatrix() :n(0), length(0), savetype(ROW){ a = nullptr; };
	UpTriMatrix(T * * uptrimatrix, int ni, MTXSAVETYPE stype);
	~UpTriMatrix(){ if (a != nullptr) delete a; };

	void UpTriMatrixInit();
	T ** Convert();
	MTXSAVETYPE getSaveType() const{ return savetype; };
	int  getOrder() const{ return n; };
	T getElem(int row,int col)const;
	int getLoca(T *)const;
	bool setElem(int row, int col, T x);
};

template <class T>
UpTriMatrix<T>::UpTriMatrix(T ** matrix, int ni, MTXSAVETYPE stype)
{
	n = ni;
	savetype = stype;
	length = n*(n + 1) / 2 + 1;
	a = new T[length];
	int k = 0;
	for (int i = 0; i < ni; ++i){
		if (ROW == savetype){
			for (int j = i; j < ni; ++j){
				a[k++] = matrix[i][j];
			}
		}
		else{
			for (int j = 0; j <= i; ++j){
				a[k++] = matrix[j][i];
			}
		}
	}
	a[k] = matrix[ni - 1][0];//common number
}

//template <class T>
//UpTriMatrix<T>::~UpTriMatrix()
//{
//	delete a;
//}

template <class T>
T ** UpTriMatrix<T>::Convert()
{
	T ** matrix = new T * [n];
	matrix[0] = new T[n*n];
	for (int i = 1; i < n; ++i)
		matrix[i] = matrix[i - 1] + n;
	int k = 0;
	for (int i = 0; i < n; ++i){
		if (ROW == savetype){
			for (int j = 0; j < i; ++j)
				matrix[i][j] = a[length-1];
			for (int j = i; j < n; ++j)
				matrix[i][j] = a[k++];
		}
		else{
			for (int j = 0; j <= i; ++j)
				matrix[j][i] = a[k++];
			for (int j = i + 1; j < n; ++j)
				matrix[j][i] = a[length - 1];
		}
	}
	return matrix;
}

#endif