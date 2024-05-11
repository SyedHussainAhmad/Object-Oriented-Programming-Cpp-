#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include "String.h"

class Encryptor 
{
public:
    virtual String encrypt(const String& message) const = 0;
    virtual String decrypt(const String& cipher) const = 0;
};

#endif  // ENCRYPTOR_H

