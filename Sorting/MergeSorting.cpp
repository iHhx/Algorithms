#include <vector>
#include <iostream>

template<class Collection>
using SizeType = typename Collection::size_type;

template<class Collection, class Comparator, typename = typename Collection::size_type>
void mergeSorting(Collection& collection, SizeType<Collection> begin, SizeType<Collection> end, Comparator comparator) noexcept
{
    if (end - begin < 2)
        return;

    const SizeType<Collection> middle = (begin + end) / 2;
    mergeSorting(collection, begin, middle, comparator);
    mergeSorting(collection, middle, end, comparator);

    Collection buffer = {};
    buffer.reserve(end - begin);
    SizeType<Collection> left = begin;
    SizeType<Collection> right = middle;

    while (left < middle && right < end)
    {
        if (comparator(collection[left], collection[right]))
        {
            buffer.push_back(collection[left]);
            left++;
        }
        else
        {
            buffer.push_back(collection[right]);
            right++;
        }
    }

    while (left < middle)
    {
        buffer.push_back(collection[left]);
        left++;
    }

    while (right < end)
    {
        buffer.push_back(collection[right]);
        right++;
    }

    std::copy(buffer.begin(), buffer.end(), collection.begin() + begin);
}

template<class Collection, typename = typename Collection::size_type>
void mergeSorting(Collection& collection, SizeType<Collection> begin, SizeType<Collection> end) noexcept
{
    if (end - begin < 2)
        return;

    const SizeType<Collection> middle = (begin + end) / 2;
    mergeSorting(collection, begin, middle);
    mergeSorting(collection, middle, end);

    Collection buffer = {};
    buffer.reserve(end - begin);
    SizeType<Collection> left = begin;
    SizeType<Collection> right = middle;

    while (left < middle && right < end)
    {
        if (collection[left] < collection[right])
        {
            buffer.push_back(collection[left]);
            left++;
        }
        else
        {
            buffer.push_back(collection[right]);
            right++;
        }
    }

    while (left < middle)
    {
        buffer.push_back(collection[left]);
        left++;
    }

    while (right < end)
    {
        buffer.push_back(collection[right]);
        right++;
    }

    std::copy(buffer.begin(), buffer.end(), collection.begin() + begin);
}

int main()
{
    std::vector<int> vector = { 7,9,1,5,8,1,8,3,7,3 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    mergeSorting(vector, 0, vector.size(), [](int a, int b) -> bool { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}