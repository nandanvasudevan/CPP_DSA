#include <iostream>
#include "array.h"

void findMissingNumber(Array input)
{
    int sumOfNaturalNumbers = (input.getMax() * (input.getMax() + 1))/2;
    int missingNumber = sumOfNaturalNumbers - input.getSum();
    std::cout<<"\nMissing number = " << missingNumber;
}

void multipleMissingNumbers(Array input)
{
    int difference = input.getValue(0) - 0;
    int missingNumbers = 0;
    for(int i = 0; i < input.getLength(); i++)
    {        
        /* if(input.getValue(i) - i > difference)
        {
            int currDifference = input.getValue(i) - i;
            int offset = currDifference - difference;
            std::cout << std::endl << "\nMissing number: " << input.getValue(i) - offset;
            difference = currDifference;
        } */
        if(input.getValue(i) - i > difference)
        {
            int j = difference;
            int currDifference = input.getValue(i) - i;
            while(j < currDifference)
            {
                std::cout << std::endl << "\nMissing number: " << i + j;
                j += difference;
                missingNumbers++;
            }
            difference - input.getValue(i) - i;
        }        
    }
    std::cout << std::endl << "\nMissing numbers: " << missingNumbers;
}

void main()
{
    int length;
    std::cout << std::endl << "Enter length: " ;
    std::cin >> length;
    Array* input = new Array(length);

    int offset = 2;
    for(int i = 0; i < length; i++)
    {
        input->insert(i + offset);
    }

    input->insert(length-2,7);
    input->insert(length-1,9);
    input->display('\t',std::string("\nInput: "));
    multipleMissingNumbers(*input);
}