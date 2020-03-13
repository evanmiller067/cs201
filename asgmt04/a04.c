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

    // ... and this one.

    // Please change 'your name' to your actual name.
    printf("CS201 - Asgmt 4 - Evan Miller\n");
    for (i = 0; i < N_TIMES; i++) {

    // You can change anything between this comment ...
        rt1 = 0;
        rt2 = 0;
        for (p = array; p < &array[ARRAY_SIZE]; p += 12) {
            rt1 += (*p) + *(p + 1) + *(p + 2) + *(p + 3) + *(p + 4) + *(p + 5);
            rt2 += *(p + 6) + *(p + 7) + *(p + 8) + *(p + 9) + *(p + 10) + *(p + 11);
        }
        sum += rt1 + rt2;

    // ... and this one. But your inner loop must do the same
    // number of additions as this one does.

    }

    // You can add some final code between this comment ...
    // ... and this one.

    return 0;
}
