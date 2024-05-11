#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String
{
	char* data;
	int size;
	int getStrLength(const char* ch) const;
	int compare(const String &) const;
	int getNumberPart(const char* data, int start = 0) const;
	bool isNegativeNum(const char* data) const;
	int getDotIndex(const char* data) const;
	int numLength(long long int num) const;
	int getDivisor(int length) const;
	void copyString(const char* source, char* dest) const;
	int findIndex(int start, const String& subStr)  const;
	void swap(char& ch1, char& ch2);

public:
	String();
	String(const char c);
	String(const char *);
	String(const String &);
	String(String &&);
	String& operator = (const String&);
	String& operator = (String&&);
	~String();

	void input();
	void shrink();
	char& operator [](const int index);
	const char& operator [](const int index) const;
	bool operator !() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String& subStr, const int start = 0) const;
	void insert(const int index, const String & subStr);
	void remove(const int index, const int count = 1);
	int replace(const String& old, const String & newSubStr);


	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);


	int operator == (const String& s2) const;
	bool operator > (const String& s2) const;
	bool operator < (const String& s2) const;
	bool operator >= (const String& s2) const;
	bool operator <= (const String& s2) const;
	bool operator != (const String& s2) const;


	String left(const int count);
	String right(const int count);

	String operator + (const String& s2) const;
	void operator += (const String& s2);
	String& operator = (const long long int num);
	String& operator = (const double num);
	explicit operator long long int() const;
	explicit operator double() const;
	explicit operator bool() const;
	String operator () (const String& delim);

};
#endif // !STRING_H




