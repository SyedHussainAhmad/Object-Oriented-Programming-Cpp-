#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
#include<stdarg.h>
using namespace std;

template <typename T>
class Array
{
	T size;
	T *data;
	void copyArray(Array* , T*);
public:
	Array(T , ...);
	//Array(T);
	Array(const Array &);
	~Array();
	T& operator[](T );
	const T &operator[](T ) const;
	T getSize() const;
	void reSize(T);
};

#endif // !ARRAY_H