#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include<iostream>
using namespace std;

enum Comparison
{
	EQUAL,SMALL,LARGE
};

class BigNumber
{
	char* number;
	int numberLength;
	int getStrLength(const char*);
	void copyStr(const char* , char* );
public:
	BigNumber(const char *);
	BigNumber(const BigNumber &);
	~BigNumber();
	void setNumber(const char * num);
	BigNumber add(BigNumber& )const;
	BigNumber subtract(BigNumber & other)const;
	BigNumber multiply(BigNumber & other)const;
	void print();
	Comparison compare(BigNumber);
};
#endif // !BIG_NUMBER_H
