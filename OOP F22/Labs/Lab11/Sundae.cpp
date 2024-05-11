#include "Sundae.h"

Sundae::Sundae(double cst, double cToping, String n):IceCream(cst, n)
{
	costOfTopping = cToping;
}

double Sundae::getCost() const
{
	return IceCream::getCost() + costOfTopping;
}
