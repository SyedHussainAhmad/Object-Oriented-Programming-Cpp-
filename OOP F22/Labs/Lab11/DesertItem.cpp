#include "DessertItem.h"

DessertItem::DessertItem(String n)
{
	name = n;
}

String DessertItem::getName() const
{
	return name;
}

double DessertItem::getTax() const
{
	return 0.0;
}
