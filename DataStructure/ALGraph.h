#ifndef _ALGRAPH_H
#define _ALGRAPH_H

#include <iostream>

using namespace std;

extern const int MAXV;

struct ArcNode
{
	int adjvex;
	ArcNode * next;
};

template <class T>
struct VexNode
{
	T vertex;
	ArcNode * firstarc;
};

template <class T>
class ALGraph
{
private:
	int numVertex, numEdge;
	VexNode<T> vexList[MAXV];
public:
	ALGraph();
	ALGraph(T a[], int n, int e);
	~ALGraph();
	void DFS(int v);
	void BFS(int v);
};

template <class T>
ALGraph<T>::ALGraph()
{
	//int edge[30] = { 0, 1, 0, 7, 1, 2, 1, 6, 1, 7, 2, 3, 2, 6, 3, 4, 3, 6, 4, 5, 4, 6, 5, 6, 5, 7, 6, 7 };
	int start[14] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6 };
	int end[14] = { 1, 7, 2, 6, 7, 3, 6, 4, 6, 5, 6, 6, 7, 7 };
	numEdge = 14;
	numVertex = 8;
	char v[9] = "ABCDEFGH";
	for (int k = 0; k < numVertex; ++k){
		vexList[k].vertex = v[k];
		vexList[k].firstarc = nullptr;
	}
	for (int k = 0; k < 14; ++k){
		ArcNode * s = new ArcNode;
		s->adjvex = end[k];
		s->next = vexList[start[k]].firstarc;
		vexList[start[k]].firstarc = s;

		ArcNode * p = new ArcNode;
		p->adjvex = start[k];
		p->next = vexList[end[k]].firstarc;
		vexList[end[k]].firstarc = p;
	}
}

template <class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	numVertex = n;
	numEdge = e;
	for (int k = 0; k < numVertex; ++k){
		vexList[k].vertex = a[k];
		vexList[k].firstarc = nullptr;
	}
	int i, j;
	for (int k = 0; k < e; ++k)
	{
		cout << "Please input the Edge start and end:";
		cin >> i >> j;
		ArcNode * s = new ArcNode;		
		s->adjvex = j;
		//head insert
		s->next = vexList[i].firstarc;
		vexList[i].firstarc = s;
	}
}

template <class T>
ALGraph<T>::~ALGraph()
{
	for (int i = 0; i < numVertex; ++i)
	{
		ArcNode * p = vexList[i].firstarc;
		ArcNode * q = p;
		while (p){
			q = p->next;
			delete p;
			p = q;
		}
	}
}

template <class T>
void ALGraph<T>::DFS(int v)
{
	cout << vexList[v].vertex;
	visitedVex[v] = true;
	ArcNode * p = vexList[v].firstarc;
	while(p){
		int j = p->adjvex;
		if (!visitedVex[j])
			DFS(j);
		p = p->next;
	}
}

template <class T>
void ALGraph<T>::BFS(int v)
{
	int queue[MAXV];
	cout << vexList[v].vertex;
	visitedVex[v] = true;
	int front = 0;
	int tail = 0;
	queue[++tail] = v;
	while(front != tail){
		v = queue[++front];
		ArcNode * p = vexList[v].firstarc;
		while (p){
			int j = p->adjvex;
			if (!visitedVex[j]){
				cout << vexList[j].vertex;
				visitedVex[j] = true;
				queue[++tail] = j;
			}
			p = p->next;
		}
	}
}

#endif