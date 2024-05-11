#include"BigNumber.h"

int main()
{
	BigNumber bn1{"20"};
	BigNumber bn2{"200"};
	bn2.multiply(bn1).print();
	return 0;
}