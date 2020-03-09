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
#include <unistd.h>

int main(int argc, char **argv)
{
	// set up pipe
	int fd[2];

	int x, y, z;

	pipe(fd);
	int pid = fork(); // call fork()

	printf("CS201 - Assignment 3 Regular - Evan Miller\n");

	if (pid == 0) {
		// -- running in child process --
		int sum = 0;
		
		read(fd[0], &x, sizeof(x));
		read(fd[0], &y, sizeof(y));
		read(fd[0], &z, sizeof(z));

		sum = (x+y+z);
		
		write(fd[1], &sum, sizeof(sum));
		close(fd[0]);
		close(fd[1]);

		// Return sum of numbers.
		return sum;
		}
	else {
		// -- running in parent process --
		int sum = x+y+z;
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		z = atoi(argv[3]);

		// Send numbers (datatype: int, 4 bytes) from command line arguments
		// starting with argv[1] one at a time through pipe to child process.
		write(fd[1], &x, sizeof(x));
		write(fd[1], &y, sizeof(y));
		write(fd[1], &z, sizeof(z));
	
		read(fd[0], &sum, sizeof(sum));
		
		printf("sum = %d\n", sum);
		
		close(fd[1]);
		close(fd[0]);		
		}

		return 0;
}
