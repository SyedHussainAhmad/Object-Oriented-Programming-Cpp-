//#include "Array.h"
//#ifndef MY_SET
//#define MY_SET
//
//class Set
//{
//	Array data;
//	int noOfElement;
//	int findIndex(int) const;
//	int getCommonElements(const Set& s2) const;
//	bool isImproperSubSet(Set s2) const;
//	bool isCallingSubSet(Set s2) const;
//	bool isS2SubSet(Set s2) const;
//
//public:
//	Set(int = 0);
//	void insert(int element);
//	void remove(int element);
//	void print() const;
//	int getCardinality() const;
//	bool isMember(int) const;
//	int isSubSet(Set s2) const;
//	void reSize(int newCapacity);
//	Set calcUnion(const Set& s2) const;
//	Set calcIntersection(const Set& s2) const;
//	Set calcDifference(const Set& s2) const;
//	Set calcSymmetricDifference(const Set& s2) const;
//	void displayPowerSet() const;
//};
//
//#endif // !MY_SET
//
//#include <iostream>
//#include "Set.h"
//using namespace std;
//Set::Set(int cap) :data(cap)
//{
//	noOfElement = 0;
//}
//bool Set::isMember(int val) const
//{
//	for (int i = 0; i < noOfElement; i++)
//	{
//		if (data.at(i) == val)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//void Set::insert(int element)
//{
//	if (isMember(element))
//		return;
//	if (noOfElement >= data.getCapacity())
//	{
//		if (data.getCapacity() == 0)
//			reSize(2);
//		else
//			reSize(data.getCapacity() * 2);
//	}
//	data.at(noOfElement) = element;
//	noOfElement = noOfElement + 1;
//}
//int Set::getCardinality() const
//{
//	return noOfElement;
//}
//void Set::reSize(int newCapacity)
//{
//	if (newCapacity == data.getCapacity())
//		return;
//	if (newCapacity < data.getCapacity() && newCapacity < noOfElement)
//		noOfElement = newCapacity;
//	data.reSize(newCapacity);
//}
//void Set::print() const
//{
//	if (noOfElement == 0)
//	{
//		cout << "{ }";
//		return;
//	}
//
//	cout << "{ ";
//	for (int i = 0; i < getCardinality(); i++)
//	{
//		cout << data.at(i);
//		if (i < getCardinality() - 1)
//			cout << ", ";
//	}
//	cout << " }" << endl;
//}
//int Set::findIndex(int val) const
//{
//	for (int i = 0; i < noOfElement; i++)
//	{
//		if (data.at(i) == val)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//int Set::getCommonElements(const Set& s2) const
//{
//	int cnt = 0;
//	for (int i = 0; i < getCardinality(); i++)
//	{
//		for (int j = 0; j < s2.getCardinality(); j++)
//		{
//			if (data.at(i) == s2.data.at(j))
//			{
//				cnt = cnt + 1;
//			}
//		}
//	}
//	return cnt;
//}
//void Set::remove(int element)
//{
//	if (!isMember(element))
//		return;
//	int index = findIndex(element);
//	for (int i = index; i < noOfElement - 1; i++)
//	{
//		data.at(i) = data.at(i + 1);
//	}
//	noOfElement = noOfElement - 1;
//}
//bool Set::isS2SubSet(Set s2) const
//{
//	if (s2.data.getCapacity() == 0)
//		return true;
//	int	elements = s2.getCardinality();
//	int i = 0, cnt = 0;
//	while (i < elements)
//	{
//		if (isMember(s2.data.at(i)))
//			cnt = cnt + 1;
//		i = i + 1;
//	}
//	if (cnt == elements)
//		return true;
//	return false;
//}
//bool Set::isCallingSubSet(Set s2) const
//{
//	if (data.getCapacity() == 0)
//		return true;
//	int elements = getCardinality();
//	int i = 0, cnt = 0;
//	while (i < elements)
//	{
//		if (s2.isMember(data.at(i)))
//			cnt = cnt + 1;
//		i = i + 1;
//	}
//	if (cnt == elements)
//		return true;
//}
//bool Set::isImproperSubSet(Set s2) const
//{
//	if (data.getCapacity() == 0 && s2.data.getCapacity() == 0)
//		return true;
//	if (getCardinality() != s2.getCardinality())
//		return false;
//	else
//	{
//
//		bool status = isCallingSubSet(s2);
//		return status;
//	}
//}
//int Set::isSubSet(Set s2) const
//{
//	if (isImproperSubSet(s2))
//		return 2;
//	if (isCallingSubSet(s2))
//		return 1;
//	if (isS2SubSet(s2))
//		return -1;
//	else
//		return 0;
//}
//Set Set::calcUnion(const Set& s2) const
//{
//	int cap = getCardinality() + s2.getCardinality() - getCommonElements(s2);
//	Set s{ cap };
//	int i;
//	for (i = 0; i < getCardinality(); i++)
//	{
//		s.data.at(i) = data.at(i);
//		s.noOfElement = s.noOfElement + 1;
//	}
//	for (int j = 0; j < s2.getCardinality(); j++)
//	{
//		if (!isMember(s2.data.at(j)))
//		{
//			s.data.at(i) = s2.data.at(j);
//			s.noOfElement = s.noOfElement + 1;
//			i = i + 1;
//		}
//	}
//	return s;
//}
//Set Set::calcIntersection(const Set& s2) const
//{
//	int cap = getCommonElements(s2);
//	Set s{ cap };
//	int k = 0;
//	for (int i = 0; i < getCardinality(); i++)
//	{
//		for (int j = 0; j < s2.getCardinality(); j++)
//		{
//			if (data.at(i) == s2.data.at(j))
//			{
//				s.data.at(k) = data.at(i);
//				s.noOfElement = s.noOfElement + 1;
//				k = k + 1;
//			}
//		}
//	}
//	return s;
//}
//Set Set::calcDifference(const Set& s2) const
//{
//	int cap = getCardinality() - getCommonElements(s2);
//	Set s{ cap };
//	int k = 0;
//	for (int i = 0; i < getCardinality(); i++)
//	{
//		if (!s2.isMember(data.at(i)))
//		{
//			s.data.at(k) = data.at(i);
//			k = k + 1;
//			s.noOfElement = s.noOfElement + 1;
//		}
//	}
//	return s;
//}
//Set Set::calcSymmetricDifference(const Set& s2) const
//{
//	Set Union = calcUnion(s2);
//	Set interSection = calcIntersection(s2);
//	Set symmDiff = Union.calcDifference(interSection);
//	return symmDiff;
//}
//void Set::displayPowerSet() const
//{
//
//}
//
//#ifndef MY_ARRAY
//#define MY_ARRAY
//
//class Array
//{
//	int* data;
//	int capacity;
//	void initializeArray();
//public:
//	Array();
//	//Array(int,...);
//	Array(int cap);
//	Array(const Array&);
//	~Array();
//	void reSize(int);
//	int& getSet(int);
//	int getCapacity() const;
//	int& at(int);
//	const int& at(int) const;
//	void display() const;
//};
//
//
//
//#endif // !MY_ARRAY
//
//#include "Array.h"
//#include <iostream>
//#include <stdarg.h>
//using namespace std;
//
//
//void Array::initializeArray()
//{
//	for (int i = 0; i < capacity; i++)
//	{
//		data[i] = 0;
//	}
//}
//Array::Array()
//{
//	data = nullptr;
//	capacity = 0;
//}
//Array::Array(int cap)
//{
//	capacity = cap;
//	if (cap <= 0)
//	{
//		capacity = 0;
//	}
//	if (capacity == 0)
//	{
//		data = nullptr;
//	}
//	else
//	{
//		data = new int[capacity];
//		initializeArray();
//	}
//}
//Array::Array(const Array& rfs) :Array()
//{
//	if (!rfs.data)
//		return;
//	capacity = rfs.capacity;
//	data = new int[capacity];
//	for (int i = 0; i < capacity; i++)
//	{
//		data[i] = rfs.data[i];
//	}
//}
//Array::~Array()
//{
//	if (!data)
//		return;
//	delete[] data;
//	data = nullptr;
//}
//int& Array::getSet(int index)
//{
//	if (index >= 0 && index < capacity)
//	{
//		return data[index];
//	}
//	exit(0);
//}
//int Array::getCapacity() const
//{
//	return capacity;
//}
//void Array::reSize(int newCapacity)
//{
//	if (newCapacity <= 0)
//	{
//		this->~Array();
//		capacity = 0;
//		return;
//	}
//	int* temp = new int[newCapacity];
//	int i = 0;
//	while (i < capacity && i < newCapacity)
//	{
//		temp[i] = data[i];
//		i = i + 1;
//	}
//	capacity = newCapacity;
//	this->~Array();
//	data = temp;
//}
//void Array::display() const
//{
//	if (!data)
//		return;
//	for (int i = 0; i < capacity; i++)
//	{
//		cout << data[i] << " ";
//	}
//}
////Array::Array(int cnt, ...) :Array()
////{
////	va_list list;
////	va_start(list, cnt);
////	capacity = cnt;
////	data = new int[capacity];// Allocate memory for the data array
////	for (int i = 0; i < cnt; i++)
////	{
////		int val = va_arg(list, int);
////		data[i] = val;
////	}
////	va_end(list);
////}
//int& Array::at(int index)
//{
//	if (index >= 0 && index < capacity)
//	{
//		return data[index];
//	}
//}
//const int& Array::at(int index) const
//{
//	if (index >= 0 && index < capacity)
//	{
//		return data[index];
//	}
//}