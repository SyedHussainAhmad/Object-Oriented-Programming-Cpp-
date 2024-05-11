#ifndef DESSERT_SHOP_H
#define DESSERT_SHOP_H
#include"String.h"

class DessertShoppe
{
	static double _TAX_RATE;
	static const String _STORE_Name;
	static const int MAX_ITEM_NAME_WIDTH;
public:
	static void setTaxRate(double);
	static double getTaxRate();
	static String centToDollars(int);
};

#endif // !DESSERT_SHOP_H