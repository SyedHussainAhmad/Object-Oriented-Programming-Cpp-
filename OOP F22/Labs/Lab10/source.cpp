#include"HighInterestSavings.h"
#include"NoServiceChargeChecking.h"
#include"CertificateOfDeposit.h"

int main()
{
	SavingAccount s(3,1000,"Ali", 2000);
	NoServiceChargeChecking c(300, 3, 200,"Huss", 2000);
	s.createMonthlyStatement();
	cout << endl;
	return 0;
}