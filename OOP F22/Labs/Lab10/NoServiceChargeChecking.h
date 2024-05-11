#ifndef NO_SERVICE_CHARGE_CHECKING_H
#define NO_SERVICE_CHARGE_CHECKING_H
#include"CheckingAccount.h"

class NoServiceChargeChecking: public CheckingAccount
{
	float minBalance;
	float interestRate;
	int currCheck;
public:
	NoServiceChargeChecking(float bal, float interest, int n, String s, float b);
	void writeCheck();
};

#endif // !NO_SERVICE_CHARGE_CHECKING_H
