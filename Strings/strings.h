#ifndef STRINGS_H
    #define STRINGS_H

    class String
    {
        private:
            int size;
            int length;            
            char* string;
        public:
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
    };
#endif