#include "SavingAccount.h"

SavingAccount::SavingAccount(float i, int n, String s, float b) : BankAccount(n, s, b)
{
	interest = (i > 0 ? i : 0);
}

void SavingAccount::makeDeposit(float amount)
{
	setBalance(getBalance() + amount);
}

float SavingAccount::withdrawMoney(float amount)
{
	float balance = getBalance();
	if (balance < amount)
	{
		return 0;
	}

	setBalance(balance - amount);
}

void SavingAccount::createMonthlyStatement()
{
	cout << "Your Current Balance: " << getBalance() << '\n';
	cout << "Total No Of deposits: " << depositNo << '\n';
	cout << "Total No Of withdrawals: " << depositNo << '\n';
}