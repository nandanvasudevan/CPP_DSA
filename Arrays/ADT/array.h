#ifndef ARRAY_H
#define ARRAY_H

class Array
{
    private:
        // Size of array
        int size;
        // Length of array
        int length;
        // pointer to created array
        int* A;

        // Overwrites existing value
        bool bOverwrite;
        // Implements FIFO or LIFO - Overwrite should be disabled
        bool bFIFO_LIFO;        

        struct Stats
        {
            float average;
            int sum;
            int max;
            int min;
        }stats;
        
    public:
        Array(int);
        Array(int, bool, bool bOverwrite);
        
        // Member functions
        // Insert an element into the array     
        void display(char, std::string& Message = std::string(""));
        // Insert into a position. Overwrites if enabled.
        void insert(const int pos, const int value);
        // Insert into FIFO or LIFO
        int insert(const int value);
        // Remove value from position
        void remove(const int pos);
        void updateStats();

        int getSize();
        float getAverage();
        int getMax();
        int getMin();
};
#endif