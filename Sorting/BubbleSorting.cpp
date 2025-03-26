#include <iostream>
#include <vector>

template<class Collection, class Comparator, typename = typename Collection::size_type>
void bubbleSorting(Collection& collection, Comparator comparator) noexcept
{
    bool was_sorted = true;
    for (typename Collection::size_type i = 0; i < collection.size(); i++)
    {
        for (typename Collection::size_type j = 0; j < collection.size() - 1; j++)
        {
            if (!comparator(collection[j], collection[j + 1]))
            {
                std::swap(collection[j], collection[j + 1]);
                was_sorted = false;
            }
        }

        if (was_sorted)
            return;
    }
}

template<class Collection, typename = typename Collection::size_type>
void bubbleSorting(Collection& collection) noexcept
{
    bool was_sorted = true;
    for (typename Collection::size_type i = 0; i < collection.size(); i++)
    {
        for (typename Collection::size_type j = 0; j < collection.size() - 1; j++)
        {
            if (collection[j] > collection[j + 1])
            {
                std::swap(collection[j], collection[j + 1]);
                was_sorted = false;
            }
        }

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

    bubbleSorting(vector, [](int a, int b) -> bool { return a < b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}