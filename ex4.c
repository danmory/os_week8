#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    int totalMB = 10 * 1024 * 1024;
	int *data = NULL;
	size_t size = 0;
	struct rusage usage;
	printf("user CPU time:\tsystem CPU time:\tsoft page faults:\thard page faults:\tcontext switches:\n");
	
	for(int i=0; i<10; i++)
	{
		size += totalMB;
		data = realloc(data, size);
		memset(data, 0, size);  
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\t\t\t%ld\t\t\t%ld\t\t\t%ld\t\t\t%ld\n",
			usage.ru_utime.tv_usec,
			usage.ru_stime.tv_usec,
			usage.ru_minflt,
			usage.ru_majflt,
			usage.ru_nvcsw + usage.ru_nivcsw
		);
		sleep(1);
	}
	free(data);
	
	return 0;
}