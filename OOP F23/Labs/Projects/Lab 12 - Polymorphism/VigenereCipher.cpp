#include "VigenereCipher.h"

//Private Functions:

char VigenereCipher::shiftChar(char c, int shift) const
{
    return c+shift;
}

bool VigenereCipher::isAlphabet(char c) const
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

VigenereCipher::VigenereCipher(int shift) : shift(shift) {}

String VigenereCipher::encrypt(const String& message) const
{
    String result;
    for (int i = 0; i < message.getLength(); i++) {
        char c = message[i];
        if (isAlphabet(c))
        {
            result += c;
        }
        else
        {
            result += shiftChar(c, shift);
        }
    }
    return result;
}

String VigenereCipher::decrypt(const String& cipher) const
{
    String result;
    for (int i = 0; i < cipher.getLength(); i++)
    {
        char c = cipher[i];
        if (isAlphabet(c))
        {
            result += c;
        }
        else
        {
            result += shiftChar(c, -shift);
        }
    }
    return result;
}
