#ifndef OVER_NIGHT_PACKAGE_H
#define OVER_NIGHT_PACKAGE_H
#include"Package.h"

class OverNightPackage : public Package
{
	double additionalFeePerOunce;
public:
	OverNightPackage(double);
	double calculateCost();
};
#endif // !OVER_NIGHT_PACKAGE_H
