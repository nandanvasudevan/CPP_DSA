/**
 * @file DiagonalMatrix.hpp
 * @author Nandan V (nvpotti.mec@gmail.com)
 * @brief Operations on diagonal matrices.
 * @version 0.1
 * @date Saturday, 22-Aug-2020
 * @copyright Copyright (c) 2020
 */
#ifndef DIAGONAL_MATRIX
#define DIAGONAL_MATRIX
#include <iostream>
namespace diagMat
{
    /**
     * @brief Get the diagonal elements from @c {diagonalMatrix}
     * @param diagonalMatrix Pointer to a diagonal matrix
     * @param matrixSize Size of diagonal matrix. Should be a square.
     * @return int* The array containing the diagonal elements.
     */
    int *getDiagonalElements(const int **diagonalMatrix, size_t matrixSize);
} // namespace diagMat
#endif