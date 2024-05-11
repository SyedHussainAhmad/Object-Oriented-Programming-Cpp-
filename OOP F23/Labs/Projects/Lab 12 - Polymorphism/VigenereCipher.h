#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "Encryptor.h"

class VigenereCipher : public Encryptor 
{
private:
    int shift;
    char shiftChar(char c, int shift) const;
    bool isAlphabet(char c) const;
public:
    VigenereCipher(int shift);
    virtual String encrypt(const String& message) const override;
    virtual String decrypt(const String& cipher) const override;
};

#endif  // VIGENERECIPHER_H

