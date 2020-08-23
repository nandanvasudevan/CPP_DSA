/**
 * @file DiagonalMatrix.cpp
 * @author Nandan V (nvpotti.mec@gmail.com)
 * @brief Operation on diagonal matrices.
 * @version 0.1
 * @date Saturday, 22-Aug-2020
 * @copyright Copyright (c) 2020
 */
#include "DiagonalMatrix.hpp"
#include "Matrix.hpp"
namespace diagMat
{
    int *getDiagonalElements(const int **diagonalMatrix, int *diagonalElements, size_t matrixSize)
    {
        if (diagonalMatrix != nullptr)
        {
            for (size_t i = 0; i < matrixSize; i++)
            {
                diagonalElements[i] = diagonalMatrix[i][i];
            }
        }

        return diagonalElements;
    }

    bool isDiagonal(const int **diagonalMatrix, size_t matrixSize)
    {
        for (size_t i = 0; i < matrixSize; i++)
        {
            for (size_t j = 0; j < matrixSize; j++)
            {
                if ((i != j) && (diagonalMatrix[i][j] != 0))
                {
                    return false;
                }
            }
        }

        return true;
    }
} // namespace diagMat