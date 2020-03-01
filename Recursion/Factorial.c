#include <stdio.h>

int factorial(int n)
{
    static int product;
    if(n > 1)
    {
        product = n*factorial(n-1);
        return product;
    }
    else
        return 1;
}

int main()
{
    int n = 4;
    printf("%d", factorial(n));
    return 0;
}