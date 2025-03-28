#include <vector>
#include <iostream>

template<class Collection, class Comparator, typename = typename Collection::size_type>
void insertionSorting(Collection& collection, Comparator comparator) noexcept
{
    for (typename Collection::size_type i = 1; i < collection.size(); i++)
    {
        for (typename Collection::size_type j = i; (j > 0) && (comparator(collection[j], collection[j - 1])); j--)
        {
            std::swap(collection[j], collection[j - 1]);
        }
    }
}

template<class Collection, typename = typename Collection::size_type>
void insertionSorting(Collection& collection) noexcept
{
    bool was_sorted = true;
    for (typename Collection::size_type i = 1; i < collection.size(); i++)
    {
        for (typename Collection::size_type j = i; j > 0; j--)
        {
            if(collection[j] < collection[j - 1])
            {
                std::swap(collection[j], collection[j - 1]);
                was_sorted = false;
            }
        }
        if (was_sorted)
            return;
    }
}

int main()
{
    std::vector<int> vector = { 7,2,9,1,7,2,7,2,6,0,5,6 };
    //std::vector<int> vector = { 1,2,3,4,5,6,7,8,9 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    insertionSorting(vector, [](int a, int b) -> bool { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}