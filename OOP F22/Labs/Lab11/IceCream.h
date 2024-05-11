#ifndef ICE_CREAM_H
#define ICE_CREAM_H
#include"DessertItem.h"

class IceCream : public DessertItem
{
	double cost;
public:
	IceCream(double,String);
	double getCost() const;
};
#endif // !ICE_CREAM_H