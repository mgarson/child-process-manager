#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv)
{ 
	if(argv[1] == nullptr)
  	{	
		printf("Iterations: 1\n");

		printf("User PID: %d ", getpid());
		printf("PPID: %d ", getppid());
		printf("Iteration: 1 ");
		printf("before sleeping\n");

		sleep(1);

		printf("USER PID: %d ", getpid());
		printf("PPID: %d ", getppid());
		printf("Iteration: 1 ");
		printf("after sleeping\n");

	}
	
	else
	{	
		int iter = atoi(argv[1]);
		while (iter > 0)
		{
			printf("USER PID: %d ", getpid());
			printf("PPID: %d ", getppid());
			printf("Iteration: %d ", iter);
			printf("before sleeping\n");

			sleep(1);

			printf("USER PID: %d ", getpid());
			printf("PPID: %d ", getppid());
			printf("Iteration: %d ", iter);
			printf("after sleeping\n");
		
			iter--;
		}
	}

	printf("\nChild is now ending\n");
	
        return EXIT_SUCCESS;
        
}       
                                                                               

