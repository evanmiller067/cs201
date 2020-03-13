#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>      // for times()
#include <time.h>           // for clock()

char * name = "Evan Miller";

/* I will be using only the two functions
 * you will be changing when grading. So
 * don't write code you want to keep outside
 *  of the two functions (they won't be copied over)
 */

// These can be changed for debugging purposes
// but DO CHANGE THEM TO THE ORIGINAL VALUES
//    RUNS = 10000
//    SIZE = 10000
#define RUNS 10000
#define SIZE 10000


/*  write a function using gcc inline assembly
 * that calculates the area of a triangle.
 * the formula for doing so is:
 *    area = 1/2 x side1 x side2
 */
int calcArea(int side1, int side2)
{
   int area = 1.0;

   // PUT YOUR ASSEMBLY CODE HERE
	asm(
		"sar %[side1] \n\t"
		"imul %[side2], %[side1] \n\t"
		"mov %[area], %[side1] \n\t"
		: [area] "=r"(area)
		: [side1]"r"(side1), [side2]"r"(side2)
		);
   // DON'T WRITE ANY OTHER
   // C CODE

  
   return area;
}

/* this is the original function
 * DON"T TOUCH THIS FUNCTION
 * it's for reference only
 */
int sumAreaOrig(int a, int b, int *arr)
{
   int sum, i, j;

   for(i=0; i<RUNS; i++) {
       
       sum = 0;
       for(j=0; j<SIZE; j++)  {
          sum += arr[j]*calcArea(a,b) + j;
      }
      
   }           
   return sum;
}

/*  PLEASE MODIFY THIS FUNCTION
 *  make sure it returns the same
 *  sum as the original function
 */
int sumAreaImprove(int a, int b, int *arr)
{
    /* you can add any variables here */
   int sum, i, j;
   int rt1, rt2, rt3;
   int area = calcArea(a, b);
   /* leave this outer loop alone*/
   for(i=0; i < RUNS; i++)
   {
       /* you can change this inner loop */
       /* but remember it must sum over all values */
	    sum = 0;
	    rt1 = 0;
		rt2 = 0;
		rt3 = 0;
       for(j=0; j<SIZE; j+= 20)  {
		   sum += (arr[j] + arr[j + 1] + arr[j + 2] + arr[j + 3] + arr[j + 4]) * area + j * 5 + 5;
		   rt1 += (arr[j + 5] + arr[j + 6] + arr[j + 7] + arr[j + 8] + arr[j + 9]) * area + (j + 5) * 5 + 5;
		   rt2 += (arr[j + 10] + arr[j + 11] + arr[j + 12] + arr[j + 13] + arr[j + 14]) * area + (j + 10) * 5 + 5;
		   rt3 += (arr[j + 15] + arr[j + 16] + arr[j + 17] + arr[j + 18] + arr[j + 19]) * area + (j + 15) * 5 + 5;
       }      
   }
   return sum + rt1 + rt2 + rt3;
}

/* You can modify main for debugging
 * but PLEASE RETURN IT TO THE ORIGINAL
 * CODE. I will be using only your two functions
 * above when grading.  So don't write code
 * you want to keep outside of the above two
 * functions (they won't be copied over)
 */
int main(int argc, char **argv)
{
    struct tms  origStart, origStop, impStart, impStop;
    double origTime, impTime;
    double difference;
    int area, sumOrig, sumImprove;
    int side1, side2;
    int i;
    int array[SIZE];

    for(i=0; i<SIZE; i++)
       array[i] = i;

    if(argc < 3) {
        printf("Need to provide two side measurements\n");
        exit(-1);
    } else {
        side1 = atoi(argv[1]);
        side2 = atoi(argv[2]);
    }

    printf("side1: %d  side2: %d\n", side1, side2);
        
	printf("Name: %s\n",name);
    
    area = calcArea(side1, side2);
    printf("the area is: %d\n", area);

    //start time here
    times(&origStart);
    sumOrig = sumAreaOrig(side1, side2, array);
    times(&origStop);
    //end time here
    printf("results from orignal: %d\n", sumOrig);

    // start time here
    times(&impStart);
    sumImprove = sumAreaImprove(side1, side2, array);
    times(&impStop);
    // end time here
    printf("results from improved: %d\n", sumImprove);

    //do time calculations here
    origTime = (origStop.tms_utime - origStart.tms_utime);
    impTime =  (impStop.tms_utime - impStart.tms_utime);
    printf("original user time: %f\n",origTime);
    printf("improved user time: %f\n", impTime);
    difference = ((origTime - impTime)/origTime)*100.0;
    printf("percent difference:  %f\n", difference);
	return 0;
}
