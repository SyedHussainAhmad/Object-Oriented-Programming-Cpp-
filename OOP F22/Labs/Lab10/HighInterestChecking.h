#ifndef HIGH_INTEREST_CHECKING_H
#define HIGH_INTEREST_CHECKING_H
#include"NoServiceChargeChecking.h"

class HighInterestChecking : public NoServiceChargeChecking
{
	int currChecks;
	double interestRate;
public:
	HighInterestChecking(float bal, float interest, int n, String s, float b);
	void writeChecks(float);
};

#endif // !HIGH_INTEREST_CHECKING_H
