#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
	int value;
public:
	Counter(int );
	void increment();
	void reset();
	void startAt(int);
	int getCounterValue();
};
#endif // !COUNTER_H