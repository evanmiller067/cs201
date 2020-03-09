// Numbers from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process adds up numbers sent through pipe.
//
// Child process returns sum of numbers to parent process.
//
// Parent process prints sum of numbers.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>         // for fork(), sleep(), pipe()
#include <sys/wait.h>       // for waitpid()
#include <sys/types.h>		// for pid_t
static int fd[2];

int main(int argc, char **argv)
{
	
	pid_t pid;

	// set up pipe, with pipe error check
	if (pipe(fd))
	{
		printf("Pipe error\n");
		return -1;
	}
	// call fork(), with error check
	pid = fork();
	
	if(pid < 0)
	{
		printf("fork error %d\n", pid);
		return -1;
	}
	
	//printf("CS201 - Assignment 3 Premium - Evan Miller\n");

	if (pid == 0) {
		// -- running in child process --
		int sum = 0;	//sum of arg values
		int argIn = 0;	//to hold input before adding to sum, might not need
		int signBit = 0; //for handling positive/negative values

		//set up pipes for Child
		// Receive numbers from parent process via pipe
		// one at a time, and count them.

		for(int i = 1; i < argc; i++)
		{
			read(fd[0], &argIn, 4);
			sum = sum+argIn;
		}
		//for prem version test for sign, multiply by (-1) to keep neg value with atoi.
		if(sum < 0)
		{
			signBit = 1; //if sum is a neg value set sign bit to 0
			sum = (sum *-1);
			write(fd[1], &signBit, 4); // send signBit value to parent to test
		}
		else//same as above but for positive values
		{
			signBit = 0;
			write(fd[1], &signBit, 4);
		}
		close(fd[1]); //close pipe

		// Return sum of numbers.
		return sum;
		}
	else {
		// -- running in parent process --
		
		int sum = 0;
		int out = 0;
		int signBit = 0;//default to positive values
		
		// Send numbers (datatype: int, 4 bytes) from command line arguments
		// starting with argv[1] one at a time through pipe to child process.
		
		for(int i = 1; i < argc; i++)
		{
			out = atoi(argv[i]);
			write(fd[1], &out, 4);
		}
		pid = wait(&sum);//wait for child to send sum, check for signBit
		read(fd[0], &signBit, 4);

		close(fd[1]);

		// Wait for child process to return. Reap child process.
		// Receive sum of numbers via the value returned when
		// the child process is reaped.
		
		//shift sum values instead of casting (int)(signed char)sum, should be faster? Due to Negative values?	
		
		sum = sum >> 8;

		printf("CS201 - Assignment 3 Premium - Evan Miller\n");	
		//printf("sum = %d\n", sum);

		//prem version, test for signBit

		if(signBit == 0)
		{
			printf("sum = %d\n", sum);
		}
		if(signBit == 1)
		{
			sum = (sum *-1);
			printf("sum = %d\n", sum);
		}

		return 0;
		}
}
