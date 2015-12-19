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

	if (this->findIter(elem) != data[index].end())
		return true;
	else
		return false;
}

int HashTableChains::myHash(T data)
{
	return ((A*data + B) % P) % size;
}

void HashTableChains::printUsageDetails()
{
	int min_size = size+1;
	int max_size = 0;
	int nOfElements = 0;
	for (int i=0; i<size; i++)
	{
		int current_size = data[i].size();
		nOfElements += current_size;
		if (max_size < current_size)
			max_size = current_size;
		if (min_size > current_size)
			min_size = current_size;		
	}
	printf("Max size: %d\nMin size: %d\nTotal elements: %d\nAverage size: %lf", max_size, min_size, nOfElements, (double)nOfElements/size);

}

void HashTableChains::remove( T elem )
{
	int index = myHash(elem);
	data[index].erase(this->findIter(elem));
}

list<T>::iterator HashTableChains::findIter( T elem )
{
	int index = myHash(elem);

	std::list<T>::iterator findIter = std::find(data[index].begin(), data[index].end(), elem);
	return findIter;
}
