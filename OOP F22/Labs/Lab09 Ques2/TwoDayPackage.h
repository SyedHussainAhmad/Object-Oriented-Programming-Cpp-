#ifndef TWO_DAY_PACKAGE_H
#define TWO_DAY_PACKAGE_H
#include"Package.h"

class TwoDayPackage : public Package
{
	double flatFee;
public:
	TwoDayPackage(double);
	double calculateCost();
};
#endif // !TWO_DAY_PACKAGE_H
