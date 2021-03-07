#include "strings.hpp"

String::String() : length(DEFAULT_LENGTH)
{
    string = new char[length];
}

String::String(int length) : length(length)
{
    string = new char[length];
}

String::String(String &original)
{
    length = original.length;
    string = new char[length];

    for (size_t i = 0; i < original.length; i++)
    {
        string[i] = original.string[i];
    }
}

String::~String()
{
    length = 0;
    delete string;
}

void String::getInput()
{
    std::cin.getline(string, length);
    std::cout << std::endl
              << "";
    int i = 1;
    while (string[i] != '\0')
    {
        i++;
    }
    length = i;
    updateWordStat();
}

void String::display(const char *message)
{
    std::cout.flush();
    std::cout << std::endl
              << message << string;
}

void String::reverse()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}

bool String::isPalindrome()
{
    String reverse(*this);
    reverse.reverse();

    for (size_t i = 0; i < length; i++)
    {
        if (string[i] != reverse.string[i])
            return false;
    }
    return true;
}

void String::toUpper(const char type)
{
    switch (type)
    {
    case 'a':
        for (size_t i = 0; i < length; i++)
        {
            if ((string[i] >= (int)'a') && (string[i] <= (int)'z'))
                string[i] -= 32;
        }
        break;
    case 'f':
        if ((string[0] >= (int)'a') && (string[0] <= (int)'z'))
            string[0] -= (char)32;
        break;
    default:
        break;
    }
}

void String::toLower(const char type)
{
    switch (type)
    {
    case 'a':
        for (size_t i = 0; i < length; i++)
        {
            if ((string[i] >= (int)'A') && (string[i] <= (int)'Z'))
                string[i] += 32;
        }
        break;
    case 'f':
        if ((string[0] >= (int)'A') && (string[0] <= (int)'Z'))
            string[0] += (char)32;
        break;
    default:
        break;
    }
}

void String::updateWordStat()
{
    String input(*this);
    input.toLower();
    for (size_t i = 0; i < length; i++)
    {
        if (input.string[i] == 'a' ||
            input.string[i] == 'e' ||
            input.string[i] == 'i' ||
            input.string[i] == 'o' ||
            input.string[i] == 'u')
        {
            wordStat.vowelCount++;
        }

        if ((string[i] != ' ' && string[i + 1] == ' ') && i > 0)
        {
            wordStat.wordCount++;
        }

        if ((input.string[i] >= (int)'a') && (input.string[i] <= (int)'z'))
        {
            wordStat.alphabetCount++;
        }
    }
    if (string[length - 1] != ' ')
        wordStat.wordCount++;
    wordStat.characterCount = length - 1;
}

bool String::compareString(String toCompare, const char type)
{
    String lowerThis(*this);
    String lowerCompare(toCompare);

    if (type == 'i')
    {
        lowerCompare.toLower();
        lowerThis.toLower();

        for (size_t i = 0; i < length; i++)
        {
            if (lowerThis.string[i] != lowerCompare.string[i])
                return false;
        }
    }
    else
    {
        for (size_t i = 0; i < length; i++)
        {
            if (lowerThis.string[i] != lowerCompare.string[i])
                return false;
        }
    }

    return true;
}

char *String::getString() { return string; }
int String::getLength() { return length; }

unsigned int String::getAlphabetCount() { return wordStat.alphabetCount; }
unsigned int String::getCharacterCount() { return wordStat.characterCount; }
unsigned int String::getConsonantCount() { return (wordStat.alphabetCount - wordStat.vowelCount); }
unsigned int String::getVowelCount() { return wordStat.vowelCount; }
unsigned int String::getWordCount() { return wordStat.wordCount; }

void String::saveData(const char *fileName)
{
    String copy(*this);
    copy.archivedString = string;
    std::ofstream outputFileStream(fileName);
    boost::archive::text_oarchive ar(outputFileStream);
    ar &copy;
}

void String::loadData(const char *fileName)
{
    std::ifstream inputFileStream(fileName);
    boost::archive::text_iarchive ar(inputFileStream);
    ar &*this;

    string = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        string[i] = archivedString[i];
    }
}
