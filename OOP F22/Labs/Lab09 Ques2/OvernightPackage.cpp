#include"OvernightPackage.h"

OverNightPackage::OverNightPackage(double fee)
{
	additionalFeePerOunce = (fee > 0 ? fee : 0);
}

double OverNightPackage::calculateCost()
{
	return (Package::calculateCost() + additionalFeePerOunce);
}