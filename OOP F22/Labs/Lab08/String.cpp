#include"String.h"


istream& operator>>(istream& is, String& str)
{
    str.~String();
    str.input();
    return is;
}

ostream& operator<<(ostream& os, const String& str)
{
    str.display();
    return os;
}

int String::getStrLength(const char* ch) const
{
    int length = 0;

    while (ch != nullptr && ch[length] != '\0')
    {
        length++;
    }
    return length;
}

int String::compare(const String& str) const
{
    if (!str.data || !data)
    {
        return -2;
    }

    if (getLength() > str.getLength())
    {
        return 2;
    }

    if (getLength() < str.getLength())
    {
        return -1;
    }


    int i = 0;
    bool compareFlag = true;
    while (i < getLength() && compareFlag)
    {
        if (data[i] != str[i])
        {
            compareFlag = false;
        }
        i++;
    }
    return compareFlag;
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
        bool findFlag = true;
        while (j < lengthOfSubStr && findFlag)
        {
            if (data[i + j] != subStr[j])
            {
                findFlag = false;
            }
            j++;
        }
        if (findFlag)
        {
            return i;
        }
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
    *this = ref;
}

String & String::operator =(const String& ref)
{
    if (!ref.data)
    {
        return *this;
    }
    this->~String();
    *this += ref;
    return *this;
}

String::String(String&& r)
{
    data = r.data;
    size = r.size;
    r.data = 0;
    r.size = 0;
}

String& String::operator=(String&& rfs)
{
    data = rfs.data;
    size = rfs.size;
    rfs.data = 0;
    rfs.size = 0;
    return *this;
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
    int sizeOfStr = getStrLength(ch) + 1;
    if (sizeOfStr != 0)
    {
        data = new char[sizeOfStr];
        copyString(ch, data);
        size = sizeOfStr;
    }
}

String::~String()
{
    if (!data)
    {
        return;
    }
    delete[] data;
    data = nullptr;
    size = 0;
}

int String::getSize() const
{
    return size;
}


int String::getLength() const
{
    return getStrLength(data);
}

char& String::operator[](int index)
{
    return data[index];
}
const char& String::operator[](const int index) const
{
    return data[index];
}

int String::find(const String& subStr, const int start) const
{
    int count = 0;
    int length = getLength();
    int lengthOfSubStr = subStr.getLength();

    for (int i = 0; i <= length - lengthOfSubStr; i++) 
    {
        int j = 0;
        while (j < lengthOfSubStr)
        {
            if (data[i + j] != subStr[j])
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
    if (!*this)
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
    if (!*this)
    {
        return;
    }

    int i = getLength() - 1;
    while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
    {
        i--;
    }
    data[i] = '\0';
    shrink();
}

void String::trim()
{
    trimLeft();
    trimRight();
}

void String::insert(const int index, const String & subStr)
{
    if ((!*this || getLength() == 0) && index == 0)
    {
        *this = subStr;
    }

    int subStrLength = subStr.getLength();
    int strLength = getLength();
    if (index<0 || index > strLength)
    {
        return;
    }

    int newSize = strLength + subStrLength + 1;
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
    if (index + count >= lengthOfCurr)
    {
        data[index] = '\0';
        shrink();
        return;
    }
    if (index < 0 || index >= lengthOfCurr || lengthOfCurr == 0 || !*this)
    {
        return;
    }
    else
    {
        copyString(&data[index + count], &data[index]);
    }
}

int String::replace(const String& old, const String& newSubStr)
{
    if (old.data == nullptr || newSubStr.data == nullptr)
    {
        return 0;
    }

    int occurances = find(old);
    if (occurances <= 0 )
    {
        return 0;
    }

    int i = 1;
    int newSubLen = newSubStr.getLength();
    int index = 0;

    while (i <= occurances)
    {
        index = findIndex(index, old);
        remove(index, old.getLength());

        insert(index, newSubStr);
        index += newSubLen;
        i++;
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
            data[i] = data[i] - 'a' + 'A';
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
            data[i] = data[i] - 'A' + 'a';
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
    if (!*this)
    {
        copyString(data, temp);
    }
    this->~String();
    data = temp;
    size = newSize;
}

void String::shrink()
{
    int newSize = getLength() + 1;
    reSize(newSize);
}


String String::left(const int count)
{
    if (!data || count > getLength())
    {
        return *this;
    }
    String str = *this;
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
    str.size = count;
    str.data = new char[str.size];
    int len = getLength();
    copyString(&data[len - count], str.data);
    str.shrink();
    return str;
}

String::operator long long int() const
{
    long long int integralValue = 0;
    if (!*this)
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
    return  negativeFlag ? integralValue * -1 : integralValue;
}

String String::operator+(const String& s2) const
{
    String str = *this;
    str += s2;
    return str;
}

void String::operator+=(const String& s2)
{
    if (!s2)
        return;
    int len = getLength();
    int s2Len = s2.getLength();
    reSize(len + s2Len + 1);
    copyString(s2.data, &data[len]);
}

String& String::operator = (const long long int num)
{
    String s;
    int len = numLength(num);
    long long int temp = num;
    int i = 0;
    if (temp < 0)
    {
        s.reSize(len + 2);
        s[len] = '-';
        temp = temp * -1;
    }
    else
    {
        s.reSize(len + 1);
    }
    while (len > 0)
    {
        int rem = temp % 10;
        s[i] = rem + '0';
        i++;
        len--;
        temp = temp / 10;
    }
    num < 0 ? s[i + 1] = '\0' : s[i] = '\0';
    s.reverse();
    return s;
}

String::operator double () const
{
    double num = 0;
    bool negativeFlag = isNegativeNum(data);

    int i = 0;
    long long int integralPart = getNumberPart(data);
    int dotIndex = getDotIndex(data);
    long long int fractionalPart = dotIndex != -1 ? getNumberPart(data, dotIndex) : 0;
    int divisor = getDivisor(numLength(fractionalPart));

    num = integralPart + (float)fractionalPart / divisor;
    if (negativeFlag)
    {
        num = num * -1;
    }
    return num;
}

String String::operator () (const String& delim)
{
    if (!delim.data)
    {
        return *this;
    }
    String str = *this;
    int i = 0;
    while (data[i] != '\0')
    {
        int j = 0;
        while (delim.data[j] != '\0')
        {
            if (data[i] == delim.data[j])
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


String::operator bool() const
{
	return !(!(*this));
}

int String::operator ==(const String& s2) const
{
	return (compare(s2));
}

bool String::operator>(const String& s2) const
{
	return (compare(s2) == 2);
}

bool String::operator<(const String& s2) const
{
	return (compare(s2) == -1);
}

bool String::operator>=(const String& s2) const
{
	return ((compare(s2) == 1) || (compare(s2) == 2));
}

bool String::operator<=(const String& s2) const
{
	return ((compare(s2) == 1) || (compare(s2) == -1));
}

bool String::operator!=(const String& s2) const
{
	return (compare(s2) == 0);
}