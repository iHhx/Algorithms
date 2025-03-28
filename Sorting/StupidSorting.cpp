#include <iostream>
#include <vector>

template <class Collection, class Comparator, typename = typename Collection::size_type>
void stupidSorting(Collection& collection, Comparator comparator) noexcept
{
    for (int i = 0; i < static_cast<int>(collection.size() - 1); i++)
    {
        if (comparator(collection[i + 1], collection[i]))
        {
            std::swap(collection[i + 1], collection[i]);
            i = -1;
        }
    }
}

template <class Collection, typename = typename Collection::size_type>
void stupidSorting(Collection& collection) noexcept
{
    for (int i = 0; i < static_cast<int>(collection.size() - 1); i++)
    {
        if (collection[i + 1] < collection[i])
        {
            std::swap(collection[i + 1], collection[i]);
            i = -1;
        }
    }
}

int main()
{
    std::vector<int> vector = { 7,10,1,5,8,1,8,3,7,3 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    stupidSorting(vector, [](int a, int b) -> bool { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}