#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv)
{
	if(argv[1] == nullptr) // Determines if first argument is null, meaning no value given for iter
  	{	
		// Program will perform a single iteration (default value).
		// Prints user's pid, parent pid, current iteration, and informs this is before sleeping
		printf("User PID: %d ", getpid());
		printf("PPID: %d ", getppid());
		printf("Iteration: 1 ");
		printf("before sleeping\n");

		// Sleeps for 1
		sleep(1);

		// Prints user's pid, parent pid, current iteration, and informs this is after sleeping
		printf("USER PID: %d ", getpid());
		printf("PPID: %d ", getppid());
		printf("Iteration: 1 ");
		printf("after sleeping\n");

	}
	
	else // Means argument given for iter
	{	
		// Changes argument to int and sets it to int iter
		int iter = atoi(argv[1]);

		// Loop to perform iterations up to iter
		while (iter > 0)
		{
			// Prints user's pid, parent pid, the current iteration, and informs it is before sleeping
			printf("USER PID: %d ", getpid());
			printf("PPID: %d ", getppid());
			printf("Iteration: %d ", iter);
			printf("before sleeping\n");
			
			// Sleeps for 1
			sleep(1);

			// Prints user's pid, parent pid, current iteration, and informs this is after sleeping
			printf("USER PID: %d ", getpid());
			printf("PPID: %d ", getppid());
			printf("Iteration: %d ", iter);
			printf("after sleeping\n");
			
			// Decrements iter to keep track of iterations performed
			iter--;
		}
	}

        return EXIT_SUCCESS;
        
}       
                                                                               

