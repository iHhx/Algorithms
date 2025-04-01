#include <iostream>
#include <vector>

void reverseMatrixDiagonals(const std::vector<std::vector<int>>& matrix) noexcept
{
    const size_t matrixSize = matrix.size();
    for (size_t i = 0u; i < matrixSize; i++)
    {
        size_t k = i;
        size_t j = 0u;
        for (; (k >= 0) && (k < matrixSize) && (j < matrixSize); k--,j++)
        {
            std::cout << matrix[k][j] << " ";
        }
        std::cout << "\n";
    }

    for (size_t j = 1u; j < matrixSize; j++)
    {
        size_t k = j;
        size_t i = matrixSize - 1;
        for (; (i >= 0) && (k < matrixSize); i--,k++)
        {
            std::cout << matrix[i][k] << " ";
        }
        std::cout << "\n";
    }
}

// 1
// 5 2
// 9 6 3
// 3 0 7 4
// 4 1 8
// 5 2
// 6

int main()
{

    const std::vector<std::vector<int>> matrix = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 0, 1, 2 },
    { 3, 4, 5, 6 }
    };

    reverseMatrixDiagonals(matrix);
    
    return 0;
}