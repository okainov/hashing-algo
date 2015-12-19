#pragma once

#include <cstdlib>
#include <list>
#include "abstracthashtable.h"

using namespace std;

const int A = 3;
const int B = 19;
const int P = 35317; //Please make sure it's more than size

class HashTableChains: public AbstractHashTable
{
private:
	list<T>* data;
	int size;
	int myHash(T elem);
	list<T>::iterator findIter(T elem);

public:
	HashTableChains(int size=0);
	virtual ~HashTableChains();
	virtual void add(T elem);
	virtual bool lookup(T elem);
	virtual void remove(T elem);
	virtual void printUsageDetails();

};