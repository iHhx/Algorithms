#include <iostream>
#include <vector>

template<class Collection, class Comparator, typename = typename Collection::iterator>
void selectionSorting(Collection& collection, Comparator comparator) noexcept
{
    bool was_sorted = true;
    for (typename Collection::size_type i = 0; i < collection.size() - 1; i++)
    {
        typename Collection::size_type index = i;
        for (typename Collection::size_type j = i + 1; j < collection.size(); j++)
        {
            if (comparator(collection[j], collection[index]))
            {
                index = j;
                was_sorted = false;
            }
        }

        if (index != i)
            std::swap(collection[i], collection[index]);
        if (was_sorted)
            return;
    }
}

template<class Collection, typename = typename Collection::iterator>
void selectionSorting(Collection& collection) noexcept
{
    bool was_sorted = true;
    for (typename Collection::size_type i = 0; i < collection.size() - 1; i++)
    {
        typename Collection::size_type index = i;
        for (typename Collection::size_type j = i + 1; j < collection.size(); j++)
        {
            if (collection[j] < collection[index])
            {
                index = j;
                was_sorted = false;
            }
        }

        if (index != i)
            std::swap(collection[i], collection[index]);
        if (was_sorted)
            return;
    }
}

int main()
{
    std::vector<int> vector = { 3,7,1,5,2,1,1,4,7,2,9,5 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    selectionSorting(vector, [](int a, int b) -> bool { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}