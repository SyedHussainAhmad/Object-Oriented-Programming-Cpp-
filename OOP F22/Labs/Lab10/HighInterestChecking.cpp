#include "HighInterestChecking.h"


HighInterestChecking::HighInterestChecking(float bal, float interest, int n, String s, float b) : currChecks(0), NoServiceChargeChecking(bal, interest, n, s, b)
{
	interestRate = (interest > 0 ? interest : 0);
}

void HighInterestChecking::writeChecks(float amount)
{
	currChecks++;
}