#ifndef GENERIC_DICTIONARY_H
#define GENERIC_DICTIONARY_H
#include<iostream>
using namespace std;
#include"DictionaryPair.h"

template <typename T,typename R>
class GenericDictionary
{
	DictionaryPair <T, R>* data;
	int noOfItems;
	int capacity;
	int keyIndex( T k);
	void reSize();
public:
	GenericDictionary();
	~GenericDictionary();
	void addPair(T k,R v);
	R getValue(T K);
	void print();
	bool isFull();
	bool isEmpty();

};
#endif // !GENERIC_DICTIONARY_H
