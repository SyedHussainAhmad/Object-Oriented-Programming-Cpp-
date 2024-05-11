#include<iostream>
using namespace std;

bool isVowel(const char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int getLength(const char* const str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isVowel(str[i]))
        {
            length++;
        }
    }
    return length;
}

char* getVowelFreeString(const char * const str)
{
    int length = getLength(str);

    // Allocate memory for result
    char* result = new char[length + 1]; // +1 for the null terminator.

    int i = 0, j =0;
    while (str[i]!= '\0')
    {
        if (!isVowel(str[i]))
        {
            result[j] = str[i];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    return result;
}

int main()
{
    char* str = getVowelFreeString("hello how are you? I am Fine...............");
    cout<< str;
    cout << endl;
    return 0;
}