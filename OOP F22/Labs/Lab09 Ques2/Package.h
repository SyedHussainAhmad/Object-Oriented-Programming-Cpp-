#ifndef PACKAGE_H
#define PACKAGE_H
#include"Person.h"

class Package
{
	Person p;
	double weight;
	double costPerOunce;
public:
	Package();
	Package(Person, double, double);
	double calculateCost();
	void setWeight(double);
	void setCostPerOunce(double);
};

#endif // !PACKAGE_H
