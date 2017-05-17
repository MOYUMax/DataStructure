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
	list.Reverse();
	cout << "after reverse the list:";
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
	C.Reverse();
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
//十进制数 n 转换任意 base进制数，用除余入栈的方法。
void convert(unsigned n, unsigned base)
{
	SeqStack<unsigned> seq_stack;
	unsigned i = n,j = 0;
	while (i){
		j = i % base;
		seq_stack.Push(j);
		i /= base;
	}
	while (!seq_stack.Empty()){
		j = seq_stack.Pop();
		if (j > 9){
			char c = j + 55;	//对大于9的数采用字母来转换
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

const int MAXV = 10;
bool visitedVex[MAXV] = { false };

void testMGraph()
{
	char a[9] = "ABCDEFGH";
	MGraph<char> mGraph(a, 8, 14);
	mGraph.DFS(0);
	cout << endl;
	for (int i = 0; i < MAXV;++i)
		visitedVex[i] = false;
	mGraph.BFS(0);
}

void testALGraph()
{
	/*char a[9] = "ABCDEFGH";
	ALGraph<char> alGraph(a, 8, 14);*/

	ALGraph<char> alGraph;
	alGraph.DFS(0);
	cout << endl;
	for (int i = 0; i < MAXV; ++i)
		visitedVex[i] = false;
	alGraph.BFS(0);

}

void testPrim()
{
	MGraph<char> mGraph;
//	mGraph.Prim();
//	mGraph.Kruskal();
//	mGraph.Dijkstra(0);
	mGraph.Floyd();
}

void testLinkHashTable()
{
	int r[12] = { 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	LinkHashTable<int> LHTI(13);
	LHTI.CreateHashTable(r, 12);
	cout << "ASL for success:" << LHTI.ASL(true, 12) << endl;
	cout << "ASL for unsuccess:" << LHTI.ASL(false, 12) << endl;
	cout << "Find 11 :" << LHTI.Find(11) << endl;
	cout << "Delete 27:" << LHTI.Delete(27) << endl;
}

void testBST()
{
	int a[7] = { 63, 90, 70, 55, 67, 42, 98 };
	BST<int> bst(a, 7);
	cout << "Search 90:" << bst.Search(bst.rootBST, 90)->data << endl;
	cout << "Find 67 Level:" << bst.FindKeyLevel(bst.rootBST, 67, 1) << endl;
	cout << "Delete 70 Level:" << bst.DeleteBST(bst.rootBST, 70) << endl;
	cout << "Find 70 Level:" << bst.FindKeyLevel(bst.rootBST, 70) << endl;
	cout << "BST IsSorted:" << bst.IsSorted(bst.rootBST) << endl;
}

void testSort()
{
	int a[8] = { 0,63, 90, 70, 55, 67, 42, 98 };
	Sort<int> sortInt;
	sortInt.BubbleSort(a, 7);
	sortInt.Print(a, 7);

	int aa[8] = { 0, 63, 90, 70, 55, 67, 42, 98 };
	sortInt.bidBubbleSort(aa, 7);
	sortInt.Print(aa, 7);
	/*int b[13] = { 0,19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	sortInt.SelectSort(b, 6);
	sortInt.Print(b, 12);
	
	sortInt.InsertSort(b, 12);
	sortInt.Print(b, 12);

	int c[20] = { 0,63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	sortInt.ShellSort(c, 19);
	sortInt.Print(c, 19);

	int d[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	sortInt.MergeSort(d, 19);
	sortInt.Print(d, 19);
*/
	int e[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	sortInt.QuickSort(e, 19);
	sortInt.Print(e, 19);
	
	int ee[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	sortInt.bidBubbleSort(ee, 19);
	sortInt.Print(ee, 19);
}
//practice 8.5.2
void SeperateOddEven(int a[], int n)
{
	int low = 0;
	int high = n;
	while (low < high){
		while (low<high && a[low] % 2 == 1)
			++low;
		while (low < high && a[high] % 2 == 0)
			--high;
		int temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		++low;
		--high;
	}
}

void testSeperateOddEven()
{
	int ee[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	SeperateOddEven(ee, 20);
	for (int i = 0; i < sizeof(ee) / sizeof(int); ++i){
		cout << ee[i] << " ";
	}
	cout << endl;
}
//练习8.5.3，根据快排思想求第 K 小数的 qsort函数变形
int qsort(int a[], int start, int end, int k){
	Sort<int> sort;
	int pos = sort.Partition(a, start,end);
	if (k == pos)return pos;
	else if (k > pos)return qsort(a, pos + 1, end, k);
	else return qsort(a, start, pos - 1, k);
}
//练习8.5.3，用快排思想求第 K 小的数
int QuickKTH(int a[], int n, int k)
{
	if (k > n)
		return 0;
	return qsort(a, 1, n, k);
}
void testQuickKTH()
{
	int ee[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	cout << "The 8th of ee " << ee[QuickKTH(ee, 19, 8)] << endl;
	Sort<int> sortInt;
	Qsort(ee, 0, 19);			//练习8.5.4快速排序的非递归实现
	//sortInt.QuickSort(ee, 19);
	sortInt.Print(ee, 19);
	
}

void Qsort(int a[], int start, int end)
{
	Sort<int> sort;
	int pivot = start;
	int stack[MAXSIZE];
	int top = -1;
	if (start < end){
		stack[++top] = start;
		stack[++top] = end;
	}
	while (top != -1){
		end = stack[top--];
		start = stack[top--];
		int pos = sort.Partition(a, start, end);
		if (start < pos - 1){
			stack[++top] = start;
			stack[++top] = pos - 1;
		}
		if (end > pos + 1){
			stack[++top] = pos + 1;
			stack[++top] = end;
		}
	}
}
//练习8.5.4，链表的排序实现：简单选择、直接插入、冒泡
void LinkSelectSort(Node<int> * front)
{
	Node<int> * p, *q, *s;
	p = front->next;
	while (p != nullptr){
		s = p;
		q = p->next;
		while (q != nullptr){
			if (q->data < s->data)s = q;
			q = q->next;
		}
		if (p != s){
			int temp = p->data;
			p->data = s->data;
			s->data = temp;
		}
		p = p->next;
	}
}
void LinkInsertSort(Node<int> * front)
{
	Node<int> *p, *q, *s;
	p = front;
	q = p->next;
	
	while (p->next != nullptr && q->next != nullptr){
		p = front;
		while (p != q && p->next->data < q->next->data){
			p = p->next;
		}
		if (p == q){
			q = q->next;
		}
		else
		{
			s = q->next;
			q->next = s->next;
			s->next = p->next;
			p->next = s;
		}
	}
}
void LinkBubbleSort(Node<int> * front)
{
	Node<int> *p, *r;
	p = front->next;
	r = nullptr;
	while (p != nullptr && r != front->next){
		p = front->next;
		while (p->next != r){
			if (p->data > p->next->data){
				int temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		r = p;		
	}
}
void testLinkSort()
{
	int a[8] = { 0, 63, 90, 70, 55, 67, 42, 98 };
	LinkList<int> * list = new LinkList<int>(a, 8);
	cout << "LinkList before sort:" << endl;
	list->PrintList();
	cout << "After Sort:" << endl;
//	LinkBubbleSort(list->GetFront());
//	LinkInsertSort(list->GetFront());
	LinkSelectSort(list->GetFront());

	list->PrintList();
}

void HeapAdjustNP(int a[], int n)
{
	int start = 1;
	int end = n + 1;
	if (a[end] > a[end / 2]){
		for (int i = end / 2; i >= start; i /= 2){
			int j = 2 * i;
			if (a[j] < a[j + 1])++j;
			if (a[i] < a[j]){
				a[0] = a[j];
				a[j] = a[i];
				a[i] = a[0];
			}
		}
	}
}
void testHeapAdjustNP()
{
	int a[8] = { 0, 63, 90, 70, 55, 67, 42, 98 };
	Sort<int> sortInt;
	/*sortInt.HeapSort(a, 7);
	sortInt.Print(a, 7);*/
	for (int i = 6 / 2; i >= 1; --i){
		sortInt.HeapAdjust(a, i, 6);
	}
	cout << "The 6 BigHeap:\n";
	sortInt.Print(a, 7);
	cout << "The n+1 BigHeap:\n";
	HeapAdjustNP(a, 6);
	sortInt.Print(a, 7);
}

void shuffle(char a[], int n)
{
	int start = 0;
	int end = n - 1;
	int current = 0;
	char temp;
	while (current <= end){
		if (a[current] == 'R'){
			temp = a[start];
			a[start] = a[current];
			a[current] = temp;
			++start;
			++current;
		}
		else if (a[current] == 'B'){
			temp = a[end];
			a[end] = a[current];
			a[current] = temp;
			--end;
		}else
			++current;
	}
}
void testshuffle()
{
	char a[11] = "RBWBBWWBBR";
	cout << "Before shuffle:" << a << endl;
	shuffle(a, 10);
	cout << "After shuffle:" << a << endl;
}
void testMergeSortWithInsertSort()
{
	int aa[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	int ee[20] = { 0, 63, 90, 70, 55, 67, 42, 98, 19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79 };
	Sort<int> mysort;
	mysort.MergeSort(aa, 19);
	mysort.Print(aa, 19);

	mysort.MergeSortBest(ee, 1, 20);
	mysort.Print(ee, 19);
}