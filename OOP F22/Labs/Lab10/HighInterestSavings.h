#ifndef HIGH_INTEREST_SAVINGS_H
#define HIGH_INTEREST_SAVINGS_H
#include"SavingAccount.h"

class HighInterestSavings : public SavingAccount
{
	int minBalance;
public:
	HighInterestSavings(int , float, int, String, float);
};
#endif // !HIGH_INTEREST_SAVINGS_H
