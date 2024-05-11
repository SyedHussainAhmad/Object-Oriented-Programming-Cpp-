#ifndef CHECKOUT_H
#define CHECKOUT_H
#include"DessertItem.h"
#include"DessertShoppe.h"
#include"Array.h"

class Checkout
{
	DessertItem** list;
	Array countPerItem;
	int itemsCount = 0;
	int listCapacity;
public:
	Checkout();
	void clear();
	void enterItem(const DessertItem & item, int cnt = 1);
	String toString();
	double totalCost();
	double totalTax();
	void reSize(int );
};

#endif // !CHECKOUT_H