#include"GenericDictionary.h"

template<typename T, typename R>
void GenericDictionary<T, R>::reSize()
{
	capacity = capacity * 2;
	DictionaryPair <T, R>* temp = new DictionaryPair <T, R>[capacity+1];

	for (int i = 0; i < noOfItems; i++)
	{
		temp[i] = data[i];
	}
	this->~GenericDictionary();
	data = temp;
}

template<typename T, typename R>
int GenericDictionary<T, R>::keyIndex(T k)
{
	if (!data)
	{
		return -1;
	}
	bool findFlag = false;
	int i = 0;
	while (i < noOfItems && !findFlag)
	{
		if (data[i].getKey() == k)
		{
			findFlag = true;
		}
		i++;
	}
	return (findFlag ? i - 1 : -1);
}

template<typename T, typename R>
GenericDictionary<T, R>::GenericDictionary() : noOfItems(0), capacity(0)
{
	data = nullptr;
}

template<typename T, typename R>
GenericDictionary<T, R>::~GenericDictionary()
{
	delete data;
	noOfItems = 0;
	capacity = 0;
}

template<typename T, typename R>
void GenericDictionary<T, R>::addPair(T k, R v)
{
	if (isFull())
	{
		reSize();
	}

	int keyAdress = keyIndex(k);
	if (keyAdress != -1)
	{
		data[keyAdress].setValue(v);
	}
	else
	{
		data[noOfItems] = DictionaryPair<T, R>{ k,v };
		noOfItems++;
	}
}

template<typename T, typename R>
R GenericDictionary<T, R>::getValue(T k)
{
	int index = keyIndex(k);
	if (index != -1)
	{
		return data[index].getValue();
	}
	else
	{
		exit(0);
	}
}

template<typename T, typename R>
void GenericDictionary<T, R>::print()
{
	for (int i = 0; i < noOfItems; i++)
	{
		//cout << data[i].getKey();
		cout << '\t';
		cout << data[i].getValue();
		cout << '\n';
	}
}

template<typename T, typename R>
bool GenericDictionary<T, R>::isFull()
{
	return (capacity == noOfItems);
}

template<typename T, typename R>
bool GenericDictionary<T, R>::isEmpty()
{
	return (!data || data == nullptr);
}
