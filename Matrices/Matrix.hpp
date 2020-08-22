/**
 * @file Matrix.hpp
 * @author Nandan V (nvpotti.mec@gmail.com)
 * @brief Common functions for matrices.
 * @version 0.1
 * @date Sunday, 23-Aug-2020
 * @copyright Copyright (c) 2020
 */
#include <iostream>
#ifndef MATRIX_COMMON
#define MATRIX_COMMON
namespace matComm
{
    /**
     * @brief Initializes a 2D pointer to matrix with specified @c {rows} and @c {columns}.
     * 
     * @param matrix The 2D pointer to be initialized
     * @param rows Number of rows necessary
     * @param columns Number of columns necessary
     */
    void initializeMatrix(int **matrix, const size_t rows, const size_t columns);

    /**
     * @brief Get input from user to fill the matrix
     * 
     * @param matrix The matrix to be filled
     * @param rows Number of rows in @c {matrix}
     * @param columns Number of columns in @c {matrix}
     */
    void getInput(int **matrix, const size_t rows, const size_t columns);

    /**
     * @brief Get the input from user to fill an array
     * 
     * @param array The array to be filled
     * @param size The size of @c {array}
     */
    void getInput(int *array, const size_t size);

    /**
     * @brief Displays the values in a matrix.
     * 
     * @param matrix The matrix to be displayed
     * @param rows Number of rows in @c {matrix}
     * @param columns Number of columns in @c {matrix}
     */
    void displayMatrix(const int **matrix, const size_t rows, const size_t columns);

    /**
     * @brief Displays the values in the array.
     * 
     * @param array The array to be displayed
     * @param size The size of @c {array}
     */
    void displayArray(const int *array, const size_t size);
} // namespace matComm

#endif