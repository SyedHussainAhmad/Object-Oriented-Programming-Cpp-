#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include<iostream>
using namespace std;

class BigNumber
{
    int getStrLength(const char* str);
    void copyStr(const char* source, char* destination);
    int compare(const BigNumber& ref)const;
    char* number;
    int numberLength;
public:
    BigNumber(const char*);
    BigNumber(const BigNumber&);
    ~BigNumber();
    void setNumber(const char* num);
    void print() const;
    BigNumber operator = (const BigNumber&);
    BigNumber operator + (const BigNumber&) const;
    BigNumber operator - (const BigNumber& other) const;
    BigNumber operator * (const BigNumber& other) const;
    bool operator == (const BigNumber& other) const;
    bool operator > (const BigNumber& other) const;
    bool operator < (const BigNumber& other) const;
    bool operator >= (const BigNumber& other) const;
    bool operator <= (const BigNumber& other) const;
    bool operator != (const BigNumber& other) const;
};

#endif // !BIG_NUMBER_H
