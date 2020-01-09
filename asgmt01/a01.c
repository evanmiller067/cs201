// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextFloat()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "I. Forgot";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
}

// get next float using scanf()
// returns true (success) or false (failure)
// if call succeeded, return float value via fPtr
bool getNextFloat(float *fPtr)
{
    // replace this code with the call to scanf()
    *fPtr = 0.0;
    return true;
}

// print requested data for the given number
void printNumberData(float f)
{
	// replace this call to printf with your actual code
	printf("%f\n", f);
}

// do not change this function in any way
int main(int argc, char **argv)
{
	float	f;								// number currently being analyzed
	bool	validInput;						// was user input valid?

	printf("CS201 - A01 - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextFloat(&f);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(f);
		if (f == 0.0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
