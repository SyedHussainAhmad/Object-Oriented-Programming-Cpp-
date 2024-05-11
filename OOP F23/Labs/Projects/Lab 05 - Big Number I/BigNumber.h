#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include<iostream>
using namespace std;

enum Comparison
{
	EQUAL, SMALL, LARGE
};

class BigNumber
{
	char* number;
	int numberLength;
	int getStrLength(const char*);
	void copyStr(const char*, char*);
public:
	BigNumber(const char*);
	BigNumber(const BigNumber&);
	~BigNumber();
	void setNumber(const char* );
	BigNumber add(BigNumber&)const;
	BigNumber subtract(BigNumber&)const;
	BigNumber multiply(BigNumber&)const;
	void print() const;
	Comparison compare(BigNumber&)const;
};
#endif // !BIG_NUMBER_H
