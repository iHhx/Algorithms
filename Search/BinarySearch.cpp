#include <iostream>
#include <vector>

template<class Collection>
using ValueType = typename Collection::value_type;

template<class Collection>
using SizeType = typename Collection::size_type;

template<class Collection>
int binarySearchNonRecursive(const Collection& col, const ValueType<Collection>& val) noexcept
{
    SizeType<Collection> left = 0u;
    SizeType<Collection> right = col.size() - 1u;
    SizeType<Collection> middle = right / 2;

    while (left <= right)
    {
        if (val > col[middle])
        {
            left = middle + 1;
            middle = left + (right - left) / 2;
        }
        else if (val < col[middle])
        {
            right = middle - 1;
            middle = left + (right - left) / 2;
        }
        else
        {
            return static_cast<int>(middle);
        }
    }
    return -1;
}

template<typename Collection>
int binarySearchRecursive(const Collection& col,
                          const ValueType<Collection>& val,
                          const SizeType<Collection> left,
                          const SizeType<Collection> right) noexcept
{
    const SizeType<Collection> middle = left + (right - left) / 2;

    if (left <= right)
    {
        if (val > col[middle])
        {
            return binarySearchRecursive(col, val, middle + 1, right);
        }
        else if (val < col[middle])
        {
            return binarySearchRecursive(col, val, left, middle - 1);
        }
        else
        {
            return static_cast<int>(middle);
        }
    }
    return -1;
}

int main()
{
    const std::vector<int> vector = { 2,3,7,17,27,44,57,61,87,91 };

    std::cout << "Index: " << binarySearchNonRecursive(vector, 17) << std::endl;
    std::cout << "Index: " << binarySearchRecursive(vector, 61, 0, vector.size()) << std::endl;
    return 0;
}