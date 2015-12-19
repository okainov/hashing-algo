#include "cuckootable.h"


void HashTableCuckoo::add( T elem )
{
	internalAdd(elem, 0);
}

HashTableCuckoo::HashTableCuckoo( int size/*=0*/ )
{
	this->size = size;
	data = new T[size];
	for (int i=0; i<size; i++)
		data[i] = INT_MAX; //empty indicator
	a1 = 3;
	b1 = 19;
	p1 = 35317;
	a2 = 7;
	b2 = 23;
	p1 = 33391;
}

int HashTableCuckoo::hash1( T elem )
{
	return ((a1*elem + b1) % p1) % size;
}

int HashTableCuckoo::hash2( T elem )
{
	return ((a2*elem + b2) % p2) % size;
}

void HashTableCuckoo::internalAdd( T elem, int deep )
{
	if (deep > MAX_DEEP)
		rehash();
	int ind1 = hash1(elem);
	int ind2 = hash2(elem);
	if (data[ind1] == INT_MAX) //empty
		data[ind1] = elem;
	else if (data[ind2] == INT_MAX) //empty
		data[ind2] = elem;
	else
	{
		T old_elem = data[ind2];
		data[ind2] = elem;
		internalAdd(old_elem, deep + 1);
	}

}

void HashTableCuckoo::rehash()
{
	printf ("Rehashing...\n");
	T* old_data = new T[size];
	memcpy(old_data, data, size*sizeof(T));

	a1 = rand() % (p1 - 1) + 1;
	b1 = rand() % p1;
	a2 = rand() % (p2 - 1) + 1;
	b2 = rand() % p2;


	for (int i = 0; i<size; i++)
		data[i] = INT_MAX;
	for (int i = 0; i<size; i++)
		if (old_data[i]!= INT_MAX)
			add(old_data[i]);
	delete[] old_data;
}

bool HashTableCuckoo::lookup( T elem )
{
	int ind1 = hash1(elem);
	int ind2 = hash2(elem);
	if (data[ind1] == elem || data[ind2] == elem)
		return true;
	else 
		return false;
}

void HashTableCuckoo::remove( T elem )
{
	int ind1 = hash1(elem);
	int ind2 = hash2(elem);
	if (data[ind1] == elem)
		data[ind1] = INT_MAX;
	else if (data[ind2] == elem)
		data[ind2] = INT_MAX;

}

void HashTableCuckoo::printUsageDetails()
{

}

HashTableCuckoo::~HashTableCuckoo()
{
	this->size = 0;
	delete[] data;
	data = NULL;
}
