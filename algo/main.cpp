#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"
#include "cuckootable.h"


int main()
{
	int n = 990;
	HashTableCuckoo table(1000);

	for (int i=0; i<n; i++)
	{
		table.add(i);
		printf("%d", (int)table.lookup(i));
	}	
	table.printUsageDetails();

	return 0;
}
