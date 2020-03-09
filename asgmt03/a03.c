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
	
	//printf("CS201 - Assignment 3 Regular - Evan Miller\n");

	if (pid == 0) {
		// -- running in child process --
		int sum = 0;	//sum of arg values
		int argIn = 0;	//to hold input before adding to sum, might not need

		//set up pipes for Child
		// Receive numbers from parent process via pipe
		// one at a time, and count them.

		for(int i = 1; i < argc; i++)
		{
			read(fd[0], &argIn, 4);
			sum = sum+argIn;
		}
		close(fd[1]); //close pipe

		// Return sum of numbers.
		return sum;
		}
	else {
		// -- running in parent process --
		
		int sum = 0;
		int out = 0;
		// Send numbers (datatype: int, 4 bytes) from command line arguments
		// starting with argv[1] one at a time through pipe to child process.
		
		for(int i = 1; i < argc; i++)
		{
			out = atoi(argv[i]);
			write(fd[1], &out, 4);
		}
		close(fd[1]);

		// Wait for child process to return. Reap child process.
		// Receive sum of numbers via the value returned when
		// the child process is reaped.
	
		pid = wait(&sum);
		sum = sum >> 8; //shift bits to avoid having to cast to (int)(static int)sum

		printf("CS201 - Assignment 3 Regular - Evan Miller\n");	
		printf("sum = %d\n", sum);
		return 0;
		}
}
