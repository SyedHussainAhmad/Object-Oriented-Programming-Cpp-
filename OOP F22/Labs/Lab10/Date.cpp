#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;

const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool Date::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
}

bool Date::isValidDay(int) const
{
    bool leapFlag = isLeapYear();
    if (daysInMonth[month] == 28)
    {
        return (leapFlag ? (day > 0 && day <= 29): (day > 0 && day <= 28));
    }
    else
    {
        return (day > 0 && day <= daysInMonth[month]);
    }
}
bool Date::isValidMonth(int) const
{
    return (month > 0 && month < 13);
}
bool Date::isValidYear(int year) const
{
    return (year >= 1500 && year <= 3000);
}

String Date::monthStr() const
{
    String monthList[13]{ "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return monthList[month];
}

String Date::shortMonthStr() const
{
    String monthList[13]{ "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return monthList[month];
}

String Date::getDayString() const
{
    String dayStr;
    dayStr.setNumber(day);
    if (day < 10)
    {
        dayStr.insert(0, '0');
    }
    return dayStr;
}

String Date::getMonthString(int value) const
{
    String monStr;
    if (!value)
    {
        monStr.setNumber(month);
        if (month < 10)
        {
            monStr.insert(0, '0');
        }
    }
    else if (value == 1)
    {
        monStr.insert(0, monthStr());
    }
    else
    {
        monStr.insert(0, shortMonthStr());
    }
    return monStr;
}

String Date::getYearString() const
{
    String yearStr;
    yearStr.setNumber(year);
    return yearStr;
}

Date::Date()
{
    day = 1;
    month = 1;
    year = 2023;
}

Date::Date(int refDay, int refMonth, int refYear):Date()
{
    if (isValidYear(refYear))
    {
        year = refYear;
    }

    if (isValidMonth(refMonth))
    {
        month = refMonth;
    }

    if (isValidDay(refDay))
    {
        day = refDay;
    }
}

void Date::setDate(int refDay, int refMonth, int refYear)
{
    if (isValidYear(refYear))
    {
        year = refYear;
    }

    if (isValidMonth(refMonth))
    {
        month = refMonth;
    }

    if (isValidDay(refDay))
    {
        day = refDay;
    }
}

void Date::setYear(int refYear)
{
    if (isValidYear(refYear))
    {
        year = refYear;
    }
}

void Date::setMonth(int refMonth)
{
    if (isValidMonth(refMonth))
    {
        year = refMonth;
    }
}

void Date::setDay(int refDay)
{
    if (isValidDay(refDay))
    {
        year = refDay;
    }
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::printFormat1() const
{
    cout << setw(2) << right << setfill('0') << month << '/';
    cout << setw(2) << right << setfill('0') << day << '/';
    cout << setw(4) << right << setfill('0') << year;
}

void Date::printFormat2() const
{
    monthStr().display();
    cout << ' ' << day << "," << year;
}

void Date::printFormat3() const
{
    cout << day << '-';
    shortMonthStr().display();
    cout << "-" << year;
}

void Date::incDay(int inc)
{
    if (inc <= 0)
    {
        return;
    }
    day += inc;
    if (daysInMonth[month] != day)
    {
        day = day % daysInMonth[month];
        inc = inc / daysInMonth[month];
        incMonth(inc);
    }
}

void Date::incMonth(int inc)
{
    if (inc <= 0)
    {
        return;
    }
    month += inc;
    if (month > 12)
    {
        month = month % 12;
        inc = inc / 12;
        incDay(inc);
    }
}

void Date::incYear(int inc)
{
    if (inc <= 0)
    {
        return;
    }
    day+= inc;
}


String Date::getDateInFormat1() const
{
    String dayStr = getDayString();
    String monStr = getMonthString();
    String yearStr = getMonthString();

    String dateStr;
    dateStr.insert(0, yearStr);
    dateStr.insert(0, '/');
    dateStr.insert(0, dayStr);
    dateStr.insert(0, '/');
    dateStr.insert(0, monStr);
    return dateStr;
}

String Date::getDateInFormat2() const
{
    String dayStr = getDayString();
    String monStr = getMonthString(1);
    String yearStr = getMonthString();

    String dateStr;
    dateStr.insert(0, yearStr);
    dateStr.insert(0, ',');
    dateStr.insert(0, dayStr);
    dateStr.insert(0, ' ');
    dateStr.insert(0, monStr);
    return dateStr;
}

String Date::getDateInFormat3() const
{
    String dayStr = getDayString();
    String monStr = getMonthString(2);
    String yearStr = getMonthString();

    String dateStr;
    dateStr.insert(0, yearStr);
    dateStr.insert(0, '-');
    dateStr.insert(0, monStr);
    dateStr.insert(0, '-');
    dateStr.insert(0, dayStr);
    return dateStr;
}
