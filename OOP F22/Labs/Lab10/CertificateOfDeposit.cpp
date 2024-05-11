#include "CertificateOfDeposit.h"

CertificateOfDeposit::CertificateOfDeposit(int month, float i, int n, String s, float b) : BankAccount(n, s, b)
{
	depositNo = 0;
	withdrawNo = 0;
	CDMaturityMonthsNO = (month > 0 ? month : 0);
	interestRate = (i > 0 ? i : 0);
	currCDMonth = 0;
}

void CertificateOfDeposit::makeDeposit(float amount)
{
	setBalance(getBalance() + amount);
	depositNo++;
}

float CertificateOfDeposit::withdrawMoney(float amount)
{
	float balance = getBalance();
	if (currCDMonth < CDMaturityMonthsNO || balance < amount)
	{
		return 0;
	}
	withdrawNo++;
	setBalance(balance - amount);
}

void CertificateOfDeposit::createMonthlyStatement()
{
	cout << "Your Current Balance: " << getBalance() << '\n';
	cout << "Total No Of deposits: " << depositNo << '\n';
	cout << "Total No Of withdrawals: " << depositNo << '\n';
}
