// Numbers from command line arguments are sent to child process
// from parent process one at a time through pipe.
//
// Child process adds up numbers sent through pipe.
//
// Child process returns sum of numbers to parent process.
//
// Parent process prints sum of numbers.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         // for fork()
#include <sys/types.h>      // for pid_t
#include <sys/wait.h>       // for waitpid()

int main(int argc, char **argv)
{
	int fd[2]; //set up fork
	pid_t pid;

	pipe(fd);
	pid = fork(); //call fork

	printf("CS201 - Assignment 3 Premium - Evan Miller\n");

	if (pid == 0) 
		{
		// -- running in child process --
		int n, a[100], sum = 0;

		// Receive numbers from parent process via pipe
		// one at a time, and count them.

		read(fd[0], &n, sizeof(n));

		int i;
		
		for(i = 0; i < n; i++)
		{
			int y;

			read(fd[0], &y, sizeof(y));
			a[i] = y; // read then store value in array
		}
		for(i = 0; i < (n); ++i)
		{
			sum += a[i];
		}
		write(fd[1], &sum, sizeof(sum)); //sum to parent
		
		exit(0);
		}
	else {
		// -- running in parent process --
		int a[100], i, sum;
		
		if(argc<2)
		{
			printf("enter numbers: \n");
			return 0;
		}
		int n = atoi(argv[1]);
		
		for(i = 0; i < (n); i++)
		{
			a[i] = atoi(argv[i+2]);
		}
		write(fd[1], &n, sizeof(n));
		
		for(i = 0; i < n; i++)
		{
			int x = a[i];
			write(fd[1], &x, sizeof(x));
		}
		wait(NULL);

		read(fd[0], &sum, sizeof(sum));

		printf("sum = %d\n", sum);
		return 0;
		}
}
