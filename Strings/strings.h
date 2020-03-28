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
                /* archive & test;  */             
            }
            int size;
            int length;            
            char* string;
            /* std::string test; */
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

            void saveData(std::string);
            void loadData(std::string);
    };
#endif