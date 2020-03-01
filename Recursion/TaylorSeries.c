#include <stdio.h>

double factorial(int n)
{
    static double product;
    if(n > 1)
    {
        product = n*factorial(n-1);
        return product;
    }
    else
        return 1;
}

double power(int number, int exponent)
{
    static double product;
    
    if(exponent > 0)
    {
        product = number * power(number, exponent-1);
        return product;
    }
    else
        return 1;
}

double taylorSeries(int x, int n)
{
    double sum;
    //static double power = 1;
    //static double factorial = 1;
    if(n > 0)
    {
        sum = (power(x,n-1)/factorial(n-1)) + taylorSeries(x, n-1);
        /*
        sum = taylorSeries(x, n-1);
        power = power * x;
        factorial = factorial * n;
        return sum + power/factorial;
        */
       return sum;
    }
    else
        return 0;
}

double HornersRule_Recursive(float x, int n)
{
    static double sum = 1;
    if(n > 0)
    {
        sum = 1 + x/n * sum;
        return HornersRule_Recursive(x, n-1);        
    }
    else return sum;    
}

double HornersRule_Iterative(float x, int n)
{
    double sum = 1;
    int i;
    for(; n > 0; n--)
    {
        sum = 1 + x/n * sum;        
    }
    return sum;
}

int main()
{
    int x = 1;
    int n = 10;

    /* printf("\nEnter the exponent value (x): ");
    scanf("%d", &x);
    printf("\nEnter precesion(n): ");
    scanf("%d", &n); */

    printf("\nRecursion:\t%lf", taylorSeries(x, n));
    printf("\nHorner's:\t%lf", HornersRule_Recursive(x, n));
    printf("\nHorner's Iterative:\t%lf", HornersRule_Iterative(x, n));

    return 0;
}