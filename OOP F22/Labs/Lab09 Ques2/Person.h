#ifndef PERSON_H
#define PERSON_H
#include"String.h"

class Person
{
	String name;
	String address;
	String city;
	String state;
	int ZIP;
public:
	Person();
	Person(String, String, String, String, int);
	String getName();
	String getAddress();
	String getCity();
	String getState();
	int getZIP();
	void setName(String);
	void setAddress(String);
	void setCity(String);
	void setState(String);
	void setZIP(int);
};


#endif // !PERSON_H