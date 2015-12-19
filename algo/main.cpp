#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"
#include "cuckootable.h"


int main()
{
	int n = 60;
	HashTableCuckoo table(100);
	int number;
	for (int i=0; i<n; i++)
	{
		number = rand();
		table.add(number);
		printf("%d", (int)table.lookup(number));
	}	
	table.printUsageDetails();

	return 0;
}
