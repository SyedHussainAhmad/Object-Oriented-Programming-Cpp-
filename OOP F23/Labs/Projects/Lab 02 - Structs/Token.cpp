#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cTime>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

struct Token
{
    int tokenNumber;
    Date tokenDate;
    Time tokenTime;
};

struct ServiceCounter
{
    int counterNumber;
    Token list[100];
    int tokensCount;
};

void printDate(Date date)
{
    cout << "Date: " << date.day << ":" << date.month << ":" << date.year << '\n';
}

void printTime(Time time)
{
    cout << "Time: " << time.hours << ":" << time.minutes << ":" << time.seconds << '\n';
}

Token generateToken()
{
    static int tokenCounter = 0;

    Token newToken;
    newToken.tokenNumber = ++tokenCounter;

    // Code to get system date and time
    Date currentDate;
    time_t t = time(0);
    tm curTime = *localtime(&t);
    currentDate.day = curTime.tm_mday;
    currentDate.month = curTime.tm_mon + 1;
    currentDate.year = curTime.tm_year + 1900;

    newToken.tokenDate = currentDate;
    newToken.tokenTime.hours = curTime.tm_hour;
    newToken.tokenTime.minutes = curTime.tm_min;
    newToken.tokenTime.seconds = curTime.tm_sec;

    return newToken;
}

void printToken(Token token)
{
    cout << "Token # : " << token.tokenNumber << endl;
    printTime(token.tokenTime);
    printDate(token.tokenDate);
}

void initializeServiceCounter(ServiceCounter& counter)
{
    static int counterNumber = 0;
    counter.counterNumber = ++counterNumber;
    counter.tokensCount = 0;
}

void assignToken(ServiceCounter& counter, Token token)
{
    if (counter.tokensCount < 100)
    {
        counter.list[counter.tokensCount++] = token;
    }
    else
    {
        cout << "Token queue is full at Counter #" << counter.counterNumber << ". Cannot assign more tokens." << endl;
    }
}

void serviceToken(ServiceCounter& counter)
{
    if (counter.tokensCount > 0)
    {
        // Perform service for the first token (first come first serve)
        cout << "*** Service Token @ Counter #" << counter.counterNumber << " ***" << endl;
        printToken(counter.list[0]);

        // Shift the remaining tokens in the queue
        for (int i = 0; i < counter.tokensCount - 1; ++i)
        {
            counter.list[i] = counter.list[i + 1];
        }

        counter.tokensCount--;
    }
    else
    {
        cout << "*** No tokens in the queue at Counter #" << counter.counterNumber << " ***" << endl;
    }
}

void printTokensAtServiceCounter(ServiceCounter counter)
{
    cout << "*** Token Queue Waiting For Service @ Counter #" << counter.counterNumber << " ***" << endl;

    if (counter.tokensCount > 0)
    {
        for (int i = 0; i < counter.tokensCount; ++i)
        {
            printToken(counter.list[i]);
        }
    }
    else
    {
        cout << "--> Queue is Empty <---" << endl;
    }
}

int main()
{
    // Sample Run
    Token x = generateToken();
    cout << "Token # : " << x.tokenNumber << endl;

    Token y = generateToken();
    printTime(y.tokenTime);
    printDate(y.tokenDate);
    cout << "Token # : " << y.tokenNumber << endl;

    ServiceCounter a, b;
    initializeServiceCounter(a);
    initializeServiceCounter(b);

    assignToken(a, generateToken());
    assignToken(b, generateToken());
    assignToken(a, generateToken());
    assignToken(a, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(b, generateToken());
    assignToken(a, generateToken());

    printTokensAtServiceCounter(a);
    serviceToken(a);
    printTokensAtServiceCounter(a);
    serviceToken(a);
    serviceToken(a);
    serviceToken(a);
    printTokensAtServiceCounter(a);

    serviceToken(b);
    printTokensAtServiceCounter(b);

    return 0;
}
