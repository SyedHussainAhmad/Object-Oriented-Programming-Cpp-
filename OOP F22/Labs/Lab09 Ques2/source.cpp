#include<iostream>
using namespace std;
#include"OvernightPackage.h"
#include"TwoDayPackage.h"

int main()
{
    Person p{ "Ahmad","johar town", "lahore" , "Punjab", 5400 };
    Package pac{p,3,10};
    cout << pac.calculateCost();
    cout << endl;


    TwoDayPackage two{10};
    two.setWeight(20);
    two.setCostPerOunce(1);
    cout << two.calculateCost();
    cout << endl;


    OverNightPackage n{ 1 };
    n.setWeight(20);
    n.setCostPerOunce(1);
    cout << n.calculateCost();

    cout << endl;
    return 0;
}