#include "stdafx.h"
#include <iostream>

#include "testAllClass.h"


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
	return;
}