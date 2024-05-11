#include "IceCream.h"

IceCream::IceCream(double c, String n) : DessertItem(n)
{
	cost = c;
}

double IceCream::getCost() const
{
	return cost;
}
