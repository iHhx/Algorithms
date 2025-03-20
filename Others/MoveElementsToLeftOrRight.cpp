#include <iostream>
#include <vector>

void moveElementsToLeftOrRight(std::vector<std::size_t>& vec) noexcept
{
    if (vec.empty())
        return {};
    
    for (decltype(vec)::size_type i = 0u; i < vec.size(); i++)
    {
        if (v[i] & 1)
        {
            if (i == j)
                ++j;
            else
                std::swap(v[i], v[j++]);
        }
    }
}

int main()
{
    std::vector<std::size_t> vec{ 1,2,3,4,5,6,7,8,9 };
    moveElementsToLeftOrRight(vec);

    std::cout << "\nstd::vector<std::size_t> vec{ 1,2,3,4,5,6,7,8,9 };\n";
    std::cout << "-----------\nAnswer:\n";
    copy(v.begin(), v.end(), std::ostream_iterator<std::size_t>(std::cout, " "));
    std::cout << "-----------\n";

    return 0;
}