#include <stdio.h>

int SumOfNaturalNumbers(int n)
{
    static int sum = 0;
    if(n > 0)
    {        
        // First method   
        // sum = n + SumOfNaturalNumbers(n - 1);    
        // Second method
        sum += n;
        SumOfNaturalNumbers(n - 1);
        //printf("\n%d\t%d", sum, n);
        return sum;
    }
    return 0;
}

int main()
{
    int n = 5;
    int sum = (n*(n+1))/2; // Formula
    printf("\nSum of %d natural numbers", n);
    printf("\n--------------------------");
    printf("\nRecursion: %d\nFormula: %d",SumOfNaturalNumbers(n), sum);
    
    return 0;
}