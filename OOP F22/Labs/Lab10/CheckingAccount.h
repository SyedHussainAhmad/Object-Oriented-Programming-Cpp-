#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include"BankAccount.h"

class CheckingAccount : public BankAccount
{
	int depositNo;
	int withrawNo;
public:
	CheckingAccount(int, String, float);
	void makeDeposit(float);
	float withdrawMoney(float);
	void createMonthlyStatement();
	virtual void writeCheck() = 0;
};
#endif // !CHECKING_ACCOUNT_H
