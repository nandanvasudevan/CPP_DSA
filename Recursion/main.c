#include <stdio.h>
#include "SimpleRecursion.h"

int main()
{
    int num = 5;
    printf("\nFirst run: %d\n", recursiveFunction(num));
    printf("\nSecond run: %d\n", recursiveFunction(num));
    return 0;
}