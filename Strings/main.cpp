#include <iostream>
#include "strings.h"
std::string fileName = "Serialized_String.txt";

int main()
{
    std::cout << std::endl << "Enter string:\t";
    String name = String(20);
    name.input();
    //name.reverse();
    name.display("Input: ");
    // std::cout << std::endl << std::boolalpha << name.isPalindrome();
    name.toUpper();
    name.display("\nUpper: ");
    name.toLower();
    name.display("\nLower: ");    
    name.saveData(fileName);    
    return 0;
}