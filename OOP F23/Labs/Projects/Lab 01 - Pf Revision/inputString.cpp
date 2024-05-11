//#include<iostream>
//using namespace std;
//
//int getLength(const char* const str)
//{
//    int length = 0;
//    while (str[length] !='\0')
//    {
//        length++;
//    }
//    return length;
//}
//
//char * getResizedString(char* const str)
//{
//    int length = getLength(str);
//    char* resizedResult = new char[length + 1];  // +1 for the null terminator
//    for (int i = 0; i < length; i++)
//    {
//        resizedResult[i] = str[i];
//    }
//    resizedResult[length] = '\0';  // Null terminate the resized string
//
//    // Free the memory allocated for the original result
//    delete[] str;
//
//    return resizedResult;
//}
//
//char* inputString()
//{
//    char* result = new char[200]; // length can be changed as it is a particular length.
//    cin.getline(result,200);
//    result = getResizedString(result);
//    return result;
//}
//
//int main()
//{
//    char* str = inputString();
//    cout << "Start = " << str << " = End";
//    cout << endl;
//    return 0;
//}