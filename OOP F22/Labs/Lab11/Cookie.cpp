#include "Cookie.h"

Cookie::Cookie(int num, double price, String n): DessertItem(n)
{
	number = num;
	pricePerDozen = price;
}

double Cookie::getCost() const
{
	return (number/12 * pricePerDozen);
}
