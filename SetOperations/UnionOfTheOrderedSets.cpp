#include <iostream>
#include <vector>

template<class Collection, typename = typename Collection::iterator>
Collection UnionOfTheOrderedSets(Collection& leftCollection, Collection& rightCollection) noexcept
{
    if (leftCollection.empty())
        return rightCollection;
    if(rightCollection.empty())
        return leftCollection;

    const typename Collection::size_type leftLength = leftCollection.size();
    const typename Collection::size_type rightLength = rightCollection.size();

    Collection answer;
    answer.reserve(leftLength + rightLength);

    typename Collection::size_type i = 0;
    typename Collection::size_type j = 0;

    while (i < leftLength || j < rightLength)
    {
        if (i >= leftLength)
        {
            answer.push_back(rightCollection[j++]);
        }
        else if (j >= rightLength)
        {
            answer.push_back(leftCollection[i++]);
        }
        else if (leftCollection[i] <= rightCollection[j])
        {
            answer.push_back(leftCollection[i++]);
        }
        else
        {
            answer.push_back(rightCollection[j++]);
        }
    }
    return answer;
}

int main()
{
    std::vector<int> lVector = { 1,2,3,4,5,6,7,8,9 };
    std::vector<int> rVector = { 1,3,5,7,9 };

    std::cout << "Left sorted array: ";
    for (const auto& value : lVector)
        std::cout << value << " ";

    std::cout << "\nRight sorted array: ";
    for (const auto& value : rVector)
        std::cout << value << " ";

    std::cout << "\nUnion sorted array: ";
    for (const auto& value : UnionOfTheOrderedSets(lVector, rVector))
        std::cout << value << " ";

    return 0;
}