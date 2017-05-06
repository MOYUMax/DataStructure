#ifndef _HuFFMANTREE_H
#define _HuFFMANTREE_H

#include <iostream>

using namespace std;

struct HNode
{
	int weight;
	int parent;
	int rchild;
	int lchild;
};

struct HCode
{
	char data;
	char code[100];
};

class HuffmanTree
{
private:
	HNode * HTree;
	HCode * HCodeTable;
public:
	int length;
	void CreateHTree(int a[], int n);
	void CreateCodeTable(char b[], int n);
	void Encode(char * s, char * d, int n);
	void Decode(char * s, char * d, int n);
	//~HuffmanTree();
};

#endif