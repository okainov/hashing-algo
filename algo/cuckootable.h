#pragma once

#include <cstdlib>
#include <list>
#include "abstracthashtable.h"

using namespace std;

const int MAX_DEEP = 10; //Should be near log(size)

class HashTableCuckoo: public AbstractHashTable
{
private:
	T* data;
	int size;

	int hash1(T elem);
	int hash2(T elem);
	void rehash();

	void internalAdd(T elem, int deep);

	int a1, b1, p1;
	int a2, b2, p2;

public:
	HashTableCuckoo(int size=0);
	virtual ~HashTableCuckoo();
	virtual void add(T elem);
	virtual bool lookup(T elem);
	virtual void remove(T elem);
	virtual void printUsageDetails();
};