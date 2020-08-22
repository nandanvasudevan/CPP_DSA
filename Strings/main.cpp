#include <iostream>
#include "strings.hpp"
const char *fileName = "Serialized_String.txt";
const char *inputQuery = "\nInput: ";
const char *lowerResponse = "\nLower:";
const char *upperResponse = "\nUpper:";

int main()
{
    std::cout << std::endl
              << "Enter string:\t";
    String name(20);
    name.getInput();
    //name.reverse();
    name.display(inputQuery);
    // std::cout << std::endl << std::boolalpha << name.isPalindrome();
    name.toUpper();
    name.display(lowerResponse);
    name.toLower();
    name.display(upperResponse);
    name.saveData(fileName);
    return 0;
}