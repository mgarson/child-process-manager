#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>
#include <string>
#include <cstring>

using namespace std;

//Structure to hold values for command line arguments
typedef struct
{
	int proc;	// Number of processes; default 1
	int simul;	// Number of simulatenous processes; default 1
	int iter;	// Number of iterations; default 1
	
} options_t;

// Method to print information on command line arguments
void print_usage(const char * app)
{
	fprintf (stdout, "usage: %s [-h] [-n proc] [-s simul] [-t iter]\n",\
			app);
	fprintf (stdout, "	proc is the number of total children to launch\n");
	fprintf (stdout, "	simul indicates how many children are to be allowed to run simultaneously\n");
	fprintf (stdout, "	iter is the number to pass to the user process\n");
}

int main(int argc, char *argv[])
{
	options_t options;

	//Set default values
	options.proc = 1;
	options.simul = 1;
	options.iter = 1;


	// Value to keep track of child iterations
	int count = 0;
	
	const char optstr[] = "hn:s:t:"; // options h, n, s, t
	char opt;
	
	

	// Parse command line arguments with getopt
	while ( ( opt = getopt (argc, argv, optstr ) ) != -1 )
	{
		switch ( opt )
		{
		case 'h':
			print_usage( argv[0] );
			return ( EXIT_SUCCESS );
		case 'n':
			// Check if n's argument starts with '-'
			if (optarg[0] == '-')
			{	
				// Check if next character starts with other option, meaning no argument given for n and another option given
				if(optarg[1] == 's' || optarg[1] == 't' || optarg[1] == 'h')
				{
					// Print error statement, print usage, and exit program
					fprintf(stderr, "Error! Option n requires an argument.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
				// Means argument is not another option, but is invalid input
				else
				{
					// Print error statement, print usage, and exit program
					fprintf(stderr, "Error! Invalid input.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
			}
			// Loop to ensure all characters in n's argument are digits
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					// If non digit is found, print error statement, print usage, and exit program
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
			}

			// Sets proc to optarg and breaks
			options.proc = atoi(optarg);
			break;

		case 's':
			// Checks if s's argument starts with '-'
			if (optarg[0] == '-')
			{
				// Checks if next character is character of other option, meaning no argument given for s and another option given
				if (optarg[1] == 'n' || optarg[1] == 't' || optarg[1] == 'h')
				{
					// Print error statement, print usage, and exit program
					fprintf(stderr, "Error! Option s requires an argument.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
				//Means argument is not another option, but is invalid input
				else
				{
					// Print error statement, print usage, and exit program
					fprintf(stderr, "Error! Invalid input.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
			}
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
			}
			options.simul = atoi(optarg);
			break;
		case 't':
			if (optarg[0] == '-')
			{
				if (optarg[1] == 'n' || optarg[1] == 's' || optarg[1] == 'h')
				{
					fprintf(stderr, "Error! Option t requires an argument.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
				else
				{
					fprintf(stderr, "Error! Invalid input.\n");
					print_usage(argv[0]);
					return EXIT_FAILURE;
				}
			}
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					return EXIT_FAILURE;
				}
			}
			options.iter = atoi(optarg);
			break;
		default:
			printf("Invalid option %c\n", optopt);
			print_usage(argv[0]);
			return EXIT_FAILURE;
		}
	}
	fprintf(stdout, "Amount of processes: %d\nAmount that are simultaneous: %d\nAmount of iterations: %d.\n", options.proc, options.simul, options.iter);
	string str = to_string(options.iter);
	char* arg = new char[str.length()+1];
	strcpy(arg, str.c_str());
	while (count < options.proc)
	{
		for (int i=0; i<options.simul; i++)
		{
			
			count++;
			cout << "count: " << count << endl;
			if (count > options.proc)
				break;

			pid_t childPid = fork();
	
			if (childPid == 0)
			{
				char* args[] = {"./user", arg, NULL};
				execvp(args[0], args);
				fprintf(stderr, "Exec failed, terminating!\n");
				exit(1);
			}
			else
			{
				waitpid(childPid, NULL, 0);
				printf("I'm a parent! My pid is %d, and my child's pid is %d.\n", getpid(), childPid);
			}
		}
		sleep(3);
	}
	printf("Parent is now ending. \n");
	return EXIT_SUCCESS;


}
