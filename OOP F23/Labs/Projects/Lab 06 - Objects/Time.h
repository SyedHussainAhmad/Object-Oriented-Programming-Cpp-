#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
#include"BoundedInteger.h"

class Time
{
	BoundedInteger hour;
	BoundedInteger minute;
	BoundedInteger second;
public:
	Time(int h = 0, int m = 0, int s = 0);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	void setTime(int h, int m, int s);
	int getHour()const;
	int getMinute()const;
	int getSecond()const;
	void printTwentyFourHourFormat()const;
	void printTwelveFourHourFormat()const;
	void incSec(int inc = 1);
	void incMin(int inc = 1);
	void incHour(int inc = 1);
	void decSec(int inc = 1);
	void decMin(int inc = 1);
	void decHour(int inc = 1);
};
#endif // !TIME_H