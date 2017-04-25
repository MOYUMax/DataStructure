#ifndef _NATURALNUMBER_H
#define _NATURALNUMBER_H

#include <iostream>
#include <vector>
using namespace std;

class NaturalNumber
{
private:
	unsigned int val;
public:
	NaturalNumber() :val(0){};
	NaturalNumber(int num) :val(num){};

	unsigned int operator=(unsigned int num) { return val = num; };
	bool operator<(const NaturalNumber & num) const { return val < num.getVal(); };
	bool operator>(const NaturalNumber & num) const { return val > num.getVal(); };
	bool operator==(int num) const { return val == num; };
	unsigned int & operator++(){ return ++val; };	//ǰ��++����
	unsigned int operator++(int){ return ++val; };	//����++���أ�Ϊ������ǰ��++���������������int
	unsigned int & operator--(){ return --val; };	//ǰ��--����
	unsigned int operator--(int){ return --val; };	//����--���أ��������int ��������ǰ��--����
	friend ostream & operator<<(ostream & os,const NaturalNumber & num);

	unsigned int getVal() const { return val; };
	unsigned int setVal(unsigned int num){ return val = num; };
	unsigned int getMaxDiv(NaturalNumber & num);
	unsigned int getMinMutiple(NaturalNumber & num);
	int getFactors(vector<unsigned int> & factors);
};


#endif