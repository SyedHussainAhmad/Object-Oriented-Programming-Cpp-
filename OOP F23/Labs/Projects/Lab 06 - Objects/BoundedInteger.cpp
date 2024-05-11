#include "BoundedInteger.h"

bool BoundedInteger::isValidBound(int lb, int ub) 
{
    return lb <= ub;
}

BoundedInteger::BoundedInteger() : lowerBound(-2147483647), upperBound(2147483647), value(lowerBound) {}

BoundedInteger::BoundedInteger(int lb, int ub) : BoundedInteger()
{
    if (!isValidBound(lb, ub)) 
    {
        return;
    }
    lowerBound = lb;
    upperBound = ub;
    value = lowerBound;
}

BoundedInteger::BoundedInteger(int lb, int ub, int val) : BoundedInteger()
{
    if (!isValidBound(lb, ub))
    {
        return;
    }
    lowerBound = lb;
    upperBound = ub;
    value = isValidValue(val) ? val : lowerBound;
}

void BoundedInteger::setValue(int val)
{
    if (isValidValue(val)) 
    {
        value = val;
    }
}

int BoundedInteger::getValue() const 
{
    return value;
}

int BoundedInteger::getLowerBound() const
{
    return lowerBound;
}

int BoundedInteger::getUpperBound() const
 {
    return upperBound;
}

void BoundedInteger::increment(int inc)
{
    value = (value + inc - lowerBound) % (upperBound - lowerBound + 1) + lowerBound;
}

void BoundedInteger::decrement(int dec)
{
    value = (value - dec - lowerBound + upperBound - lowerBound + 1) % (upperBound - lowerBound + 1) + lowerBound;
}

bool BoundedInteger::isValidValue(int val) const
{
    return val >= lowerBound && val <= upperBound;
}
