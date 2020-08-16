> Date: 07 March 2020
> #  Array representation
Arrays are used to store values of similar type together.

# Initializing an array
In C language, an array of length 'l' can be initialized only in compile time and not during run time.

    void array()
    {
        const int l = 10;
        int A[l];       <-- The above statement will throw a compile 
                                time error
        scanf("%d", &l);
        int arr[l];     <-- The above statement will throw a compile 
                                time error
        int arr2[10];   <-- The above statement works
    }
  
However, in CPP
    
    void array()
    {
        const int A = 10;
        int arr[A];     <-- The above expression is valid
    }

# Dynamic initialization of arrays
*   In CPP and C it is possible to create arrays at run time.
>   You cannot increase the size of an array at run time.

The alternative is to create a new **dynamic array** of larger size of then copy existing elements from the old array.

    void dynamicArray()
    {
        /*<-- CPP language -->*/
        int *P = new int [5]; // Creates an int array of size 5
        delete(P); // de-allocates heap memory

        /*<-- C language -->*/
        int *p = (int*)malloc(5 * sizeof(int));
        free(p);           

        /*<-- Array of Pointers -->*/
        int *arrayOfPointers[3];
        *arrayOfPointers[0] = new int[5];

        int **doublePointer;
        doublePointer = new int*[4];
        doublePointer[0] = new int[5];

    /*   Here the double pointer exists in stack. All the others created with the "new" keyword exist in heap. 
    */

    }

#   Row major formula
  For `A[m][n]` -> m rows and n columns  
  `&A[i][j] = startingAddress + (nxi + j)*sizeofDataType`

#   Column major formula
  `&A[i][j] = startingAddress + (mxj + i)*sizeofDataType`

#  3D array formula
  For `A[l][m][n];`
  ## Row major        
  `A[i][j][k] = startingAddress + (ixmxn + jxn + k)*sizeofDataType`

  ## Column major
  `A[i][j][k] = startingAddress + (kxmxl + jxl + i)*sizeofDataType`

> Date: 07 March 2020
# Array as Abstract Data Type (ADT)