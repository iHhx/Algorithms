#include <iostream>
#include <vector>
#include <array>

template <class Collection>
using SizeType = typename Collection::size_type;

template <class Collection>
void quickSort(Collection& collection, SizeType<Collection> leftIndex, SizeType<Collection> rightIndex) noexcept
{
    SizeType<Collection> left = leftIndex;
    SizeType<Collection> right = rightIndex;
    SizeType<Collection> key = collection[(leftIndex + rightIndex) / 2];

    while (left <= right)
    {
        while (collection[left] < key) left++;
        while (collection[right] > key) right--;
        if (left <= right)
        {
            if (collection[left] == collection[right]) left++, right--;
            else
                std::swap(collection[left++], collection[right--]);
        }
    }

    if (left < rightIndex)
    {
        quickSort(collection, left, rightIndex);
    }

    if (right > leftIndex)
    {
        quickSort(collection, leftIndex, right);
    }
}

int main()
{
    //std::vector<int> vector = { 7,9,1,5,8,1,8,3,7,3 };
    std::array<int, 10> vector = { 7,9,1,5,8,1,8,3,7,3 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    quickSort(vector, 0, vector.size());

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}