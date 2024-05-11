#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
private:
	friend ostream& operator <<(ostream& r, String& s);
	char* data;
	int size;
	int findIndex(int, const String&)  const;
	int getStrLength(const char*) const;
	int numLength(long long int) const;
	int getDivisor(int) const;
	void copyString(const char*, char*) const;
	void swap(char&,char&);
	bool isNegativeNum(const char *) const;
	int getNumberPart(const char *, int = 0) const;
	int getDotIndex(const char* data) const;

public:
	String();
	String(const char );
	String(const char*);
	String(const String &);
	void operator=(const String &);
	String(String&& r);
	String& operator=(String&& rfs);
	~String();
	char& operator[](const int);
	const char& operator[](const int) const;
	void input();
	void shrink();
	bool isEmpty() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(String & , int = 0 ) const;
	void insert(int, String const &);
	void remove(int, int = 1);
	int replace(String&, String&);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	bool operator==(const String&) const;
	String left(const int);
	String right(const int);
	String operator+(const String &) const;
	void operator+=(const String &);
	void setNumber(const long long int);
	float toFloat() const;
	int toInteger() const;
	String tokenzie(String);
	void reverseWords();
	void changeToNewCharSet(String);
};

#endif // !STRING_H