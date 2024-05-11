#include"BigNumber.h"

int main()
{
  /*  BigNumber bn1("4253798563475682");
    BigNumber bn2("4253798563475692");

    cout << "Adding bn1 and bn2:\n";
    BigNumber bn4 = bn1.add(bn2);
    bn4.print();
    cout << endl;

    cout << "Comparison of bn1 and bn2:\n";
    switch (bn1.compare(bn2))
    {
    case EQUAL:
        cout << "Both numbers are equal.\n";
        break;
    case SMALL:
        cout << "bn1 is smaller than bn2.\n";
        break;
    case LARGE:
        cout << "bn1 is larger than bn2.\n";
        break;
    }*/
    BigNumber bn1("999");
    BigNumber bn2("999");

    bn1.add(bn2).print();
    return 0;
}