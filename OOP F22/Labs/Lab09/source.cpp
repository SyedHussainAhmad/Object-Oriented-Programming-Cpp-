#include<iostream>
#include"FBCounter.h"
using namespace std;

int main()
{
    FBCounter c;
    c.increment();
    c.increment();
    c.decrement();
    c.increment();
    cout << c.getCounterValue();
    cout << endl;
    return 0;
}