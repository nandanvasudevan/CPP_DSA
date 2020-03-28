#include <iostream>
#include "strings.h"

/* String::~String()
{
    delete string;
}
 */
String::String()
{

}

String::String(int size)
{   
    String::size = size;
    length = size;
    String::string = new char[size];
}

void String::input()
{
    std::cin >> string;    
    int i = 0;
    while(string[i] != '\0'){ i++; }
    length = i;    
}

void String::display(char* message)
{   
    std::cout << std::endl << message << length;
}

void String::reverse()
{
    int i = 0, j = length - 1;
    while(i < j)
    {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i ++;
        j --;
    }    
}

void String::createCopy(String copy)
{
    for(int i = 0; i < length; i++)
    {
        copy.string[i] = string[i];     
    }    
}

bool String::isPalindrome()
{
    String reverse = String(length);
    createCopy(reverse);
    reverse.reverse();

    for(int i = 0; i < length; i++)
    {
        if(string[i] != reverse.string[i]) return false;
    }
    return true;
}

void String::toUpper(char type)
{
    switch(type)
    {
        case 'a':
            for(int i = 0; i < length; i++)
            {
                if((string[i] >= (int)'a') && (string[i] <= (int)'z'))
                    string[i] -= 32;    
            }
        break;
        case 'f':
            if((string[0] >= (int)'a') && (string[0] <= (int)'z'))
                string[0] -= (char) 32;
        break;
        default:
        break;
    }
}

void String::toLower(char type)
{
    switch(type)
    {
        case 'a':
            for(int i = 0; i < length; i++)
            {
                if((string[i] >= (int)'A') && (string[i] <= (int)'Z'))
                    string[i] += 32;
            }
        break;
        case 'f':
            if((string[0] >= (int)'A') && (string[0] <= (int)'Z'))
                string[0] += (char) 32;
        break;
        default:
        break;
    }
}


char* String::getString() { return string; }
int String::getLength() { return length; }

void String::saveData(std::string fileName)
{    
    std::ofstream outputFileStream(fileName);
    boost::archive::text_oarchive ar(outputFileStream);

    ar & *this;    
}

void String::loadData(std::string fileName)
{
    std::ifstream inputFileStream(fileName);
    boost::archive::text_iarchive ar(inputFileStream);

    ar & *this;  
}