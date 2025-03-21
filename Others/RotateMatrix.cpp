#include <iostream>
#include <vector>

void rotateMatrixToRight(std::vector<std::vector<int>>& matrix) noexcept
{
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    std::vector<std::vector<int>> result(cols, std::vector<int>(rows, 0));

    auto print2 = [&](std::string str = "") {
        std::cout << str << "\n";
        std::cout << "--\n";
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[0].size(); j++) {
                std::cout << result[i][j] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "--\n";
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][rows - 1 - i] = matrix[i][j];
        }
    }
    print2();
}

void rotateMatrixToLeft(std::vector<std::vector<int>>& matrix) noexcept
{
    const int rows = matrix.size();
    const int cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = i + 1; j < cols; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseMatrix(std::vector<std::vector<int>>& matrix) noexcept
{
    for (auto& row : matrix) {
        reverse(row.begin(), row.end());
    }
}

int main() {

    auto print = [](std::vector<std::vector<int>>& matrix, std::string str = "") {
        std::cout << str;
        std::cout << "\n--\n";
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                std::cout << matrix[i][j] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "--";
    };

	std::vector<std::vector<int>> matrix1 = {
        { 11, 22, 33 },
        { 44, 55, 66 },
        { 77, 88, 99 },
        { 10, 11, 12 },
        { 13, 14, 15 }
    };
    print(matrix1, "\nRotate Matrix To Right:");
    rotateMatrixToRight(matrix1);

    std::vector<std::vector<int>> matrix2 = {
        { 11, 22, 33, 44 },
        { 55, 66, 77, 88 },
        { 99, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    print(matrix2, "\nRotate Matrix To Left:");
    rotateMatrixToLeft(matrix2);
    print(matrix2);

    print(matrix1, "\n\nRreverse Matrix:");
    reverseMatrix(matrix1);
    print(matrix1);

	return 0;
}