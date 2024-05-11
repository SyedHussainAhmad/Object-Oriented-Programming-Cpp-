//#include <iostream>
//using namespace std;
//
//bool isDigit(char c) 
//{
//    return c >= '0' && c <= '9';
//}
//
//bool isInteger(const char* str) 
//{
//    if (*str == '-')
//    {
//        str++;
//    }
//    while (*str != '\0') 
//    {
//        if (!isDigit(*str)) 
//        {
//            return false;
//        }
//        str++;
//    }
//    return true;
//}
//
//int charArrayToInt(const char* str) 
//{
//    int result = 0;
//    bool isNegative = false;
//    if (*str == '-')
//    {
//        str++;
//        isNegative = true;
//    }
//    while (*str != '\0') 
//    {
//        result = result * 10 + (*str - '0');
//        str++;
//    }
//    return (isNegative ? result * -1 : result);
//}
//
//int inputNum() 
//{
//    const int bufferSize = 100;  // Adjust the buffer size as needed
//    char input[bufferSize];
//    bool findFlag = false;
//    int num;
//
//    while (!findFlag)
//    {
//        cout << "Enter Number: ";
//        cin.getline(input, bufferSize);
//
//        if (isInteger(input)) 
//        {
//            num = charArrayToInt(input);
//            findFlag = true;
//        }
//        else 
//        {
//            cout << "Not a valid integral value." << endl;
//        }
//    }
//    return num;
//}
//
//int main() 
//{
//    int num = inputNum();
//    cout << "The number is: " << num << '\n';
//    return 0;
//}
