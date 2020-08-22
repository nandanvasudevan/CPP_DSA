#include "Matrix.hpp"

namespace matComm
{
    void initializeMatrix(int **matrix, const size_t rows, const size_t columns)
    {
        if (rows * columns > 0)
        {
            for (size_t i = 0; i < rows; i++)
            {
                matrix[i] = new int(columns);
            }
        }
        else
        {
            matrix = nullptr;
        }
    }

    void getInput(int **matrix, const size_t rows, const size_t columns)
    {
        initializeMatrix(matrix, rows, columns);
        if (matrix != nullptr)
        {
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < columns; j++)
                {
                    std::cout << "Enter value for matrix[" << i << "][" << j << "]: ";
                    std::cin >> matrix[i][j];
                }
            }
        }
        else
        {
            matrix = nullptr;
        }
    }

    void getInput(int *array, const size_t size)
    {
        if (array != nullptr)
        {
            for (size_t i = 0; i < size; i++)
            {
                std::cout << "Enter value for array[" << i << "]:";
                std::cin >> array[i];
            }
        }
    }

    void displayMatrix(const int **matrix, const size_t rows, const size_t columns)
    {
        if (matrix != nullptr)
        {
            for (size_t i = 0; i < rows; i++)
            {
                for (size_t j = 0; j < columns; j++)
                {
                    std::cout << "Matrix[" << i << "][" << j << "]: " << matrix[i][j] << '\t';
                }
                std::cout << '\n';
            }
        }
    }

    void displayArray(const int *array, const size_t size)
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << "Array[" << i << "]: " << array[i] << '\n';
        }
    }
} // namespace matComm
