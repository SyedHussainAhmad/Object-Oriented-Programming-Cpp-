#include<iostream>
#include"String.h"
using namespace std;

int String::getStrLength(const char* ch) const
{
    int length = 0;

    while (ch != nullptr && ch[length] != '\0')
    {
        length++;
    }
    return length;
}

int String::getNumberPart(const char* data, int start) const
{
    int i = start;
    int num = 0;
    while (data[i] != '\0' && data[i] != '.')
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            num = num * 10 + (data[i] - '0');
        }
        i++;
    }
    return num;
}

bool String::isNegativeNum(const char* data) const
{
    bool minusFlag = false;
    int i = 0;
    while (data[i] != '\0' && !minusFlag)
    {
        if (data[i] == '-')
        {
            minusFlag = true;
        }
        i++;
    }
    if (minusFlag)
    {
        (data[i] >= '0' || data[i] <= '9') ? minusFlag = true : minusFlag = false;
    }
    return minusFlag;
}

int String::getDotIndex(const char* data) const
{
    bool dotFlag = false;
    int i = 0;
    while (data[i] != '\0' && !dotFlag)
    {
        if (data[i] == '.')
        {
            dotFlag = true;
        }
        i++;
    }
    return dotFlag ? i : -1;
}

int String::numLength(long long int num) const
{
    int len = 1;
    num < 0 ? num = num * -1 : num;
    while (num >= 10)
    {
        num = num / 10;
        len++;
    }
    return len;
}
int String::getDivisor(int length) const
{
    int divisor = 1;
    for (int i = 0; i < length; i++)
    {
        divisor *= 10;
    }
    return divisor;
}

void String::copyString(const char* source, char* dest) const
{
    if (!source)
    {
        return;
    }
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

int String::findIndex(int start, const String& subStr)  const
{
    int length = getLength();
    int lengthOfSubStr = subStr.getLength();
    if (lengthOfSubStr == 0)
        return 0;

    for (int i = start; i <= length - lengthOfSubStr; i++)
    {
        int j = 0;
        while (j < lengthOfSubStr)
        {
            if (data[i + j] != subStr.at(j))
                break;
            j++;
        }
        if (j == lengthOfSubStr)
            return i;
    }
    return 0;
}
void String::swap(char& ch1, char& ch2)
{
    char temp = ch1;
    ch1 = ch2;
    ch2 = temp;
}

String::String()
{
    data = nullptr;
    size = 0;
}

String::String(const String& ref) :String()
{
    if (!ref.data)
    {
        return;
    }
    size = ref.size;
    data = new char[size];
    copyString(ref.data, data);
}

String::String(char c)
{
    size = 2;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
}

String::String(const char* ch) :String()
{
    int sizeOfStr = getStrLength(ch);
    if (sizeOfStr != 0)
    {
        data = new char[sizeOfStr + 1];
        copyString(ch, data);
        size = sizeOfStr + 1;
    }
}

String::~String()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }
}

int String::getSize() const
{
    return size;
}

void String::input()
{
    char ch;
    int index = 0;
    if (data != nullptr)
    {
        index = getLength();
    }
    else
    {
        size = 2;
        data = new char[size];
    }
    cout << "Enter String : ";
    while (cin.get(ch))
    {
        if (ch == '\n')
        {
            data[index] = '\0';
            return;
        }
        if (index >= size - 1)
        {
            reSize(size * 2);
        }
        data[index] = ch;
        index++;
    }
    data[index] = '\0';
}

void String::display() const
{
    cout << data;
}

int String::getLength() const
{
    return getStrLength(data);
}

char& String::at(int index)
{
    return data[index];
}
const char& String::at(const int index) const
{
    return data[index];
}

bool String::isEmpty() const
{
    if (data == nullptr)
        return true;
    else if (size >= 1)
    {
        if (data[0] == '\0')
            return true;
    }
    return false;
}

int String::find(String& subStr, int  start) const
{
    int count = 0;
    int length = getLength();
    int lengthOfSubStr = subStr.getLength();

    for (int i = 0; i <= length - lengthOfSubStr; i++) {
        int j = 0;
        while (j < lengthOfSubStr)
        {
            if (data[i + j] != subStr.at(j))
                break;
            j++;
        }
        if (j == lengthOfSubStr)
            count++;
    }
    return count;
}

void String::trimLeft()
{
    if (isEmpty())
    {
        return;
    }

    int i = 0;
    while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
    {
        i++;
    }
    copyString(&data[i], &data[0]);
}

void String::trimRight()
{
    if (isEmpty())
    {
        return;
    }

    int i = getLength() - 1;
    while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
    {
        i--;
    }
    data[i] = '\0';

}

void String::trim()
{
    trimLeft();
    trimRight();
}

void String::insert(int index,  String& subStr)
{
    if ((isEmpty() || getLength() == 0) && index == 0)
    {
        reSize(subStr.getLength() + 1);
        copyString(subStr.data, data);
        return;
    }
    if (subStr.getLength() == 0 || index < 0)
    {
        return;
    }

    int subStrLength = subStr.getLength();
    int strLength = getLength();
    if (index<0 || index > strLength)
        return;
    int newSize = strLength + subStrLength +1;
    char* temp = new char[newSize];
    char c = data[index];
    data[index] = '\0';
    copyString(data, temp);
    copyString(subStr.data, &temp[index]);
    temp[index + subStrLength] = c;
    copyString(&data[index + 1], &temp[index + subStrLength + 1]);
    this->~String();
    size = newSize;
    data = temp;

}

void String::remove(const int index, const int  count)
{
    int lengthOfCurr = getLength();
    if (index + count > lengthOfCurr)
    {
        data[0] = '\0';
        shrink();
        return;
    }
    if (index < 0 || index >= lengthOfCurr)
    {
        return;
    }
    else if (lengthOfCurr == 0 || isEmpty())
    {
        return;
    }
    else
    {
        copyString(&data[index + count], &data[index]);
    }
}

int String::replace(String& old, String& newSubStr)
{
    if (old.data == nullptr || newSubStr.data == nullptr)
        return 0;
    int occurances = find(old);
    int i = 1;
    int newSubLen = newSubStr.getLength();
    int index = 0;
    if (occurances > 0)
    {
        while (i <= occurances)
        {
            index = findIndex(index, old);
            remove(index, old.getLength());

            insert(index, newSubStr);
            index += newSubLen;
            i = i + 1;
        }
    }
    return occurances;
}

void String::makeUpper()
{
    int i = 0;
    while (data[i] != '\0')
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = data[i] - 32;
        }
        i++;
    }
}

void String::makeLower()
{
    int i = 0;
    while (data[i] != '\0')
    {
        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = data[i] + 32;
        }
        i++;
    }
}

void String::reverse()
{
    int n = getLength();
    for (int i = 0; i < n / 2; i++)
        swap(data[i], data[n - i - 1]);
}

void String::reSize(int newSize)
{
    if (newSize <= 0)
    {
        this->~String();
        return;
    }
    char* temp = new char[newSize];
    if (!isEmpty())
    {
        copyString(data, temp);
    }
    this->~String();
    data = temp;
    size = newSize;
}

void String::shrink()
{
    int newSize = getLength()+1;
    reSize(newSize);
}

bool String::compare(const String& str2) const
{
    int i = 0;
    bool findFlag = true;
    while (data[i] != '\0' && findFlag)
    {
        if (data[i] != str2.data[i])
        {
            findFlag = false;
        }
        i = i + 1;
    }
    return findFlag;
}

String String::left(const int count)
{
    if (!data || count > getLength())
    {
        return *this;
    }
    String str;
    str.data = new char[size];
    copyString(data, str.data);
    str.data[count] = '\0';
    str.shrink();
    return str;
}

String String::right(const int count)
{
    if (!data || count > getLength())
    {
        return *this;
    }
    String str;
    str.size = size - count;
    str.data = new char[str.size];
    int len = getLength();
    copyString(&data[len - count], str.data);
    return str;
}

int String::toInteger() const
{
    int integralValue = 0;
    if (isEmpty())
    {
        return integralValue;
    }

    bool negativeFlag = isNegativeNum(data);

    int i = 0;
    while (data[i] != '\0')
    {
        if (data[i] >= '0' && data[i] <= '9')
        {
            integralValue = integralValue * 10 + (data[i] - '0');
        }
        i++;
    }
    return  negativeFlag? integralValue*1: integralValue;
}

String String::concat(const String& s2) const
{
    String str;
    str.size = size + s2.size;
    str.data = new char[str.size];
    int len = getLength();
    copyString(data, str.data);
    copyString(s2.data, &str.data[len]);
    return str;
}

void String::concatEqual(const String& s2)
{
    if (s2.isEmpty())
        return;
    int len = getLength();
    int s2Len = s2.getLength();
    reSize(len + s2Len + 1);
    copyString(s2.data, &data[len]);
}

void String::setNumber(const long long int num)
{
    int len = numLength(num);
    this->~String();
    long long int temp = num;
    int i = 0;
    if (temp < 0)
    {
        reSize(len + 2);
        at(len) = '-';
        temp = temp * -1;
    }
    else
    {
        reSize(len + 1);
    }
    while (len > 0)
    {
        int rem = temp % 10;
        at(i) = rem + '0';
        i++;
        len--;
        temp = temp / 10;
    }
    num < 0 ? at(i + 1) = '\0' : at(i) = '\0';
    reverse();
}

float String::toFloat() const
{
    float num = 0;
    bool negativeFlag = isNegativeNum(data);

    int i = 0;
    long long int integralPart = getNumberPart(data);
    int dotIndex = getDotIndex(data);
    long long int fractionalPart = dotIndex != -1? getNumberPart(data, dotIndex): 0;
    int divisor = getDivisor(numLength(fractionalPart));

    num = integralPart + (float)fractionalPart/divisor;
    if (negativeFlag)
    {
        num = num * -1;
    }
    return num;
}


String String::tokenzie(String receivedStr)
{
    if (!receivedStr.data)
    {
        return *this;
    }
    String str = *this;
    int i = 0;
    while (data[i] != '\0')
    {
        int j = 0;
        while (receivedStr.data[j] != '\0')
        {
            if (data[i] == receivedStr.data[j])
            {
                str.data[i] = '\n';
            }
            j++;
        }
        i++;
    }
    this->~String();
    return str;
}

void String::reverseWords()
{
    if (!data)
    {
        return;
    }
    int i = 0;
    for (int i = 0; i < getLength(); i++)
    {
        String s;
        while ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
        {
            String temp = data[i];
            s.insert(0, temp);
            i++;
        }
        remove(i - s.getLength(), s.getLength());
        insert(i - s.getLength(), s);
    }
}

void String::changeToNewCharSet(String cs)
{
    if (!data)
    {
        return;
    }
    int i = 0;
    while (data[i]!= '\0')
    {
        if (data[i] >='a' && data[i] <= 'z')
        {
            data[i] = cs.data[data[i] - 'a' - 1];
        }
        i++;
    }
}
