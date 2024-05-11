#include"FBCounter.h"

FBCounter::FBCounter() : c(0)
{
}

void FBCounter::increment()
{
	c.increment();
}

void FBCounter::decrement()
{
	c.startAt(c.getCounterValue() - 1);
}

int FBCounter::getCounterValue()
{
	return c.getCounterValue();
}