#include "DessertShoppe.h"

double DessertShoppe::_TAX_RATE = 0;

void DessertShoppe::setTaxRate(double tax)
{
	_TAX_RATE = tax;
}

double DessertShoppe::getTaxRate()
{
	return _TAX_RATE;
}

String DessertShoppe::centToDollars(int cents)
{
	String s = "";

	if (cents < 0)
	{
		s += "-";
		cents = cents * -1;
	}
	int dollars = cents / 100;
	cents = cents % 100;
	s += dollars;
	s += ".";

	if (cents < 10)
	{
		s += "0";
	}
	s += cents;
	return s;
}
