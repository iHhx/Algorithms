#include <iostream>
#include <vector>

void moveElementsToLeftOrRight(std::vector<std::size_t>& vec) noexcept
{
    if (vec.empty())
        return;

    for (std::size_t i = 0u, j = 0u; i < vec.size(); i++)
    {
        if (vec[i] & 1)
        {
            if (i == j)
                ++j;
            else
                std::swap(vec[i], vec[j++]);
        }
    }
}

int main()
{
    std::vector<std::size_t> vec{ 1,2,3,4,5,6,7,8,9 };
    moveElementsToLeftOrRight(vec);

    std::cout << "\nstd::vector<std::size_t> vec{ 1,2,3,4,5,6,7,8,9 };\n";
    std::cout << "-----------\nAnswer:\n";
    for (const auto val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << "\n-----------\n";
    
    return 0;
}