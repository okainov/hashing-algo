#include "cuckootable.h"
#include "math.h"

HashTableCuckoo::HashTableCuckoo( int size/*=0*/ )
{
	this->size = size;
	data = new T[size];
	for (int i=0; i<size; i++)
		data[i] = INT_MAX; //empty indicator

	primeNumbers = new int[primesSize];
	//Pretty random P's
	primeNumbers[0]=99551;primeNumbers[1]=99559;primeNumbers[2]=99563;primeNumbers[3]=99571;primeNumbers[4]=99577;
	primeNumbers[5]=99581;primeNumbers[6]=99607;primeNumbers[7]=99611;primeNumbers[8]=99623;primeNumbers[9]=99643;
	primeNumbers[10]=99661;primeNumbers[11]=99667;primeNumbers[12]=99679;primeNumbers[13]=99689;primeNumbers[14]=99707;
	primeNumbers[15]=99709;primeNumbers[16]=99713;primeNumbers[17]=99719;primeNumbers[18]=99721;primeNumbers[19]=99733;		
	primeNumbers[20]=99761;primeNumbers[21]=99767;primeNumbers[22]=99787;primeNumbers[23]=99793;primeNumbers[24]=99809;
	primeNumbers[25]=99817;primeNumbers[26]=99823;primeNumbers[27]=99829;primeNumbers[28]=99833;primeNumbers[29]=99839;
	primeNumbers[30]=99859;primeNumbers[31]=99871;primeNumbers[32]=99877;primeNumbers[33]=99881;primeNumbers[34]=99901;
	primeNumbers[35]=99907;primeNumbers[36]=99923;primeNumbers[37]=99929;primeNumbers[38]=99961;primeNumbers[39]=99971;

	//Not really random P's
	//for (int i=0; i<primesSize; i++)
	//	primeNumbers[i] = 35317;

	generateHashes();
	MAX_DEEP = int(3*logf(size));
	nBigOperations = nAtomicOperations = 0;
}

int HashTableCuckoo::hash1( T elem )
{
	return ((a1*elem + b1) % p1) % size;
}

int HashTableCuckoo::hash2( T elem )
{
	return ((a2*elem + b2) % p2) % size;
}

void HashTableCuckoo::add( T elem)
{
	nBigOperations++; 
	bool ElemAdded = false;
	int deep = 0;
	while (!ElemAdded)
	{
		nAtomicOperations += 2;
		if (deep > MAX_DEEP)
		{
			rehash();
			deep = 0;
		}
		int ind1 = hash1(elem);
		int ind2 = hash2(elem);
		if (data[ind1] == INT_MAX) //empty
		{
			data[ind1] = elem;
			ElemAdded = true;
			break;
		}
		else if (data[ind2] == INT_MAX) //empty
		{
			data[ind2] = elem;
			ElemAdded = true;
			break;
		}
		else
		{
			T old_elem = data[ind2];
			data[ind2] = elem;
			elem = old_elem;			
		}
		deep++;
	}

}

void HashTableCuckoo::rehash()
{
	nAtomicOperations += size; //O(n)
	//printf ("Rehashing...\n");
	T* old_data = new T[size];
	memcpy(old_data, data, size*sizeof(T));

	generateHashes();

	for (int i = 0; i<size; i++)
		data[i] = INT_MAX;
	for (int i = 0; i<size; i++)
	{
		if (old_data[i] != INT_MAX)
			add(old_data[i]);
	}
	delete[] old_data;
}

bool HashTableCuckoo::lookup( T elem )
{
	nBigOperations++; 
	nAtomicOperations += 2; //O(1)
	int ind1 = hash1(elem);
	int ind2 = hash2(elem);
	if (data[ind1] == elem || data[ind2] == elem)
		return true;
	else 
		return false;
}

void HashTableCuckoo::remove( T elem )
{
	nBigOperations++; 
	nAtomicOperations += 2; //O(1)
	int ind1 = hash1(elem);
	int ind2 = hash2(elem);
	if (data[ind1] == elem)
		data[ind1] = INT_MAX;
	else if (data[ind2] == elem)
		data[ind2] = INT_MAX;

}

void HashTableCuckoo::printUsageDetails()
{
	printf("# Operations: %d\n# atomic operations: %d", 
		nBigOperations, nAtomicOperations);

}

HashTableCuckoo::~HashTableCuckoo()
{
	this->size = 0;
	delete[] data;
	data = NULL;

	delete[] primeNumbers;
	primeNumbers = NULL;
}

void HashTableCuckoo::generateHashes()
{
	int prime_indicator = rand() % primesSize;
	p1 = primeNumbers[prime_indicator];
	prime_indicator = rand() % primesSize;
	p2 = primeNumbers[prime_indicator];

	a1 = rand() % (p1 - 1) + 1;
	b1 = rand() % p1;
	a2 = rand() % (p2 - 1) + 1;
	b2 = rand() % p2;
}
