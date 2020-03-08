#include <iostream>
#include "array.h"

Array::Array(const int length)
{
    Array::length = length;
    bFIFO_LIFO = true;
    bOverwrite = false;

    size = length * sizeof(int);
    A = new int[size];
}

Array::Array(int length, bool bFIFO_LIFO, bool bOverwrite)
{
    Array::length = length;
    Array::bFIFO_LIFO = bFIFO_LIFO;
    Array::bOverwrite = bOverwrite;

    size = length * sizeof(int);
    A = new int[size];
}

void Array::display(char separator, std::string& Message)
{
    std::cout << Message << std::endl;
    for(int i = 0; i < length; i++)
    {
        std::cout << A[i] << separator;
    }
}

void Array::insert(const int pos, const int value)
{
    if(bOverwrite)
    {
        if(pos < length)
            A[pos] = value;
        else
        {
            std::cout << "Invalid position";
        }
    }
    else 
    {
        for(int i = length; i > pos; i--)
        {
            A[i] = A[i-1];
        }

        A[pos] = value;
    }
    updateStats();
    
}

int Array::insert(const int value)
{
    int returnVal = 0;
    if(bFIFO_LIFO)
    {
        static unsigned int counter = 0;
        
        A[counter++] = value;

        if(counter >= length) counter = 0;
        if(counter == length - 1) returnVal = A[0];
        else returnVal = A[counter + 1];
    }
    else
    {
        static unsigned int counter = 0;
        int returnIndex = 0;
        A[counter++] = value;
       

        if(counter >= length) 
        {
            counter = 0;
            returnIndex = length - 1;
        }
        
        returnVal = A[returnIndex];
    }
    updateStats(); 
    return returnVal;   
}

int Array::getSize(){ return size; }

void Array::updateStats()
{
    int sum = 0;
    int max = A[0];
    int min = A[0];
    for(int i=0; i < length; i++)
    {        
        sum += A[i];
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }

    stats.max = max;
    stats.min = min;
    stats.sum = sum;
    stats.average = sum/length;
}

float Array::getAverage() { return stats.average; }
int Array::getMax() { return stats.max; }
int Array::getMin() { return stats.min; }