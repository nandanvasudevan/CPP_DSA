#include <iostream>
#include "strings.h"
std::string fileName = "Serialized_String.txt";

int main()
{
    std::cout << std::endl << "Enter string:\t";
    String name = String(10);
    name.input();
    //name.reverse();
    name.display("Input: ");
    // std::cout << std::endl << std::boolalpha << name.isPalindrome();
    name.toUpper('a');
    name.display("\nUpper: ");
    name.toLower('a');
    name.display("\nLower: ");
    name.saveData(fileName);    
    String newName = String();
    newName.loadData(fileName);
    newName.display("\nNew Name: ");
    return 0;
}