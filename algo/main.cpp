#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"
#include "cuckootable.h"
#include <time.h>

bool wasGeneratedEarlier(int* data, int size, int elem)
{
	bool result = false;
	for (int i=0; i<size; i++)
	{
		if (data[i] == elem)
		{
			result = true;
			break;
		}
	}
	return result;
}



int main()
{
	srand(time(0));
	for (int j=0; j<5; j++)
	{
		printf("\n");
		int n = 6000;
		HashTableCuckoo table(10000);
		int* data = new int[n];
		for (int i=0; i<n; i++)
		{
			data[i] = INT_MAX;
		}
		for (int i=0; i<n; i++)
		{
			int elem = rand();
			while (wasGeneratedEarlier(data, n, elem))
				elem = rand();
			data[i] = elem;

			//data[i] = rand();
			table.add(data[i]);
			table.lookup(data[i]);
			//printf("%d", (int)table.lookup(data[i]));
		}	
		for (int i=0; i<n; i++)
		{
			table.remove(data[i]);
		}	
		table.printUsageDetails();

		delete[] data;
	}
	return 0;
}