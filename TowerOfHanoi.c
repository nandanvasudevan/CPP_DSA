#include <stdio.h>

void towerShift(int numberOfRings, int Tower1, int Tower2, int Tower3)
{
    if(numberOfRings > 0)
    {
        towerShift(numberOfRings - 1, Tower1, Tower3, Tower2);
        printf("\nMoving from %c to %c", (char)Tower1, (char)Tower3);
        towerShift(numberOfRings - 1, Tower2, Tower1, Tower3);        
    }
}

int main()
{
    towerShift(3,(int)'A',(int)'B',(int)'C');
    return 0;
}