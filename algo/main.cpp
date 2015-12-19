#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"


int main()
{
	int n = 100;
	double* inputData = new double[n];
	HashTableChains table(n);

	for (int i=0; i<n; i++)
	{
		table.add(i);
		printf("%d", (int)table.lookup(i));
	}	

	delete[] inputData;
	return 0;
}
