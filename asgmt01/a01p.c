// do not change this code except in the following ways:
//   * write code for the following functions:
//      * bigOrSmallEndian()
//      * getNextHexInt()
//      * printNumberData()
//   * change studentName by changing "I. Forgot" to your actual name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char *studentName = "Evan Miller";

// report whether machine is big or small endian
void bigOrSmallEndian()
{
	int num = 0x01234567;
	char* printNum = (char*) &num;

	if(*printNum == 0x67)
	{
		printf("byte order: little-endian");
	}
	else
	{
		printf("byte order: big-endian");
	}
}
// get next int (entered in hex) using scanf()
// returns true (success) or false (failure)
// if call succeeded, return int value via iPtr
bool getNextHexInt(unsigned int *iPtr)
{
	*iPtr = 0;
	if(scanf("%X", iPtr)==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// print requested data for the given number
void printNumberData(int i)
{
	int signBit = i & 0x80000000;
	int expBits = i & 0x7f800000;
	int fractBits = i & 0x007fffff;

	expBits = expBits >> 23;

	if(signBit != 0)
	{
		signBit = 1;
	}
	printf("signBit %i, ", signBit);
	printf("expBits %3i, ", expBits);
	printf("fractBits 0x%08X\n", fractBits);

	if(expBits == 0 && fractBits == 0)
	{
		if(signBit == 0)
		{
			printf("+zero\n");
		}
		else
		{
			printf("-zero\n");
		}
	}
	else if(expBits == 0 && fractBits != 0)
	{
		printf("denormalized: exp = %3i\n", (1-127));
	}
	else if(expBits != 0 && fractBits != 255)
	{
		printf("normalized: exp = %3i\n", (expBits - 127));
	}
	else if(expBits == 255 && fractBits == 0)
	{
		if(signBit == 0)
		{
			printf("+infinity\n");
		}
		else
		{
			printf("-infinity\n");
		}
	}
	else if(expBits == 255 && fractBits >= 0x00400000)
	{
		printf("QNaN\n");
	}
	else if(expBits == 255 && fractBits >= 0x00200000)
	{
		printf("SNaN\n");
	}
	printf("\n");
}

// do not change this function in any way
int main(int argc, char **argv)
{
	unsigned int	i;					// number currently being analyzed
	bool			validInput;			// was user input valid?

	printf("CS201 - A01p - %s\n\n", studentName);
	bigOrSmallEndian();
	for (;;) {
		if (argc == 1)						// allow grading script to control ...
			printf("> ");					// ... whether prompt character is printed
		validInput = getNextHexInt(&i);
		printf("0x%08X\n", i);
		if (! validInput) {					// encountered bad input
			printf("bad input\n");
			while (getchar() != '\n') ;		// flush bad line from input buffer
			continue;
			}
		printNumberData(i);
		if (i == 0) {
			printf("bye...\n");
			break;
			}
		}
	printf("\n");
	return 0;
}
