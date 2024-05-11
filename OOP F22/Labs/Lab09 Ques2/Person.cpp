#include"Person.h"

Person::Person()
{
	ZIP = 0;
}

Person::Person(String n, String a, String c, String s, int z) : name(n), address(a), city(c), state(s)
{
	ZIP = (z > 0 ? z : 0);
}

String Person::getName()
{
	return name;
}

String Person::getAddress()
{
	return address;
}

String Person::getCity()
{
	return city;
}

String Person::getState()
{
	return state;
}

int Person::getZIP()
{
	return ZIP;
}

void Person::setName(String n)
{
	name = n;
}

void Person::setAddress(String a)
{
	address = a;
}

void Person::setCity(String c)
{
	city = c;
}

void Person::setState(String s)
{
	state = s;
}

void Person::setZIP(int z)
{
	ZIP = z;
}