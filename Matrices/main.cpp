#include "DiagonalMatrix.hpp"
#include "Matrix.hpp"
int main()
{
    int **matrix;
    int *flattenedMatrix;
    size_t rows = 2;
    size_t columns;
    std::cout << "Enter rows: ";
    std::cin >> rows;
    std::cout << "Enter columns: ";
    std::cin >> columns;

    matrix = new int *[rows];
    flattenedMatrix = new int[rows];

    matComm::getInput(matrix, rows, rows);
    matComm::displayMatrix(const_cast<const int **>(matrix), rows, rows);

    if (rows == columns)
    {
        if (diagMat::isDiagonal(const_cast<const int **>(matrix), rows))
        {
            flattenedMatrix = diagMat::getDiagonalElements(const_cast<const int **>(matrix), flattenedMatrix, rows);
            matComm::displayArray(const_cast<const int *>(flattenedMatrix), rows);
        }
        else
        {
            std::cout << "Entered matrix is not a diagonal matrix";
        }
    }
    else
    {
        std::cout << "Rows and columns must be same for diagonal matrix";
    }

    delete[] matrix;
    delete[] flattenedMatrix;
}