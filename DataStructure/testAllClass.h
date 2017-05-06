#ifndef _TESTALLCLASS_H
#define _TESTALLCLASS_H
#include "NaturalNumber.h"
#include "SeqList.h"
#include "LinkList.h"
#include "CLinkList.h"
#include "SeqStack.h"
#include "CLinkQueue.h"
#include "UpTriMatrix.h"
#include "BiTree.h"
#include "HuffmanTree.h"

void testNaturalNumber();//Á·Ï° 1.4 ×ÔÈ»Êý
void testSeqList();//practice 2.5.1 Sequence List
void testLinkList();//practice 2.5.1 Link List
void testCLinkList();//practice 2.5.5 Circular Link List
//practice 2.5.6
void Classify(LinkList<char> & A, CLinkList<char> & B, CLinkList<char> & C, CLinkList<char> & D);
//parctice 2.5.7
class node{ //
public:
	int data;
	node * next;
	node(int i) : data(i), next(0){}
};
node * creatList(int n);
void Josephus(unsigned n, unsigned k);

//practice 3.3.1 SeqStack for check expression's parentheses match
bool ParenthesesMatch(const char * s);
void testParenthMatch();
void testSeqStack();
//parctice 3.3.2
void testCLinkQueue();
//practiec 3.3.3
void convert(unsigned n, unsigned base);
void testConvertSystem();
//practice 3.3.4
int NPBagPack(int s, int * w,int n );
void testNPBagPack();
//practice 4.3.1
void testUpTriMatrix();
//practiec BiTree Self Definetion
void testBiTree();
//practice 5.10
void testHuffmanTree();
#endif