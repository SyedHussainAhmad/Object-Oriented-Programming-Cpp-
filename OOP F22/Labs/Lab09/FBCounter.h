#ifndef FB_COUNTER_H
#define FB_COUNTER_H
#include"Counter.h"
class FBCounter : public Counter
{
	int value;
public:
	FBCounter();
	void decrement();
};
#endif // !FB_COUNTER_H