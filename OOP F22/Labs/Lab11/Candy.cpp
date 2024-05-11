#include "Candy.h"

Candy::Candy(double w, double c ,String n) : DessertItem(n)
{
	weight = w;
	costPerPound = c;
}

double Candy::getCost() const
{
	return (weight*costPerPound);
}
