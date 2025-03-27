#include <iostream>
#include <vector>

// Only for ordered sets with doubles
template<class Collection>
Collection UnionOfTheOrderedSets(const Collection& leftCollection, const Collection& rightCollection) noexcept
{
    if (leftCollection.empty())
        return rightCollection;
    if(rightCollection.empty())
        return leftCollection;

    const typename Collection::size_type leftLength = leftCollection.size();
    const typename Collection::size_type rightLength = rightCollection.size();

    Collection result;
    result.reserve(leftLength + rightLength);

    typename Collection::size_type leftIndex = 0;
    typename Collection::size_type rightIndex = 0;

    while (leftIndex < leftLength || rightIndex < rightLength)
    {
        if (leftIndex >= leftLength)
        {
            result.push_back(rightCollection.at(rightIndex++));
        }
        else if (rightIndex >= rightLength)
        {
            result.push_back(leftCollection.at(leftIndex++));
        }
        else if (leftCollection.at(leftIndex) <= rightCollection.at(rightIndex))
        {
            result.push_back(leftCollection.at(leftIndex++));
        }
        else
        {
            result.push_back(rightCollection.at(rightIndex++));
        }
    }

    return result;
}

int main()
{
    const std::vector<int> leftVector = { 1,2,3,4,5,6,7,8,9 };
    const std::vector<int> rightVector = { 1,3,5,7,9 };

    std::cout << "Left sorted array: ";
    for (const auto& value : leftVector)
        std::cout << value << " ";

    std::cout << "\nRight sorted array: ";
    for (const auto& value : rightVector)
        std::cout << value << " ";

    std::cout << "\nResult: ";
    for (const auto& value : UnionOfTheOrderedSets(leftVector, rightVector))
        std::cout << value << " ";

    return 0;
}