#ifndef SUNDAE_H
#define SUNDAE_H
#include"IceCream.h"

class Sundae : public IceCream
{
	double costOfTopping;
public:
	Sundae(double, double, String);
	double getCost() const;
};
#endif // !SUNDAE_H