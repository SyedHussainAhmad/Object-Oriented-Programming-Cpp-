#ifndef FB_COUNTER_H
#define FB_COUNTER_H
#include"Counter.h"
class FBCounter
{
	Counter c;
public:
	FBCounter();	
	void increment();
	void decrement();
	int getCounterValue();
};
#endif // !FB_COUNTER_H