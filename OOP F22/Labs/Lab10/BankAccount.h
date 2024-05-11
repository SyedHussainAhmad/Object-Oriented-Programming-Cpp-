#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include"String.h"

class BankAccount
{
	int accountNumber;
	String name;
	float balance;

protected:
	int getAccountNumber();
	String getName();
	float getBalance();
	void setAccountNumber(int);
	void setName(String);
	void setBalance(float);

public:
	BankAccount(int, String, float);
	virtual void makeDeposit(float) = 0;
	virtual float withdrawMoney(float) = 0;
	virtual void createMonthlyStatement() = 0;
};
#endif // !BANK_ACCOUNT_H
