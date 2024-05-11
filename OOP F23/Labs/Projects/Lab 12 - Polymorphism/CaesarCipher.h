#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "String.h"
#include "Encryptor.h"

class CaesarCipher : public Encryptor
{
    int shift;
    char shiftChar(char c, int shift) const;
    bool isAlphabet(char c) const;
public:
    CaesarCipher(int shift);
    String encrypt(const String& message) const override;
    String decrypt(const String& cipher) const override;

};

#endif  // CAESAR_CIPHER_H
