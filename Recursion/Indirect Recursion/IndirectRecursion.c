#include "IndirectRecursion.h"

void secondRF(int n)
{
    if(n > 1)
    {
        printf("\nSecond:\t%d", n);
        firstRF(n/2);
    }
}

void firstRF(int n)
{
    if(n > 0)
    {
        printf("\nFirst:\t%d", n);
        secondRF(n-1);
    }
}