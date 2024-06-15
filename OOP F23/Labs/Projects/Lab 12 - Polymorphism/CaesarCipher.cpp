#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int shift) : shift(shift) {}

void CaesarCipher::setShift(int newShift) 
{
    shift = newShift;
}

bool CaesarCipher::isAlphaChar(char ch) const 
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char CaesarCipher::shiftChar(char ch, int shift) const 
{
    char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
    return static_cast<char>((ch - base + shift) % 26 + base);
}

String CaesarCipher::encrypt(const String& message) const 
{
    String encryptedMessage = message;
    for (size_t i = 0; i < encryptedMessage.getLength(); i++) 
    {
        char& ch = encryptedMessage[i];
        if (isAlphaChar(ch)) 
        {
            ch = shiftChar(ch, shift);
        }
    }
    return encryptedMessage;
}

String CaesarCipher::decrypt(const String& cipher) const 
{
    String decryptedMessage = cipher;
    for (size_t i = 0; i < decryptedMessage.getLength(); i++) 
    {
        char& ch = decryptedMessage[i];
        if (isAlphaChar(ch)) 
        {
            ch = shiftChar(ch, -shift);
        }
    }
    return decryptedMessage;
}
