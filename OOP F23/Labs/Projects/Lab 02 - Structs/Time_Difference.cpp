//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//#include <ctime> 
//
//struct Time
//{
//    int hours;
//    int minutes;
//    int seconds;
//};
//
//Time getTimeDifference(Time userTime)
//{
//    // Code to get system time
//    Time currentTime;
//    time_t t = time(0);
//    tm curTime = *localtime(&t);
//    currentTime.hours = curTime.tm_hour;
//    currentTime.minutes = curTime.tm_min;
//    currentTime.seconds = curTime.tm_sec;
//
//    // Calculate time difference
//    Time diffTime;
//    diffTime.hours = currentTime.hours - userTime.hours;
//    diffTime.minutes = currentTime.minutes - userTime.minutes;
//    diffTime.seconds = currentTime.seconds - userTime.seconds;
//
//    // Adjust negative values
//    if (diffTime.seconds < 0)
//    {
//        diffTime.seconds += 60;
//        diffTime.minutes--;
//    }
//    if (diffTime.minutes < 0)
//    {
//        diffTime.minutes += 60;
//        diffTime.hours--;
//    }
//    if (diffTime.hours < 0)
//    {
//        diffTime.hours += 24;
//    }
//
//    return diffTime;
//}
//
//int main()
//{
//    Time t1 = { 10, 15, 50 };
//    Time diffTime1 = getTimeDifference(t1);
//    cout << diffTime1.hours << " : " << diffTime1.minutes << " : " << diffTime1.seconds << endl;
//
//    return 0;
//}
