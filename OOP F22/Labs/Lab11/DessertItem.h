#ifndef DESSERT_ITEM_H
#define DESSERT_ITEM_H
#include"String.h"

class DessertItem
{
	String name;
public:
	DessertItem(String = "");
	String getName() const;
	virtual double getCost() const = 0;
	virtual double getTax() const;
};
#endif // !DsESERT_ITEM_H
