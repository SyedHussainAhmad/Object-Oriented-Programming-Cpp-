#include"CaesarCipher.h"
#include"VigenereCipher.h"


int main()
{
    CaesarCipher caesar(3);

    String message = "HELLO";
    String encryptedMessage = caesar.encrypt(message);
    String decryptedMessage = caesar.decrypt(encryptedMessage);

    cout << "Caesar Cipher:" << endl;
    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encryptedMessage << endl;
    cout << "Decrypted message: " << decryptedMessage << endl;
    cout << endl;
	return 0;
}