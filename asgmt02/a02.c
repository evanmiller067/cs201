#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// do not change anything above this comment

double hullSpeed(double lgth)
{
	double hs; //hull speed variable to return
	asm("fldl %1 \n" // st(0) => st(1), sto(0)length. FLDL loadas double
		"fsqrt  \n" // sqrt(st(0))
		"fmulp \n" // multiply st(0),st(1)(1.34). stores result in st(0)
		:"=&t"(hs) :"m"(lgth), "0"(1.34)
		);
	return hs; 
}

// do not change anything below this comment, except for printing out your name

double hullSpeedC(double lgth)
{
	// this C implementation of the hull speed computation is provided
	// so you can compare its correct results with the results of your code

	return 1.34 * sqrt(lgth);
}

int main (int argc, char **argv)
{
	double	lgth;
	double	hullSpd, hullSpdC;

	printf("CS201 - Assignment 02 - Evan Miller\n");
	if (argc != 2) {
		printf("need 1 argument: boat length\n");
		return -1;
		}
	lgth = atof(argv[1]);
	hullSpd = hullSpeed(lgth);
	hullSpdC = hullSpeedC(lgth);

	printf("hullSpeed(%.0f) = %.3f, %.3f\n", lgth, hullSpd, hullSpdC);

	return 0;
}
