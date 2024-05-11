#include "NoServiceChargeChecking.h"

NoServiceChargeChecking::NoServiceChargeChecking(float bal, float interest, int n, String s, float b) : currCheck(0), CheckingAccount(n, s, b)
{
	minBalance = (bal > 0 ? bal : 0);
	interestRate = (interest > 0 ? interest : 0);
}

void NoServiceChargeChecking::writeCheck()
{
	currCheck++;
}
