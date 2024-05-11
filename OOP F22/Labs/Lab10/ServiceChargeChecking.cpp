#include "ServiceChargeChecking.h"

int ServiceAccountChecking::getNoOfChecks()
{
	return noOfChecks;
}

ServiceAccountChecking::ServiceAccountChecking(int c,int no , int n, String s, float b) : currNo(0) , CheckingAccount(n,s,b)
{
	serviceCharge = (c > 0 ? c : 0);
	noOfChecks = (no > 0 ? no : 0);
}

void ServiceAccountChecking::writeCheck()
{
	if (currNo>=noOfChecks)
	{
		return;
	}
	currNo++;
}
