#include "stdio.h"
#include "math.h"
#include <cstdlib>
#include "hashtablechains.h"


int main()
{
	int n = 300;
	HashTableChains table(100);

	for (int i=0; i<n; i++)
	{
		table.add(i);
		if (i%2 == 0)
			table.remove(i);
		printf("%d", (int)table.lookup(i));
	}	
	table.printUsageDetails();

	return 0;
}
