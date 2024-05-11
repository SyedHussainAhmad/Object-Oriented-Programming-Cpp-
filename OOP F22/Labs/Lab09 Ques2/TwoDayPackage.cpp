#include"TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(double f)
{
	flatFee = (f > 0 ? f : 0);
}

double TwoDayPackage::calculateCost()
{
	return Package::calculateCost() + flatFee;
}
