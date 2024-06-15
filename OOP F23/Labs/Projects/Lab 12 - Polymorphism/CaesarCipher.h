#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include"Encryptor.h"

class CaesarCipher : public Encryptor
{
private:
    int shift;
    bool isAlphaChar(char ch) const;
    char shiftChar(char ch, int shift) const;

public:
    CaesarCipher(int shift);
    void setShift(int newShift);
    String encrypt(const String& message) const override;
    String decrypt(const String& message) const override;
};

#endif // CAESARCIPHER_H
