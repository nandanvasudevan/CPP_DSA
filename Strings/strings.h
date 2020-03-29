#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <fstream>

#ifndef STRINGS_H
    #define STRINGS_H

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
                /* archive & test;  */             
            }
            int size;
            int length;            
            char* string;
            /* std::string test; */

            struct wordStats
            {
                int wordCount = 0;
                int vowelCount = 0;
                int alphabetCount = 0;
                int characterCount = 0;                
            }wordStat;
        public:
            String();
            /* ~String(); */
            String(int);            
            void reverse();            
            void input();
            void display(char*);
            void createCopy(String);
            void toUpper(char type = 'a');
            void toLower(char type = 'a');
            
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