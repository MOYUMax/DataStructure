#include "stdafx.h"
#include "HuffmanTree.h"
#include <string.h>



void HuffmanTree::CreateHTree(int a[], int n)
{
	cout << "Initial HTree i weight lchild rchild parent:" << endl;
	HTree = new HNode[2 * n - 1];
	for (int i = 0; i < n; ++i){
		HTree[i].weight = a[i];
		HTree[i].lchild = HTree[i].rchild = HTree[i].parent = -1;
		cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << " " << HTree[i].parent << endl;
	}
	cout << "Create HuffmanTree: i weight lchild rchild parent:" << endl;
	int x, y;
	for (int i = n; i < 2 * n - 1; ++i){
		//select two HNode which parent=-1 and min weight from HTree 
		x = y = INT_MAX;
		int xj = 0, yj = 0;
		for (int j = 0; j < i; ++j){
			if (-1 == HTree[j].parent){
				if (HTree[j].weight < y){
					x = y;
					y = HTree[j].weight;
					xj = yj;
					yj = j;
				}
				else if (HTree[j].weight < x){
					x = HTree[j].weight;
					xj = j;
				}
			}
		}		
		HTree[xj].parent = HTree[yj].parent = i;
		HTree[i].weight = HTree[xj].weight + HTree[yj].weight;
		HTree[i].lchild = yj;
		HTree[i].rchild = xj;
		HTree[i].parent = -1;
		cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << " " << HTree[i].parent << endl;
	}
}

void Reverse(char * s)
{
	int len = strlen(s);
	int i = 0, j = len - 1;
	while (i < j){
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		++i;
		--j;
	}
}

void HuffmanTree::CreateCodeTable(char b[], int n)
{
	length = n;
	HCodeTable = new HCode[n];
	for (int i = 0; i < n; ++i){
		HCodeTable[i].data = b[i];
		int child = i;
		int parent = HTree[i].parent;
		int k = 0;
		while (parent != -1){
			if (child == HTree[parent].lchild)
				HCodeTable[i].code[k] = '0';
			else
				HCodeTable[i].code[k] = '1';
			k++;
			child = parent;
			parent = HTree[child].parent;
		}
		HCodeTable[i].code[k] = '\0';		
		Reverse(HCodeTable[i].code);
		cout << b[i] << " code :" << HCodeTable[i].code << endl;
	}
}

void HuffmanTree::Decode(char * s, char * d, int n)
{
	while (*s != '\0'){
		int parent = 2 * n - 2;
		while (HTree[parent].lchild != -1){
			if (*s == '0')
				parent = HTree[parent].lchild;
			else
				parent = HTree[parent].rchild;
			s++;
		}
		*d = HCodeTable[parent].data;
		d++;
	}
	*d = '\0';
}

void HuffmanTree::Encode(char *s, char *d, int n)
{
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < length; ++j){
			if (s[i] == HCodeTable[j].data){
				strcpy(d, HCodeTable[j].code);
				d += strlen(HCodeTable[j].code);
			}
		}
	}
}