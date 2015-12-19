#include "hashtablechains.h"
#include <algorithm>


HashTableChains::HashTableChains(int size/* =0 */)
{
	this->size = size;
	data = new list<T>[size];
}

HashTableChains::~HashTableChains()
{
	this->size = 0;
	delete[] data;
	data = NULL;
}

void HashTableChains::add( T elem )
{
	int index = myHash(elem);
	printf("Inserting into %d\n", index);
	data[index].push_back(elem);

}

bool HashTableChains::lookup( T elem )
{
	int index = myHash(elem);

	std::list<T>::iterator findIter = std::find(data[index].begin(), data[index].end(), elem);
	if (findIter != data[index].end())
		return true;
	else
		return false;

}

int HashTableChains::myHash(T data)
{
	int a = 3;
	int b = 19;
	int p = 227;
	return ((a*data + b) % p) % size;
}
