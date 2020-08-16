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
                archive & size;
                archive & length;  
                archive & wordStat.wordCount;
                archive & archivedString;
            }
            int size;
            int length;            
            char* string;
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
            void reverse();            
            void input();
            void display(char*);
            void createCopy(String);
            void toUpper(char type = 'a');
            void toLower(char type = 'a');
            bool compareString(String, char type = 'n');
            
            bool isPalindrome();

            char* getString();
            int getLength();

            void updateWordStat(void);
            unsigned int getWordCount(void);
            unsigned int getVowelCount(void);
            unsigned int getAlphabetCount(void);
            unsigned int getCharacterCount(void);
            unsigned int getConsonantCount(void);

            void saveData(std::string);
            void loadData(std::string);
    };
#endif