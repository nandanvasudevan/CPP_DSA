#include "DiagonalMatrix.hpp"
#include "Matrix.hpp"
int main()
{
    int **matrix = new int *[5];
    int *flattenedMatrix;
    size_t size = 2;
    std::cout << "Enter size of matrix: ";
    std::cin >> size;
    matComm::getInput(matrix, size, size);
    matComm::displayMatrix(const_cast<const int **>(matrix), size, size);
    flattenedMatrix = diagMat::getDiagonalElements(const_cast<const int **>(matrix), size);
    matComm::displayArray(const_cast<const int *>(flattenedMatrix), size);
    delete[] matrix;
    delete flattenedMatrix;
}