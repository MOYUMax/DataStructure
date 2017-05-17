#ifndef _MGRAPH_H
#define _MGRAPH_H

#include <iostream>
using namespace std;

//#define MAXV 10
extern const int MAXV;
extern bool visitedVex[];

struct EdgeV
{
	int start;
	int end;
	int weight;
};

template <class T>
class MGraph
{
private:
	T vertex[MAXV];
	int numVex, numEdge;
	int arc[MAXV][MAXV];

	EdgeV edges[MAXV*(MAXV - 1)];
	int adjvex[MAXV];
	int lowcost[MAXV];
	int mininum();
	void SortEdge();

	bool S[MAXV];
	int D[MAXV];
	int P[MAXV];
	int FindMin();
	void Print();
public:
	MGraph();
	MGraph(T a[], int n, int e);
	void DFS(int v);
	void BFS(int v);
	void Prim();
	void Kruskal();
	void Dijkstra(int v);
	void Floyd();
};

template <class T>
MGraph<T>::MGraph()
{
	char a[7] = "ABCDEF";
	int start[9] = { 0, 0, 0, 1, 2, 2, 3, 3, 4 };
	int end[9] = { 1, 2, 5, 4, 3, 5, 4, 5, 5 };
	int edge[9] = { 34, 46, 19, 12, 17, 25, 38, 25, 26 };
	numVex = 6;
	numEdge = 9;
	for (int i = 0; i < numVex; ++i)
		vertex[i] = a[i];
	for (int i = 0; i < MAXV; ++i)
		for (int j = 0; j < MAXV; ++j)
		{
			arc[i][j] = MAXSIZE;
		}
	for (int k = 0; k < numEdge; ++k){
		int i = start[k];
		int j = end[k];
		arc[i][j] = edge[k];
		arc[j][i] = edge[k];
	}
}

template <class T>
MGraph<T>::MGraph(T a[], int n, int e)
{
	numVex = n;
	numEdge = e;
	for (int i = 0; i < numVex; ++i)
		vertex[i] = a[i];
	for (int i = 0; i < numVex; ++i)
		for (int j = 0; j < numVex; ++j)
			arc[i][j] = 0;
	int i, j;
	for (int k = 0; k < numEdge; ++k){
		cout << "Please input the Edge's start and end(div):";
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}
}

template <class T>
void MGraph<T>::DFS(int v)
{
	cout << vertex[v];
	visitedVex[v] = true;
	for (int j = 0; j < numVex; ++j)
		if (arc[v][j] == 1 && !visitedVex[j])
			DFS(j);
}

template <class T>
void MGraph<T>::BFS(int v)
{
	int queue[MAXV];
	int tail = 0;
	int front = 0;
	cout << vertex[v];
	visitedVex[v] = true;
	queue[++tail] = v;
	while (front != tail)
	{
		v = queue[++front];
		for (int j = 0; j < numVex; ++j)
		{
			if (arc[v][j] == 1 && !visitedVex[j])
			{
				cout << vertex[j];
				visitedVex[j] = true;
				queue[++tail] = j;
			}
		}
	}
}

/* 
 *
 */
template <class T>
int MGraph<T>::mininum()
{
	int min = INT_MAX;
	int k = 0;
	for (int i = 1; i < numVex; ++i){
		if (lowcost[i] != 0 && lowcost[i] < min){
			min = lowcost[i];
			k = i;
		}
	}
	return k;
}

template <class T>
void MGraph<T>::Prim()
{
	for (int i = 0; i < numVex; ++i){
		adjvex[i] = 0;
		lowcost[i] = arc[0][i];
	}
	lowcost[0] = 0;
	for (int i = 1; i < numVex; ++i){
		int k = mininum();
//		cout << 'V' << adjvex[k] << "->V" << k << endl;
		cout << vertex[adjvex[k]] << "->" << vertex[k] <<" weight = "<<arc[adjvex[k]][k]<< endl;
		lowcost[k] = 0;
		for (int j = 0; j < numVex; ++j){
			//if (lowcost[j] != 0 && arc[k][j] < lowcost[j])
			if (lowcost[j] > 0 && arc[k][j] < lowcost[j])
			{
				lowcost[j] = arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

template <class T>
void MGraph<T>::SortEdge()
{
	int k = 0;
	for (int i = 0; i < numVex; ++i)
		for (int j = i; j < numVex;++j)
			if (arc[i][j] != MAXSIZE)
			{
				edges[k].start = i;
				edges[k].end = j;
				edges[k].weight = arc[i][j];
				++k;
			}
	for (int i = 0; i < numEdge; ++i)
	{
		for (int j = i; j < numEdge;++j)
			if (edges[i].weight > edges[j].weight){
				EdgeV temp = edges[i];
				edges[i] = edges[j];
				edges[j] = temp;
			}
	}
}

template <class T>
void MGraph<T>::Kruskal()
{
	SortEdge();
	int vset[MAXV];
	for (int i = 0; i < numVex; ++i)
		vset[i] = i;
	int k = 0;
	while (k < numVex){
		int m = edges[k].start;
		int n = edges[k].end;
		int sn1 = vset[m];
		int sn2 = vset[n];
		if (sn1 != sn2)
		{
			cout << vertex[m] << "->" << vertex[n] << " weight = " << arc[m][n] << endl;
			++k;
			for (int i = 0; i < numVex; ++i){
				if (vset[i] == sn2)
					vset[i] = sn1;
			}
		}
		else
			++k;
	}
}

template <class T>
void MGraph<T>::Print()
{
	for (int i = 0; i < numVex; ++i){
		cout << vertex[i] << ":" << vertex[P[i]] << "\t{" << vertex[i];
		int pre = P[i];
		while (pre != -1){
			cout << vertex[pre];
			pre = P[pre];
		}
		cout << "}" << endl;
	}
}

template <class T>
int MGraph<T>::FindMin()
{
	int k = 0, min = INT_MAX;
	for (int i = 0; i < numVex; ++i){
		if (!S[i] && min>D[i]){
			min = D[i];
			k = i;
		}
	}
	if (min == MAXSIZE)
		return -1;
	return k;
}


template <class T>
void MGraph<T>::Dijkstra(int v)
{
	for (int i = 0; i < MAXV; ++i)
		S[i] = false;
	for (int i = 0; i < numVex; ++i)
	{
		D[i] = arc[0][i];
		if (D[i] != MAXSIZE)
			P[i] = v;
		else
			P[i] = -1;
	}
	S[v] = true;
	D[v] = 0;
	for (int i = 0; i < numVex; ++i)
	{
		if ((v = FindMin()) == -1)
			return;
		S[v] = true;
		for (int j = 0; j < numVex;++j)
			if (!S[j] && (D[j]>arc[v][j] + D[v])){
				D[j] = arc[v][j] + D[v];
				P[j] = v;
			}
	}
	Print();
}

template <class T>
void MGraph<T>::Floyd()
{
	int dist[MAXV][MAXV];
	int path[MAXV][MAXV];
	for (int i = 0; i < numVex; ++i)
		for (int j = 0; j < numVex; ++j)
		{
			dist[i][j] = arc[i][j];
			path[i][j] = j;
		
		}
	for (int k = 0; k < numVex; ++k)
		for (int i = 0; i < numVex; ++i)
			for (int j = 0; j < numVex;++j)
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k];
				}
	//print
	for (int v = 0; v < numVex; ++v)
	{
		for (int w = v + 1; w < numVex; ++w){
			cout << vertex[v] << "->" << vertex[w] << " weight:" << dist[v][w];
			int k = path[v][w];
			cout << "\tpath:" << vertex[v];
			while (k != w){
				cout << "->" << vertex[k];
				k = path[k][w];
			}
			cout << "->" << vertex[w] << endl;
		}
		cout << endl;
	}
}

#endif