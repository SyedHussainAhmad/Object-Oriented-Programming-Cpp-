#ifndef CERTIFICATE_OF_DEPOSIT
#define CERTIFICATE_OF_DEPOSIT
#include"BankAccount.h"

class CertificateOfDeposit : public BankAccount
{
	int depositNo;
	int withdrawNo;
	int CDMaturityMonthsNO;
	float interestRate;
	int currCDMonth;
public:
	CertificateOfDeposit(int , float, int, String, float);
	void makeDeposit(float);
	float withdrawMoney(float);
	void createMonthlyStatement();
};
#endif // !CERTIFICATE_OF_DEPOSIT
