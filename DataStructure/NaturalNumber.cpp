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
/* 获取自然数的所有因子，存入 vector<unsigned int> 向量中
 * 算法采用了 平方根优化，大大减少了循环次数
 */
int NaturalNumber::getFactors(vector<unsigned int> & factors)
{
	int result = 0;
	unsigned int m = unsigned(sqrt(double(val)));	//自然数开更号，目的是减少循环次数
	vector<unsigned int > bigfactors;
	for (unsigned int i = 1; i < m; ++i){
		if (0 == val%i){
			result += 2;		//一次找到两个因子，即 i 和 val/i
			factors.push_back(i);//将 i 插入 factors中
			bigfactors.push_back(val / i);//将 num/i 插入 bigfactors中
		}
	}
	if (m*m == val){//中间值 m 只算一个因子，即 m = val/m
		++result;
		factors.push_back(m);
	}
	vector<unsigned int>::iterator vecIt = bigfactors.end();
	if (bigfactors.size()){//将bigfactors 中的因子复制到 factors中
		do{
			--vecIt;
			factors.push_back(*vecIt);//复制
		} while (vecIt != bigfactors.begin());
	}
	return result;
}