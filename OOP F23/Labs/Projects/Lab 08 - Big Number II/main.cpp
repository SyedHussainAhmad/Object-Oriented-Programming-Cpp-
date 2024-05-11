#include"BigNumber.h"

int main()
{
	//BigNumber bn1{ "45" };
	//BigNumber bn2{ "45" };
	////(bn1 - bn2).print(); //prints on console 0
	//cout << '\n';

	//bool cond = bn1 == bn2;
	//cout << cond;
	//bn2 = "2";
	//BigNumber bg = bn1 - bn2;
	////bg.print(); //prints on console 43
	//cout << '\n';

	//bg = bn1 * bn2;
	////bg.print(); //prints on console 90
	BigNumber bn1{ "45" };
	BigNumber bn2{ "45" };
	cout << (bn1 >= bn2); //prints 1
	cout << (bn1 > bn2); //prints 0
	cout << (bn1 == bn2); //prints 1

}
