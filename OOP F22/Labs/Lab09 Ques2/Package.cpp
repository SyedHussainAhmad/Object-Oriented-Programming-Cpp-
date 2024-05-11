#include"Package.h"
Package::Package()
{
	weight = 0;
	costPerOunce = 0;
}

Package::Package(Person pr, double w, double c) : p(pr)
{
	weight = (w > 0 ? w : 0);
	costPerOunce = (c > 0 ? c : 0);
}

double Package::calculateCost()
{
	return weight * costPerOunce;
}

void Package::setWeight(double w)
{
	weight = (w > 0 ? w : 0);
}

void Package::setCostPerOunce(double c)
{
	costPerOunce = (c > 0 ? c : 0);
}
