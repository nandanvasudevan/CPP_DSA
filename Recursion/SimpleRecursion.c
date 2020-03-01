#include "SimpleRecursion.h"

int x = 0;

int recursiveFunction(int n)
{
    // static int x = 0;
    static int val = 0;
    if(n > 0)
    {
        x ++;
        // printf("Ascending: %d\n", n);                
        val = recursiveFunction(n - 1) + x;        
        printf("\nval: %d\tx: %d", val - x, x);
        return val;
        // printf("Descending: %d\n", n);
    }
    return 0;
}