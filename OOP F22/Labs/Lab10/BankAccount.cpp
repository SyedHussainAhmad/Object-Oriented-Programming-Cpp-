#include "BankAccount.h"

int BankAccount::getAccountNumber()
{
	return accountNumber;
}

String BankAccount::getName()
{
	return name;
}

float BankAccount::getBalance()
{
	return balance;
}

void BankAccount::setAccountNumber(int n)
{
	accountNumber = n;
}

void BankAccount::setName(String s)
{
	name = s;
}

void BankAccount::setBalance(float b)
{
	if (b>0)
	{
		balance = b;
	}
}

BankAccount::BankAccount(int n, String s, float b)
{
	accountNumber = (n > 0 ? n : 0);
	name = s;
	balance = (b > 0 ? b : 0);
}
