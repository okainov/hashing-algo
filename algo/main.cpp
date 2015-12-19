#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"
#include "cuckootable.h"
#include <time.h>


int main()
{
	srand(time(0));
	for (int j=0; j<5; j++)
	{
		printf("\n");
		int n = 2000;
		HashTableCuckoo table(10000);
		int number;
		int* data = new int[n];
		for (int i=0; i<n; i++)
		{
			data[i] = rand();
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