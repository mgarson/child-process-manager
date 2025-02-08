#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>
#include <string>
#include <cstring>

using namespace std;

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
	const char optstr[] = "hn:s:t:"; // options h, n, s, t
	char opt;
	string str;
	int proc = 0;
	int simul = 0;
	int iter = 0;
	int count = 0;


	while ( ( opt = getopt (argc, argv, optstr ) ) != -1 )
	{
		switch ( opt )
		{
		case 'h':
			print_usage( argv[0] );
			return ( EXIT_SUCCESS );
		case 'n':
			if (optarg == NULL)
			{
				fprintf(stderr, "Error! Option n needs to have a number");
				return EXIT_FAILURE;
			}
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					return EXIT_FAILURE;
				}
			}
			proc = atoi(optarg);
			cout << proc << " set as n"<<endl;
			break;
		case 's':
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					return EXIT_FAILURE;
				}
			}
			simul = atoi(optarg);
			cout << simul << " set as s" << endl;
			break;
		case 't':
			for(int i = 0; optarg[i] != '\0'; i++)
			{
				if (!isdigit(optarg[i]))
				{
					fprintf(stderr, "Error! %s is not a valid number.\n", optarg);
					return EXIT_FAILURE;
				}
			}
			iter = atoi(optarg);
			cout << iter << " set as t" << endl;
			break;
		default:
			printf("Invalid option %c\n", optopt);
			print_usage(argv[0]);
			return EXIT_FAILURE;
		}
	}

	str = to_string(iter);
	char* arg = new char[str.length()+1];
	strcpy(arg, str.c_str());
	while (count < proc)
	{
		for (int i=0; i<simul; i++)
		{
			
			count++;
			cout << "count: " << count << endl;
			if (count > proc)
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
