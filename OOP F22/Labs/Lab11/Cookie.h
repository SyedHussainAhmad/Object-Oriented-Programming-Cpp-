#ifndef COOKIE_H
#define COOKIE_H
#include"DessertItem.h"

class Cookie : public DessertItem
{
	int number;
	double pricePerDozen;
public:
	Cookie(int, double,String);
	double getCost() const;
};
#endif // !COOKIE_H