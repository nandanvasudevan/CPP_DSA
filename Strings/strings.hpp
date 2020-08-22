#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <iostream>
#include <fstream>

#ifndef STRINGS_H
#define STRINGS_H
#define DEFAULT_LENGTH 20
class String
{
private:
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &archive, const unsigned int version)
    {
        archive &length;
        archive &wordStat.wordCount;
        archive &archivedString;
    }
    size_t length;
    char *string;
    std::string archivedString;

    struct wordStats
    {
        int wordCount = 0;
        int vowelCount = 0;
        int alphabetCount = 0;
        int characterCount = 0;
    } wordStat;

public:
    String();
    String(int);
    String(String &);
    ~String();
    void reverse();
    void getInput();
    void display(const char *);
    // void createCopy(String);
    void toUpper(const char type = 'a');
    void toLower(const char type = 'a');
    bool compareString(String, const char type = 'n');

    bool isPalindrome();

    char *getString();
    int getLength();

    void updateWordStat(void);
    unsigned int getWordCount(void);
    unsigned int getVowelCount(void);
    unsigned int getAlphabetCount(void);
    unsigned int getCharacterCount(void);
    unsigned int getConsonantCount(void);

    void saveData(const char *fileName);
    void loadData(const char *fileName);
};
#endif