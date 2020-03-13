#include <stdio.h>
#include <stdlib.h>

// You are only allowed to make changes to this code as specified by the comments in it.
// The code you submit must have these two values.
#define N_TIMES     600000
#define ARRAY_SIZE   10000

int main (void)
{
    double  *array = calloc(ARRAY_SIZE, sizeof(double));
    double  sum = 0;
    int     i;

    // You can add variables between this comment ...

    double *p; //pointer
    double rt1 = 0; //running total to be added to sum
    double rt2 = 0; //running total 2
	double rt3 = 0;
	double rt4 = 0;
	double rt5 = 0;
	double rt6 = 0;
	double rt7 = 0;
	double rt8 = 0;
    // ... and this one.

    // Please change 'your name' to your actual name.
    printf("CS201 - Asgmt 4 - Evan Miller\n");
    for (i = 0; i < N_TIMES; i++) {

    // You can change anything between this comment ...
       // rt1 = 0;
       // rt2 = 0;
		p = array + (ARRAY_SIZE);
			while(array < p - 25)
			{
            	rt1 += *p + *(p - 1) + *(p - 2) + *(p - 3);
				rt2 += *(p - 4) + *(p - 5) + *(p - 6);
            	rt3 += *(p - 7) + *(p - 8) + *(p - 9);
				rt4 += *(p - 10) + *(p - 11) + *(p - 12);
				rt5 += *(p - 13) + *(p - 14) + *(p - 15);
				rt6 += *(p - 16) + *(p - 17) + *(p - 18);
				rt7 += *(p - 19) + *(p - 20) + *(p - 21);
				rt8 += *(p - 22) + *(p - 23) + *(p - 24);
				p -= 25;
        	}
			if(p > array)
			{
				rt1 += *p;
			}
		
       //  sum += (rt1 + rt2 + rt3 + rt4 + rt5);

    // ... and this one. But your inner loop must do the same
    // number of additions as this one does.

    }

    // You can add some final code between this comment ...
    
	sum += (rt1 + rt2 + rt3 + rt4 + rt5 + rt6 + rt7 + rt8);	

	// ... and this one.

    return 0;
}
