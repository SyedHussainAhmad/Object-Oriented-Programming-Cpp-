#ifndef SERVICE_ACOUNT_CHECKING_H
#define SERVICE_ACOUNT_CHECKING_H
#include"CheckingAccount.h"

class ServiceAccountChecking: CheckingAccount
{
	int serviceCharge;
	int noOfChecks;
	int currNo;
protected:
	int getNoOfChecks();
public:
	ServiceAccountChecking(int,int, int, String, float);
	void writeCheck();
};
#endif // !SERVICE_ACOUNT_CHECKING_H
