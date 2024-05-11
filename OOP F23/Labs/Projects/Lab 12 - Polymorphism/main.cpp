#include"VigenereCipher.h"
#include<iostream>
using namespace std;

int main()
{
	VigenereCipher g{2};
	g.encrypt("45%").display();
	return 0;
}