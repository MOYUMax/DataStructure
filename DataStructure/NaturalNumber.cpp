#include "stdafx.h"
#include "NaturalNumber.h"
#include <iostream>

unsigned int NaturalNumber::getMaxDiv(NaturalNumber & num)
{
	unsigned int a = val;
	unsigned int b = num.getVal();
	unsigned int left = a%b;
	while (left != 0){
		a = b;
		b = left;
		left = a%b;
	}
	return b;
}

unsigned int NaturalNumber::getMinMutiple(NaturalNumber & num)
{
	int left = getMaxDiv(num);
	return val*num.getVal() / left;
}

ostream & operator<<(ostream & os, const NaturalNumber & num)
{
	os << num.getVal();
	return os;
}
/* ��ȡ��Ȼ�����������ӣ����� vector<unsigned int> ������
 * �㷨������ ƽ�����Ż�����������ѭ������
 */
int NaturalNumber::getFactors(vector<unsigned int> & factors)
{
	int result = 0;
	unsigned int m = unsigned(sqrt(double(val)));	//��Ȼ�������ţ�Ŀ���Ǽ���ѭ������
	vector<unsigned int > bigfactors;
	for (unsigned int i = 1; i < m; ++i){
		if (0 == val%i){
			result += 2;		//һ���ҵ��������ӣ��� i �� val/i
			factors.push_back(i);//�� i ���� factors��
			bigfactors.push_back(val / i);//�� num/i ���� bigfactors��
		}
	}
	if (m*m == val){//�м�ֵ m ֻ��һ�����ӣ��� m = val/m
		++result;
		factors.push_back(m);
	}
	vector<unsigned int>::iterator vecIt = bigfactors.end();
	if (bigfactors.size()){//��bigfactors �е����Ӹ��Ƶ� factors��
		do{
			--vecIt;
			factors.push_back(*vecIt);//����
		} while (vecIt != bigfactors.begin());
	}
	return result;
}