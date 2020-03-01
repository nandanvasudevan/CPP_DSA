#include "NestedRecursion.h"

int recursiveFunction(int n)
{
    if(n > 100) 
    {
        printf("\nIf:\t%d", n);
        return (n - 10);
    }
    else
    {
        printf("\nElse:\t%d", n);
        return recursiveFunction(recursiveFunction(n + 11));
    }
}