#include <vector>
#include <iostream>

// Only for ordered sets without doubles
template<class Collection>
Collection symmetricDifference(const Collection& leftCollection, const Collection& rightCollection) noexcept
{
    if (leftCollection.empty())
        return rightCollection;
    if (rightCollection.empty())
        return leftCollection;

    const typename Collection::size_type leftLength = leftCollection.size();
    const typename Collection::size_type rightLength = rightCollection.size();

    Collection result;
    result.reserve(leftLength + rightLength);

    typename Collection::size_type leftIndex = 0;
    typename Collection::size_type rightIndex = 0;

    while (leftIndex < leftLength && rightIndex < rightLength)
    {
        if (leftCollection[leftIndex] < rightCollection[rightIndex])
        {
            result.push_back(leftCollection[leftIndex++]);
        }
        else if (leftCollection[leftIndex] > rightCollection[rightIndex])
        {
            result.push_back(rightCollection[rightIndex++]);
        }
        else
        {
            ++leftIndex, ++rightIndex;
        }
    }

    while (leftIndex < leftLength)
    {
        result.push_back(leftCollection[leftIndex++]);
    }

    while (rightIndex < rightLength)
    {
        result.push_back(rightCollection[rightIndex++]);
    }

    return result;
}

int main()
{
    const std::vector<int> leftVector{ 1,2,3,5,8 };
    const std::vector<int> rightVector{ 3,6,8,12,24,47 };

    std::cout << "Left sorted array: ";
    for (const auto& value : leftVector)
        std::cout << value << " ";

    std::cout << "\nRight sorted array: ";
    for (const auto& value : rightVector)
        std::cout << value << " ";

    std::cout << "\nResult: ";
    for (const auto& value : symmetricDifference(leftVector, rightVector))
        std::cout << value << "  ";
    
    return 0;
}