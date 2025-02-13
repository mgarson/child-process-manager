Project 1: Launching Child Processes
Author: Maija Garson
Date: 02/13/2025

Description:
This project will compile two programs into two executables using the makefile provided. One of the executables, oss, is generated from oss.cpp.
The other executable, user, is generated from user.cpp. The oss program launches the user program as its child up to a specified amount of times.
The child processes run simultaneously up to a specified amount of times. The child process will also do a specified amount of iterations before ending.

Compilation:
Compile these programs using make. In the command line it should look like:
make

Running the Program:
Once compiled, the oss program can be run with 4 options that are optional:
oss [-h] [-n proc] [-s simul]
Where
	-h: Display help message
	-n proc: Proc represents the amount of total child processes to launch
	-s simul: Simul represents the amount of child processes that can run simultaneously
	-t iter: Iter represents the amount of iterations that each child process will perform before terminating
Default values for options n, s, and t will be 1 if they are not specified in the command line.

Problems Encountered:
Managing Simultaneous Child Processes
	The biggest challenge that I encountered was getting the child processes to run simultaneously while also ensuring that the parent process
	did not end prematurely. At first, I was only able to get the program to terminate successfully by putting sleep(3) at the end of the while
	loop for total processes. At this point, the child processes were not being created at the same time. I printed timestamps for each child, and 
	it would show them being created at different times. I then was able to get the children to run simultaneously without the parent ending early
	by adding an additional check to the while loop for total processes. This check ensured that there were no other processes currently running
	when leaving the loop. After this, the child processes run simulaneously up to the specified amount, and there is no premature termination.
Parsing Command Line Options
	Another challenge I faced was ensuring that command line options were handled correctly. After adding the check to ensure arguments given to 
	the options were integers, the program would not print the correct statement if no argument was given for an option. It seemed that the program
	would take in the next option as the argument for the previous options. For example, if I was to put "./oss -n -s 3", the error message that 
	would print would be something like, "Error, -s is not a valid number". I was able to fix this by adding a check to see if "-" was the next char	after an option. This caused the correct error message to be printed for this situation.
