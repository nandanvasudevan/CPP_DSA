#include "strings.h"

String::String()
{
    length = DEFAULT_LENGTH;
    string = new char[length];
}

String::String(int size)
{   
    String::size = size;
    length = size;
    string = new char[size];
}

void String::input()
{
    std::cin.getline(string, length);
    std::cout << std::endl << "";
    int i = 1;
    while(string[i] != '\0'){ i++; }
    length = i;
    updateWordStat();
}

void String::display(char* message)
{   
    std::cout.flush();
    std::cout << std::endl << message << string;
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
    copy.wordStat = wordStat;
    copy.length = length;
    copy.size = size;
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

void String::updateWordStat()
{
    String input;
    createCopy(input);
    input.toLower();
    for(int i = 0; i < length; i++)
    {
        if( input.string[i] == 'a' || 
            input.string[i] == 'e' || 
            input.string[i] == 'i' || 
            input.string[i] == 'o' || 
            input.string[i] == 'u')
        {
            wordStat.vowelCount++;
        }

        if((string[i] != ' ' && string[i+1] == ' ') && i > 0)
        {
            wordStat.wordCount++;
        } 

        if((input.string[i] >= (int)'a') && (input.string[i] <= (int)'z'))
        {
            wordStat.alphabetCount ++;
        }
    }
    if(string[length-1] != ' ') wordStat.wordCount++;
    wordStat.characterCount = length-1;
}

bool String::compareString(String toCompare, char type)
{
    String lowerThis = String(length);
    String lowerCompare = String(toCompare.length);
    toCompare.createCopy(lowerCompare);
    createCopy(lowerThis);
    
    if(type == 'i')
    {
        lowerCompare.toLower();
        lowerThis.toLower();

        for(int i = 0; i < length; i++)
        {
            if(lowerThis.string[i] != lowerCompare.string[i]) return false;
        }
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            if(lowerThis.string[i] != lowerCompare.string[i]) return false;
        }
    }

    return true;    
}

char* String::getString() { return string; }
int String::getLength() { return length; }

unsigned int String::getAlphabetCount() { return wordStat.alphabetCount; }
unsigned int String::getCharacterCount() { return wordStat.characterCount; }
unsigned int String::getConsonantCount() { return (wordStat.alphabetCount - wordStat.vowelCount); }
unsigned int String::getVowelCount() { return wordStat.vowelCount; }
unsigned int String::getWordCount() { return wordStat.wordCount; }

void String::saveData(std::string fileName)
{    
    String copy = String(length);
    createCopy(copy);    
    copy.archivedString = string;
    std::ofstream outputFileStream(fileName);
    boost::archive::text_oarchive ar(outputFileStream);    
    ar & copy;    
}

void String::loadData(std::string fileName)
{
    std::ifstream inputFileStream(fileName);
    boost::archive::text_iarchive ar(inputFileStream);
    ar & *this;

    string = new char[length];
    for(int i = 0; i < length; i++)
    {
        string[i] = archivedString[i];
    }    
}