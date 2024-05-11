#include "HighInterestSavings.h"

HighInterestSavings::HighInterestSavings(int m, float i, int n, String s, float b) : SavingAccount(i,n,s,b)
{
	minBalance = m;
}
