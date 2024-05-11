#include<iostream>
#include"BigNumber.h"
using namespace std;

int BigNumber::getStartingZeros(const char* number)
{
	int startingZeroes = 0;
	while (number[startingZeroes] == '0')       //for calculating zeroes at start
		startingZeroes++;

	return startingZeroes;
}

void BigNumber::copyStr(const char* src, char* dest)
{
	if (src == nullptr)
	{
		return;
	}
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
int BigNumber::getStrLength(const char* ch)
{
	int i = 0;
	if (ch == nullptr)
	{
		return 0;
	}
	while (ch[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
BigNumber::BigNumber(const char* input)
{
	if (input == nullptr || getStrLength(input) == 0)  // for nullptr and empty 
	{
		number = new char[2];
		number[0] = '0';
		number[1] = '\0';
		numberLength = 1;
	}
	else
	{
		numberLength = getStrLength(input);
		number = new char[numberLength + 1];
		copyStr(input, number);
	}
}
BigNumber::BigNumber(const BigNumber& ref)
{
	numberLength = ref.numberLength;
	number = new char[numberLength + 1];
	copyStr(ref.number, number);
}
BigNumber::~BigNumber()
{
	delete[] number;
	number = nullptr;
	numberLength = 0;
}
void BigNumber::print()
{
	cout << number;
}
Comparison BigNumber::compare(BigNumber ref)
{						 
	
	// handling length if zeroes are at start
	int startingZeroes = getStartingZeros(number);
	int startingZeroes2 = getStartingZeros(ref.number);


	if (ref.numberLength - startingZeroes2 < numberLength - startingZeroes)
		return LARGE;
	else if (ref.numberLength - startingZeroes2 > numberLength - startingZeroes)
		return SMALL;


	while (startingZeroes < numberLength && startingZeroes2 < ref.numberLength)
	{
		if (ref.number[startingZeroes2] > number[startingZeroes])
			return SMALL;
		else if (ref.number[startingZeroes2] < number[startingZeroes])
			return LARGE;
		startingZeroes++;
		startingZeroes2++;
	}
	return EQUAL;
}
BigNumber BigNumber::add(BigNumber other)
{

	int largeLength = (numberLength >= other.numberLength) ? numberLength : other.numberLength;               // finding large length

	char* result = new char[largeLength + 2]; // 1 extra for potential carry
	result[largeLength + 1] = '\0';
	int carry = 0;
	int k = largeLength;
	for (int i = numberLength - 1, j = other.numberLength - 1; i >= 0 || j >= 0; i--, j--, k--)
	{
		int digit1 = (i >= 0) ? (number[i] - '0') : 0;
		int digit2 = (j >= 0) ? (other.number[j] - '0') : 0;
		int res = digit1 + digit2 + carry;
		carry = res / 10;
		result[k] = (res % 10) + '0';
	}
	// handling last carry
	if (carry)
	{
		int startingZeros = getStartingZeros(result);
		result[startingZeros] = '1';
		BigNumber sum(result + startingZeros);
		delete[] result;
		return sum;
	}
	else
	{	
		//if last carry is 0, than 0 index not copied
		int startingZeros = getStartingZeros(result);
		BigNumber sum(result + startingZeros + 1);
		delete[] result;
		return sum;
	}
}
