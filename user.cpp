#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv)
{       
	int iter = atoi(argv[1]);

	printf("USER PID: %d ", getpid());
	printf("PPID: %d ", getppid());
	printf("Iteration: %d ", iter);
	printf("before sleeping\n");

	sleep(1);

	printf("USER PID: %d ", getpid());
	printf("PPID: %d ", getppid());
	printf("Iteration: %d ", iter);
	printf("after sleeping\n");

	printf("\nChild is now ending\n");
	
        return EXIT_SUCCESS;
        
}       
                                                                               

