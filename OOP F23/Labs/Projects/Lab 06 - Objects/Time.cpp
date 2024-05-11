#include "Time.h"

Time::Time(int h, int m, int s) : hour(0, 23, h), minute(0, 59, m), second(0, 59, s)
{}

void Time::setHour(int h)
{
    hour.setValue(h);
}

void Time::setMinute(int m)
{
    minute.setValue(m);
}

void Time::setSecond(int s)
{
    second.setValue(s);
}

void Time::setTime(int h, int m, int s)
{
    hour.setValue(h);
    minute.setValue(m);
    second.setValue(s);
}

int Time::getHour() const 
{
    return hour.getValue();
}

int Time::getMinute() const 
{
    return minute.getValue();
}

int Time::getSecond() const 
{
    return second.getValue();
}

void Time::printTwentyFourHourFormat() const 
{
    cout << "Time: " << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue() << endl;
}

void Time::printTwelveFourHourFormat() const 
{
    int h = hour.getValue();
    char period[3] = { 'A', 'M', '\0' };
    if (h >= 12) 
    {
        period[0] = 'P';
        h = (h == 12) ? 12 : h % 12;
    }
    else 
    {
        h = (h == 0) ? 12 : h;
    }
    cout << "Time: " << h << ":" << minute.getValue() << ":" << second.getValue() << " " << period << endl;
}


void Time::incSec(int inc) 
{
    second.increment(inc);
    if (second.getValue() >= 60) 
    {
        second.setValue(second.getValue() % 60);
        incMin();
    }
}

void Time::incMin(int inc)
{
    incHour(inc / 60);
    if (minute.getValue() + inc % 60 > 59)
    {
        incHour(1);
    }
    minute.increment(inc % 60);
}

void Time::incHour(int inc) 
{
    hour.increment(inc);
    hour.setValue(hour.getValue() % 24);
}

void Time::decSec(int dec) 
{
    second.decrement(dec);
    if (second.getValue() < 0) 
    {
        minute.decrement(1);
        second.increment(60);
    }
}

void Time::decMin(int dec) 
{
    minute.decrement(dec);
    if (minute.getValue() < 0) 
    {
        hour.decrement(1);
        minute.increment(60);
    }
}

void Time::decHour(int dec) 
{
    hour.decrement(dec);
    if (hour.getValue() < 0) 
    {
        hour.increment(24);
    }
}
