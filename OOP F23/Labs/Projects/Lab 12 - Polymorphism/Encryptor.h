#ifndef CIPHER_H
#include"String.h"
#include<iostream>
using namespace std;

class Encryptor
{
public:
    virtual String encrypt(const String& message) const = 0;
    virtual String decrypt(const String& message) const = 0;
};
#endif // !CIPHER_H
