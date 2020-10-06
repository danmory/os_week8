#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int totalMB = 10 * 1024 * 1024;
	int *data = NULL;
	size_t size = 0;
	for(int i=0; i<10; i++)
	{
		size += totalMB;
		data = realloc(data, size);
		memset(data, 0, size);
		sleep(1);
	}
	
	free(data);
	
	return 0;
}

/* 
* EXERCISE 2
* si = 0 
* so = 0 
* It means that there are always available space in the main memory, 
* so,data do not move from main memory to swap space.
*/

/* 
* EXERCISE 3
* When process is not sleeping it is in the list of active processes, and
* when process is sleeping then it is not
*/