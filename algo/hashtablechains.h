#pragma once

#include <cstdlib>
#include <list>

using namespace std;
typedef int (*HashFunction)();
typedef int T;

class HashTableChains 
{
private:
	list<T>* data;
	int size;
	int myHash(T elem);

public:
	HashTableChains(int size=0);
	~HashTableChains();
	void add(T elem);
	bool lookup(T elem);

};