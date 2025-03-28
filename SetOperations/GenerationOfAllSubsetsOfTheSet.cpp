#include <iostream>
#include <vector>

//1 2 3
//1 2
//1 3
//1
//2 3
//2
//3

void generateSubsets(const std::vector<int>& sourceSet, std::vector<int>& subset, std::size_t index) noexcept
{
    if (index == sourceSet.size())
    {
        std::copy(subset.begin(), subset.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
        return;
    }
    else
    {
        subset.push_back(sourceSet.at(index));
        generateSubsets(sourceSet, subset, index + 1);
        subset.pop_back();
        generateSubsets(sourceSet, subset, index + 1);
    }
}

int main()
{
    std::vector<int> subset = {};
    std::vector<int> sourceSet = { 1,2,3 };

    generateSubsets(sourceSet, subset, 0);
    
    return 0;
}