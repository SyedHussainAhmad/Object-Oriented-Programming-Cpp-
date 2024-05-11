#include"GenericDictionary.h"
#include"String.h"
int main()
{
	GenericDictionary<String, int> grocery;
	cout << "Grocery List";
	cout << "\n============\n";
	grocery.addPair("Oranges", 12);
	grocery.addPair("Apples", 18);
	grocery.addPair("Bananas", 78);
	grocery.addPair("Apricot", 316);
	grocery.print();

}