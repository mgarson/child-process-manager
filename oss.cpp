#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void print_usage(const char * app)
{
	fprintf (stderr, "usage: %s [-h] [-n proc] [-s simul] [-t iter]\n",\
			app);
	fprintf (stderr, "	proc is the number of total children to launch\n");
	fprintf (stderr, "	simul indicates how many children are to be allowed to run simultaneously\n");
	fprintf (stderr, "	iter is the number to pass to the user process\n");
}

int main(int argc, char *argv[])
{
	const char optstr[] = "hn:s:t:"; // options h, n, s, t
	char opt;
	int numChild;

	while ( ( opt = getopt (argc, argv, optstr ) ) != -1 )
	{
		switch ( opt )
		{
		case 'h':
			print_usage( argv[0] );
			return ( EXIT_SUCCESS );
		case 'n':
			numChild = atoi(optarg);
			cout << optarg << " set as n"<<endl;
			break;
		case 's':
			break;
		case 't':
			break;
		default:
			printf("Invalid option %c\n", optopt);
			print_usage(argv[0]);
			return EXIT_FAILURE;
		}
	}

	cout << "optind is: " << optind << endl;

	printf("List of parameters:\n");
	/*for (int i=optind; i<argc; i++)
	{
		printf("Parameter %d: %s\n", i - optind + 1, argv[i]);
	}*/
	if (optind < argc)
	{
		for (int i = optind; i<argc; i++)
			printf("parameter %d: %s\n", i-optind+1, argv[i]);
	}
	else printf("no additional parameters.\n");
	return EXIT_SUCCESS;


}
