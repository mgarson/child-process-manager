#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv)
{       
        printf("Hello from user.cpp, a new executable!\n");
	printf("My process id is: %d\n", getpid());
	printf("I have %d arguments: \n", argc);

	int i;
	for(i=0; i<argc; i++)
		printf("|%s| ", argv[i]);
	printf("\nChild is now ending\n");

	sleep(3);
        return EXIT_SUCCESS;
        
}       
                                                                               

