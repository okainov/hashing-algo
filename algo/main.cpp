#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include <list>

using namespace std;


template <typename T> class HashTableChains 
{
private:
	list<T>* data;
	int size;

public:
	HashTableChains(int size=0)
	{
		this->size = size;
		data = new list<T>[size];
	}
	~HashTableChains()
	{
		this->size = 0;
		delete[] data;
		data = NULL;
	}

};

int main()
{
	int n = 100;
	double* inputData = new double[n];
	for (int i=0; i<n; i++)
		inputData[i] = rand();

	HashTableChains<double> table;

	

	delete[] inputData;
	return 0;
}
