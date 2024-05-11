#include "CaesarCipher.h"

//Private Functions:

char CaesarCipher::shiftChar(char c, int shift) const 
{
    char base = (c>= 'a' && c <= 'z') ? 'a' : 'A';
    return ((c - base + shift + 26) % 26) + base;
}

bool CaesarCipher::isAlphabet(char c) const 
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

CaesarCipher::CaesarCipher(int shift) : shift(shift) {}

String CaesarCipher::encrypt(const String& message) const 
{
    String result;
    for (int i = 0; i < message.getLength(); i++) {
        char c = message[i];
        if (isAlphabet(c)) 
        {
            result += shiftChar(c, shift);
        }
        else 
        {
            result += c;  
        }
    }
    return result;
}

String CaesarCipher::decrypt(const String& cipher) const 
{
    String result;
    for (int i = 0; i < cipher.getLength(); i++) 
    {
        char c = cipher[i];
        if (isAlphabet(c)) 
        {
            result += shiftChar(c, -shift);
        }
        else 
        {
            result += c;
        }
    }
    return result;
}
