#pragma once

#include <cstdlib>
#include <list>

using namespace std;
typedef int (*HashFunction)();
typedef int T;

const int A = 3;
const int B = 19;
const int P = 227; //Please make sure it's more than size

class HashTableChains 
{
private:
	list<T>* data;
	int size;
	int myHash(T elem);
	list<T>::iterator findIter(T elem);

public:
	HashTableChains(int size=0);
	~HashTableChains();
	void add(T elem);
	bool lookup(T elem);
	void remove(T elem);
	void printUsageDetails();

};