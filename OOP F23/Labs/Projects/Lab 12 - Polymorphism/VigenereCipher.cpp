#include "VigenereCipher.h"

VigenereCipher::VigenereCipher(const String& keyword) : keyword(keyword) {}

void VigenereCipher::setKeyword(const String& newKeyword) 
{
    keyword = newKeyword;
}

bool VigenereCipher::isAlphaChar(char ch) const 
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char VigenereCipher::shiftChar(char ch, int shift) const 
{
    char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
    return static_cast<char>((ch - base + shift) % 26 + base);
}

String VigenereCipher::encrypt(const String& message) const 
{
    String encryptedMessage = message;
    int keywordLength = keyword.getLength();
    int keywordIndex = 0;
    for (size_t i = 0; i < encryptedMessage.getLength(); i++) 
    {
        char& ch = encryptedMessage[i];
        if (isAlphaChar(ch)) 
        {
            int shift = keyword[keywordIndex % keywordLength] - 'A';
            ch = shiftChar(ch, shift);
            keywordIndex++;
        }
    }
    return encryptedMessage;
}

String VigenereCipher::decrypt(const String& message) const 
{
    String decryptedMessage = message;
    int keywordLength = keyword.getLength();
    int keywordIndex = 0;
    for (size_t i = 0; i < decryptedMessage.getLength(); i++) 
    {
        char& ch = decryptedMessage[i];
        if (isAlphaChar(ch)) {
            int shift = keyword[keywordIndex % keywordLength] - 'A';
            ch = shiftChar(ch, -shift);
            keywordIndex++;
        }
    }
    return decryptedMessage;
}
