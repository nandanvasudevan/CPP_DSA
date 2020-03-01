#include "TreeRecursion.h"

int recursiveFunction(int n)
{    
    if(n > 0)
    {   
        printf("\nn: %d", n);
        recursiveFunction(n-1);
        recursiveFunction(n-1);
        // printf("Descending: %d\n", n);
    }
    return 0;
}