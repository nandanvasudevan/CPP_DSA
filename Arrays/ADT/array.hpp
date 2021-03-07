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
        // ~Array();
        
        // Member functions
        int getValue(const int pos);
        // Insert an element into the array     
        void display(char, std::string Message = std::string(""));
        // Insert into a position. Overwrites if enabled.
        void insert(const int pos, const int value);
        // Insert into FIFO or LIFO
        int insert(const int value);
        // Remove value from position
        void remove(const int pos);  
        // Update average, sum, max and min values      
        void updateStats();
        // Reverse the array
        void reverse();
        // Nandan -> Merge arrays
        // 15 Mar 2020
        Array merge(int[], int[], int, int);
        Array merge(Array, Array, bool ignoreDuplicate = false);
        // Nandan -> Union operation
        // 15 Mar 2020
        Array unionOperator(Array, Array);

        // returns true if array is sorted
        bool isSorted();

        float getAverage();
        int getSize();
        int getLength();        
        int getMax();
        int getMin();
        int getSum();
};
#endif
