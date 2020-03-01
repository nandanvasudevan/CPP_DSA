#include "SimpleRecursion.h"

int recursiveFunction(int n)
{
    if(n > 0)
    {
        // printf("Ascending: %d\n", n);
        return recursiveFunction(n - 1) + n;
        // printf("Descending: %d\n", n);
    }
}