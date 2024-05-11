#include"Counter.h"

Counter::Counter(int i = 0) : value(i)
{
}
void Counter::increment()
{
	value++;
}

void Counter::reset()
{
	value = 0;
}

void Counter::startAt(int i = 1)
{
	value = i;
}

int Counter::getCounterValue()
{
	return value;
}