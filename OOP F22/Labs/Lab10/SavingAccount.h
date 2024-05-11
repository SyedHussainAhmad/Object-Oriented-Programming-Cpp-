#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include"BankAccount.h"

class SavingAccount : public BankAccount
{
	float interest;
	int depositNo;
	int withrawNo;
public:
	SavingAccount(float, int, String, float);
	void makeDeposit(float);
	float withdrawMoney(float);
	void createMonthlyStatement();
};
#endif // !SAVING_ACCOUNT_H
