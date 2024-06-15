#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include"Encryptor.h"

class VigenereCipher : public Encryptor
{
private:
    String keyword;
    bool isAlphaChar(char ch) const;
    char shiftChar(char ch, int shift) const;

public:
    VigenereCipher(const String& keyword);
    void setKeyword(const String& newKeyword);
    String encrypt(const String& message) const override;
    String decrypt(const String& message) const override;
};

#endif // VIGENERECIPHER_H
