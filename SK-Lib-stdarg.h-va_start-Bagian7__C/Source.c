#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

double deviation(int first, ...);

int main(void) {
    /* Call with 3 integers (-1 is used as terminator). */
    printf("Deviation is: %f\n", deviation(2, 3, 4, -1));

    /* Call with 4 integers. */
    printf("Deviation is: %f\n", deviation(5, 7, 9, 11, -1));

    /* Call with just -1 terminator. */
    printf("Deviation is: %f\n", deviation(-1));

    _getch();
    return 0;
}

/* Returns the standard deviation of a variable list of integers. */
double deviation(int first, ...) {
    int count = 0, i = first;
    double mean = 0.0, sum = 0.0;

    va_list marker;
    va_list copy;

    va_start(marker, first);     /* Initialize variable arguments. */
    va_copy(copy, marker);       /* Copy list for the second pass */

    while (i != -1) {
        sum += i;
        count++;
        i = va_arg(marker, int);
    }

    va_end(marker);              /* Reset variable argument list. */
    mean = sum ? (sum / count) : 0.0;

    i = first;                  /* reset to calculate deviation */
    sum = 0.0;
    
    while (i != -1) {
        sum += (i - mean) * (i - mean);
        i = va_arg(copy, int);
    }

    va_end(copy);               /* Reset copy of argument list. */
    return count ? sqrt(sum / count) : 0.0;
}