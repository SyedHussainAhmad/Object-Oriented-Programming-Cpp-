#ifndef CANDY_H
#define CANDY_H
#include"DessertItem.h"

class Candy: public DessertItem
{
	double weight;
	double costPerPound;
public:
	Candy(double, double ,String);
	double getCost() const;
};
#endif // !CANDY_H