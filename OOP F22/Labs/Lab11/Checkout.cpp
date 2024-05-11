#include "Checkout.h"

Checkout::Checkout() : countPerItem(0,0)
{
	list = nullptr;
	listCapacity = 0;
}

void Checkout::clear()
{
    delete list;
    countPerItem.~Array();
    itemsCount = 0;
    listCapacity = 0;
}

void Checkout::enterItem(const DessertItem& item, int cnt)
{
    if (countPerItem.getSize() < listCapacity + cnt)
    {
	    countPerItem.reSize((countPerItem.getSize() + 1) * 2);
    }

    countPerItem[itemsCount] = cnt;
    *(list[itemsCount]) = item;
    itemsCount++;
}

String Checkout::toString()
{
    String s;
    for (int i = 0; i < itemsCount; i++)
    {
        s+=list[i]->getName();
        s+=countPerItem[i] * list[i]->getCost();
        s+="=";
        s+=countPerItem[i];
        s+="x";
        s+=list[i]->getCost();
    }
    return s;
}

double Checkout::totalCost()
{
    double cost = 0;

    for (int i = 0; i < itemsCount; i++)
    {
        cost += list[i]->getCost();
    }
    return cost;
}

double Checkout::totalTax()
{
    return (DessertShoppe::getTaxRate() * totalCost()) / 100;
}

void Checkout::reSize(int cap)
{
    if (cap <= 0)
    {
        this->~Checkout();
        return;
    }
    DessertItem** temp = new DessertItem*[cap];
    if (cap)
    {
        for (int i = 0; i < listCapacity; i++)
        {
            *(temp[i]) = *(list[i]);
        }
    }
    this->~Checkout();
    list = temp;
    listCapacity = cap;
}
