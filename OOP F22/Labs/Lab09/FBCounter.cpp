#include"FBCounter.h"

FBCounter::FBCounter() : Counter(0)
{
	value = getCounterValue();
}

void FBCounter::decrement()
{
	value--;
	startAt(getCounterValue() - 1);
}
