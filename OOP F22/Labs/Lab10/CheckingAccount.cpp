#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int n, String s, float b) : depositNo(0), withrawNo(0), BankAccount(n,s,b)
{
}

void CheckingAccount::makeDeposit(float amount)
{
	setBalance(getBalance() + amount);
	depositNo++;
}

float CheckingAccount::withdrawMoney(float amount)
{
	float balance = getBalance();
	if (balance < amount)
	{
		return 0;
	}
	withrawNo++;
	setBalance(balance - amount);
}

void CheckingAccount::createMonthlyStatement()
{
	cout << "Your Current Balance: " << getBalance() << '\n';
	cout << "Total No Of deposits: " << depositNo << '\n';
	cout << "Total No Of withdrawals: " << depositNo << '\n';
}

