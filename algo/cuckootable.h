#pragma once

#include <cstdlib>
#include <list>
#include "abstracthashtable.h"

using namespace std;



class HashTableCuckoo: public AbstractHashTable
{
private:
	T* data;
	int size;
	int MAX_DEEP;
	static const int primesSize = 40;
	int* primeNumbers;

	int hash1(T elem);
	int hash2(T elem);
	void rehash();

	void internalAdd(T elem, int deep);
	void generateHashes();

	int a1, b1, p1;
	int a2, b2, p2;
	int nAtomicOperations;
	int nBigOperations;

public:
	HashTableCuckoo(int size=0);
	virtual ~HashTableCuckoo();
	virtual void add(T elem);
	virtual bool lookup(T elem);
	virtual void remove(T elem);
	virtual void printUsageDetails();
};