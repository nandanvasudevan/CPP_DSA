#include <iostream>
#include "array.h"

int main()
{
    int size = 5;
    Array names = Array(size, true, true);
    for(int i = 0; i < size; i++)
    {
        int value;
        std::cout << std::endl << "Enter value for element in position " << i + 1 << ": ";
        //std::cin >> value;
        names.insert(10 + i);
    }
    names.display('\n', std::string("Before:"));
    std::cout << "\nMax: " << names.getMax();
    names.insert(2,99);
    names.display('\n', std::string("\nAfer:"));
    std::cout << "\nMax: " << names.getMax();    
}