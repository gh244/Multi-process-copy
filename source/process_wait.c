#include <stdio.h>
#include <sys/types.h>
#include <wait.h>

int process_wait(void) {
	int zpid = wait(NULL);
	printf("process %d has already been recycled\n", zpid);
	return 0;	
}	
