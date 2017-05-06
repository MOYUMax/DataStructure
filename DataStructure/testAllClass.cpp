#include "stdafx.h"
#include <iostream>
#include <string>

#include "testAllClass.h"
using namespace std;

void testNaturalNumber()
{
	NaturalNumber a;
	cout << "Natural Number a = " << a << endl;
	NaturalNumber b(10);
	NaturalNumber num1 = 5;
	cout<<"b = "<<b<<",It's greatest common divsor with 5 is :"<<b.getMaxDiv(num1)<<endl;
	b++;
	++b;
	++++++++a;
	cout << "a = " << a << "\tb = " << b << endl;
	cout << "a b MaxDiv = " << a.getMaxDiv(b) << endl;
	cout << "a b MinMutiple = " << b.getMinMutiple(a) << endl;
	vector<unsigned int> fac;
	b = 23960000;
	int t = b.getFactors(fac);
	cout << b << " 共有因子 " << t << " 个\n";
	for (const auto & fac_elem : fac){
		cout << fac_elem << " ";
	}
	cout << "\nend of the testNatural Number!\n";
	return;
}

void testSeqList()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	SeqList<int> list(a, 7);
	list.PrintList();
	list.Insert(1, 0);
	list.PrintList();
	int x = list.Delete(8);
	cout << "delete :" << x << endl;
	list.PrintList();
	int p = list.Locate(4);
	cout << "the element 4's locates: " << p << endl;
	list.Swap();
	cout << "after Swap the list:";
	list.PrintList();

	return;
}

void testLinkList()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	LinkList<int> list(a, 7);
	list.PrintList();
	list.Insert(1, 0);
	list.PrintList();
	int x = list.Delete(8);
	cout << "delete :" << x << endl;
	list.PrintList();
	int p = list.Locate(4);
	cout << "the element 4's locates: " << p << endl;

	LinkList<int> A(a, 7);
	cout << "LinkList A :";
	A.PrintList();
	
	LinkList<int> C;
	Mearge(A, list, C);
	cout << "after Mearge A with list:";
	C.PrintList();
	C.Swap();
	cout << "after Swap LinkList C :";
	C.PrintList();

	/*LinkList<int> A(list);
	LinkList<int> B(list);
	LinkList<int> C(a, 7);
	cout << "Compare the A, B, C.\n";
	cout << "LinkList A :";
	A.PrintList();
	cout << "LinkList B :";
	B.PrintList();
	int ret = compare(A, B);
	cout<<"Compare A with B :"<< ret <<endl;
	cout << "LinkList C :";
	C.PrintList();
	ret = compare(A, C);
	cout << "Compare A with C :" << ret <<endl;*/

	return;
}
void testCLinkList()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	CLinkList<int> list(a, 7);
	list.PrintList();
	list.Insert(1, 0);
	list.PrintList();
	int x = list.Delete(8);
	cout << "delete :" << x << endl;
	list.PrintList();
	int p = list.Locate(4);
	cout << "the element 4 locate on : " << p << endl;
	Node<int> * ret = list.Get(5);
	cout << "The fifth element is : " << ret->data << endl;
	x = list.DeletePrior(ret);
	cout << "after delete the 5's prior element : "<< x <<endl;
	list.PrintList();
	
	char b[8] = { '1', 'a', '0', '{', '*', ' ', '9', 'w' };
	LinkList<char> A(b, 8);
	A.PrintList();

	CLinkList<char> C;
	CLinkList<char> N;
	CLinkList<char> O;
	Classify(A, C, N, O);

	cout << "after Classify\n";
	cout << "CLinkList C :";
	C.PrintList();
	cout << "CLinkList N :";
	N.PrintList();
	cout << "CLinkList O :";
	O.PrintList();
}

bool isNumber(char c)
{
	return (c >= '0'&&c <= '9') ? true : false;
}
bool isAlphabet(char c)
{
	return ((c >= 'A'&&c <='Z') || (c >= 'a'&&c <= 'z')) ? true : false;
}

void Classify(LinkList<char> & A, CLinkList<char> & C, CLinkList<char> & N, CLinkList<char> & O)
{
	Node<char> * p = A.GetFront()->next;
	A.GetFront()->next = nullptr;
	/*Node<char> * c = C.GetRear()->next;
	Node<char> * n = N.GetRear()->next;
	Node<char> * o = O.GetRear()->next;*/
	Node<char> * q;
	while (p != nullptr){
		q = p->next;
		if (isNumber(p->data)){
			N.Insert(1, p);
			/*p->next = n->next;
			n->next = p;
			p = q;*/
		}
		else if (isAlphabet(p->data)){
			C.Insert(1, p);
			/*p->next = c->next;
			c->next = p;
			p = q;*/
		}
		else{
			O.Insert(1, p);
			/*p->next = o->next;
			o->next = p;
			p = q;*/
		}
		p = q;
	}
}

//void Josephus(unsigned n, unsigned k)
//{
//	CLinkList<int> Jos;
//	for (int i = 1; i <= (int)n; ++i){
//		Jos.Insert(i, i);
//	}
//	Jos.PrintList();
//	int length = Jos.GetLength();
//	cout << "The Sequence of Jos :"<< endl;
//	Node<int> * p = Jos.GetRear()->next;
//	Node<int> * q = p->next;
//	//Node<int> * temp;
//	while (length != 0){
//		for (int i = 1; i < (int)k; ++i){
//			p = q;
//			q = q->next;
//		}
//		q = q->next;
//		int ret = Jos.DeleteNext(p);
//		cout << ret << " ";
//		--length;
//	}
//	cout << endl;
//}

node * creatList(int n)
{
	node * first, *p;
	p = first = new node(1);
	for (int i = 2; i <= n; ++i){
		node * q = new node(i);
		p->next = q;
		p = q;
	}
	p->next = first;
	return first;
}
//约瑟夫环，使用自定义的无头结点循环链表
void Josephus(unsigned n, unsigned k)
{
	node * jos = creatList(n);
	node * p = jos;
	node * q = nullptr;
	while (p != q){//删除到只剩最后一个节点时停止
		int j = 0;
		while (p && ++j < int(k) ){
			q = p;
			p = p->next;
		}
		cout << p->data << " ";//打印每个节点
		q->next = p->next;
		delete p;
		p = q->next;
	}
	cout << p->data << endl;//打印最后一个节点
}

bool isLeftParentheses(char c)
{
	return c == '(' ? true : false;
}
bool isRigthParentheses(char c)
{
	return c == ')' ? true : false;
}
//左右括号匹配
bool ParenthesesMatch(const char * s)
{
	SeqStack<char> expre_stack;
	char tempc;
	int i = 0;
	while (s[i]){
		if (isLeftParentheses(s[i])){
			expre_stack.Push(s[i]);
			//cout << s[i] ;
		}
		else if (isRigthParentheses(s[i])){
			try{
				tempc = expre_stack.Pop();
				//cout << s[i];
			}
			catch (const char * &){
				//cerr << "EXPECTION: " << e << endl;
				return false;
			}
		}
		++i;
	}
	if (!expre_stack.Empty())
		return false;
	return true;
}

void testParenthMatch()
{
	string s = "a+((b*c)/()(d+f)-(sdf)*d))-5";
	cout << s << " is " << ParenthesesMatch(s.c_str()) << endl;
	while (1){
		cout << "Please input expression(Ctrl+C break):" << endl;
		cin >> s;
		bool ret = ParenthesesMatch(s.c_str());
		if (ret)
			cout << "Expression OK." << endl;
		else
			cout << "Expression Error." << endl;
	}
}

void testSeqStack()
{
	SeqStack<int> a;
	for (int i = 1; i < 11; ++i)
		a.Push(i);
	int j = 0;
	while (!a.Empty()){
		j = a.Pop();
		cout << j << " ";
	}
	cout << "\nend\n";
	try{
		a.Pop();
	}
	catch(const char * & e){
		cerr << "Pop eror " << e << endl;
	}
}

void testCLinkQueue()
{
	CLinkQueue<int>	cqi;
	for (int i = 1; i < 10; ++i)
		cqi.EnQueue(i);
	int j = cqi.GetLength();
	cout << "The length of the CLinkQueue : " << j << endl;
	while (!cqi.isEmpty()){
		j = cqi.DeQueue();
		cout << j << " ";
	}
	cout << endl;
	cqi.SetNull();
	j = cqi.GetLength();
	cout << "After SetNull to CLinkQueue : Length =" << j << endl;
	cqi.EnQueue(132564);
	j = cqi.DeQueue();
	cout << "Last DeQueue item : " << j;

	cout << "\nend\n";
}

void convert(unsigned n, unsigned base)
{
	SeqStack<unsigned> seq_stack;
	unsigned i = n,j = 0;
	while (i){
		j = i%base;
		seq_stack.Push(j);
		i /= base;
	}
	while (!seq_stack.Empty()){
		j = seq_stack.Pop();
		if (j > 9){
			char c = j + 55;
			cout << c;
		}
		else
			cout << j;
	}
	cout << endl;
}

void testConvertSystem()
{
	cout << "Please input the decimal and base to convert(sperate by space):";
	int n, k;

	while (1){
		cin >> n >> k;
		cout << "Trans decimal number " << n << " to " << k << " number : ";
		convert(n, k);
		cout << "Input again or Ctrl+C to break:";
	}
}

int NPBagPack(int s,int * w, int n)
{
	if (s == 0)
		return 1;
	if (s < 0 || (s > 0 && n < 0))
		return 0;
	if (NPBagPack(s - w[n], w, n - 1)){
		cout << w[n]<<" ";
		return 1;
	}
	return NPBagPack(s,w, n - 1);
}
void testNPBagPack()
{
	int S = 8;
	int N = 6;
	int W[7] = { 0, 1, 2, 3, 4, 5, 6 };
	if (NPBagPack(S, W, N)){
		cout << "\nOK\n";
	}
}

void testUpTriMatrix()
{
	int n = 5;
	int ** p = new int * [n];
	p[0] = new int[n*n];
	for (int i = 1; i < n; ++i)
		p[i] = p[i - 1] + n;
	int a[5][5] = {
		{1,2,0,4,3},
		{0,4,7,8,1},
		{0,0,6,5,4},
		{0,0,0,2,9},
		{0,0,0,0,3}
	};
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			p[i][j] = a[i][j];
	UpTriMatrix<int> upmatrix(p, 5, ROW);
	int ** q = upmatrix.Convert();
	for (int i = 0; i < upmatrix.getOrder(); ++i){
		for (int j = 0; j < upmatrix.getOrder(); ++j)
			cout << q[i][j] << " ";
		cout << endl;
	}
}

void testBiTree()
{
	
	string a = "ABD##EF###CG#H###";
	char str[18] = "ABCDEFG";
	BiTree<char> * bTree = new BiTree<char>(str,7);
	bTree->Print(Pre);
	bTree->Print(In);
	bTree->Print(Post);
	bTree->Print(Level);
	BiTree<char> * cTree = new BiTree<char>(bTree);
	int depth;
	depth = cTree->Depth(cTree->root);
	cout << "CopyTree c has depth : " << depth << endl;
	int node = cTree->CountNode(cTree->root);
	cout << "C Tree BiNode number =  " << node << endl;
	int leaf = cTree->Leaf(cTree->root);
	cout << "C Tree Leaf number = " << leaf << endl;
}

void testHuffmanTree()
{
	int a[8] = { 7, 19, 2, 6, 32, 3, 21, 10 };
	char b[9] = "ABCDEFGH";

	HuffmanTree huff;
	cout << "CreateHTree:\n";
	huff.CreateHTree(a, 8);
	cout << "CreateCodeTable:\n";
	huff.CreateCodeTable(b, 8);

	char code[100];
	huff.Encode(b, code, 8);
	cout << "Encode ABCDEFGH: " << code << endl;;

	char str[10];
	huff.Decode(code, str, 8);
	cout << "Decode : " << str << endl;
}