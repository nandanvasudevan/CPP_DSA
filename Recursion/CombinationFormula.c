#include <stdio.h>

float combinationFormula(int n, int r)
{
    static float nFact = 1, rFact = 1, n_rFact = 1, n_r = 1;    
    float fCombination = 1;
    static OneTime = 1;

    if(OneTime == 1)
    {
        OneTime = 0;
        if(n == r){ return 1; }
        else if(r == 0){ return 1; }
    }

    if(r > n) return 0;    
    else
    {
        if((n_r) <= (n - r)) n_rFact *= n_r++;
        if(n > 1) nFact *= n;
        else
        {
            fCombination = nFact/(rFact*n_rFact);
            //printf("\n%d %d %d %f",nFact, rFact, n_rFact, fCombination);                      
        }
        if(r > 1) rFact *= r;   
        // printf("\n%d\tFact: %f", n, nFact);
        if(n > 0) return combinationFormula(n-1,r-1);
        else return fCombination;
    }    

}

float combination_PascalsTriangle(int n, int r)
{
    if((n == r) || (r == 0)) return 1;
    else return (combination_PascalsTriangle(n-1, r-1) + combination_PascalsTriangle(n-1,r));
}

int main()
{
    float result = combination_PascalsTriangle(5,2);
    printf("\n%f", result);
    return 0;
}