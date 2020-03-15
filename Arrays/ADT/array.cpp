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

int Array::getValue(const int pos) { return A[pos]; }

void Array::display(char separator, std::string& Message)
{
    std::cout << Message << std::endl;
    for(int i = 0; i < length; i++)
    {
        std::cout << A[i] << separator;
    }
}

void Array::remove(const int pos)
{
    for(int i = pos; i < length; i++)
    {
        A[i] = A[i+1];
    }
    updateStats();
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

void Array::reverse()
{
    // int* reverse = new int[length];
    for(int i = 0, j = length - 1; i < j; i++, j--)
    {
        // reverse[--j] = A[i];
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    // delete reverse;
}

Array Array::merge(int array1[], int array2[], int len1, int len2)
{
    int finalLenth = len1 + len2;
    Array* mergedArray = new Array(finalLenth);
    int bigLength, smallLength;

    if(len1 >= len2) 
    {
        bigLength = len1;
        smallLength = len2;
    }
    else
    {
        bigLength = len2;
        smallLength = len1;
    }
    
    Array* bigOne = new Array(bigLength);
    Array* smallOne = new Array(smallLength);

    bigOne->A = array1;
    smallOne->A = array2;

    if(!(bigOne->isSorted() && smallOne->isSorted())) return false;

    for(int i=0, j=0, k=0; k < finalLenth;k++)
    {
        if((bigOne->A[i] <=smallOne->A[j]) && (i < bigLength))
        {   
            std::cout << "bigOne[" << i <<"]: " << bigOne->A[i];
            mergedArray->A[k] = bigOne->A[i++];
        }
        else if((bigOne->A[i] > smallOne->A[j]) && (j < smallLength))
        {
            std::cout << "smallOne[" << j <<"]: " << smallOne->A[j];
            mergedArray->A[k] = smallOne->A[j++];
        }
        else
        {
            if(i < bigLength)
                mergedArray->A[k] = bigOne->A[i++];
            else
            {                
                mergedArray->A[k] = smallOne->A[j++];
            }
                
        }
    }
    return *mergedArray;
}

Array Array::merge(Array array1, Array array2, bool ignoreDuplicate)
{
    int finalLenth = array1.getLength() + array2.getLength();
    Array* mergedArray = new Array(finalLenth);
    int bigLength, smallLength;

    if(array1.getLength() >= array2.getLength()) 
    {
        bigLength = array1.getLength();
        smallLength = array2.getLength();
    }
    else
    {
        bigLength = array2.getLength();
        smallLength = array1.getLength();
    }
    
    Array* bigOne = new Array(bigLength);
    Array* smallOne = new Array(smallLength);

    bigOne->A = array1.A;
    smallOne->A = array2.A;

    if(!(bigOne->isSorted() && smallOne->isSorted())) return false;

    for(int i=0, j=0, k=0; k < finalLenth;k++)
    {
        if((bigOne->A[i] == smallOne->A[j]) && (j < smallLength) && (i < bigLength) && ignoreDuplicate)
        {
            mergedArray->A[k] = smallOne->A[j++];
            i++;
        }
        else if((bigOne->A[i] <= smallOne->A[j]) && (i < bigLength))
        {   
            mergedArray->A[k] = bigOne->A[i++];
        }
        else if((bigOne->A[i] > smallOne->A[j]) && (j < smallLength))
        {
            mergedArray->A[k] = smallOne->A[j++];
        }        
        else
        {
            if(i < bigLength)
                mergedArray->A[k] = bigOne->A[i++];
            else if(j < smallLength)
            {
                mergedArray->A[k] = smallOne->A[j++];
            }
            else
            {
                mergedArray->A[k] = 0;
            }
            
                
        }
    }
    return *mergedArray;
}

Array Array::unionOperator(Array array1, Array array2){ return merge(array1, array2, true); }

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
int Array::getSize(){ return size; }
int Array::getLength() { return length; }
int Array::getMax() { return stats.max; }
int Array::getMin() { return stats.min; }

bool Array::isSorted()
{
    int diff = 0;
    bool negativeSlope = false, positiveSlope = false;

    for(int i = 1; i < length; i++)
    {
        diff = A[i] - A[i-1];
        if((diff >= 0) && !negativeSlope) positiveSlope = true;
        else if((diff < 0) && !positiveSlope) negativeSlope = true;
        else return false;
    }
    return true;
}