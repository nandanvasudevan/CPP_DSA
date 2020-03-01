#include <stdio.h>

int power(int number, int exponent)
{
    static int product;
    
    if(exponent > 0)
    {
        product = number * power(number, exponent-1);
        return product;
    }
    else
        return 1;
}

int main()
{
    int number = 10;
    int exponent = 3;
    printf("%d", power(number, exponent));
    return 0;
}