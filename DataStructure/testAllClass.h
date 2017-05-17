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
#include "MGraph.h"
#include "ALGraph.h"
#include "LinkHashTable.h"
#include "BST.h"
#include "Sort.h"



void testNaturalNumber();//��ϰ 1.4 ��Ȼ��
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
//practiec 3.3.3 ��ʮ������ n ת��Ϊ base ��������ʹ�ó�����ջ��
void convert(unsigned n, unsigned base);
void testConvertSystem();
//practice 3.3.4 ���Է� s �ı������� n ����Ʒ����Ϊ w[0~n-1];��ʹ�÷������Ʒ����֮�����õ��� s����Ʒ���н�
int NPBagPack(int s, int * w,int n );
void testNPBagPack();
//practice 4.3.1
void testUpTriMatrix();
//practiec BiTree Self Definetion
void testBiTree();
//practice 5.10
void testHuffmanTree();
//practice 6.3
void testMGraph();
void testALGraph();
//parctice 6.4
void testPrim();
//practice 7.5.1
void testLinkHashTable();
//practice 7.5.2
void testBST();
//practice 8 All Sort aglriothm
void testSort();
//practice 8.5.2
void testSeperateOddEven();
void SeperateOddEven(int a[], int n);
//practice 8.5.3
int QuickKTH(int a[], int n, int k);
void testQuickKTH();
//
void Qsort(int a[], int start, int end);
//practice 8.5.5
void LinkBubbleSort(Node<int> * front);
void LinkInsertSort(Node<int> * front);
void LinkSelectSort(Node<int> * front);
void testLinkSort();
//practice 8.5.6
void HeapAdjustNP(int a[], int n);
void testHeapAdjustNP();
//practice 8.5.7
void shuffle(char a[], int n);
void testshuffle();

//practice myself
void testMergeSortWithInsertSort();
#endif