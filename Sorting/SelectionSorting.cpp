#include <iostream>
#include <vector>

template<class Collection, class Comparator, typename = typename Collection::iterator>
void selectionSorting(Collection& collection, Comparator comparator) noexcept
{
    for (typename Collection::size_type i = 0; i < collection.size() - 1; i++)
    {
        typename Collection::size_type index = i;

        for (typename Collection::size_type j = i + 1; j < collection.size(); j++)
        {
            if (comparator(collection[j], collection[index]))
                index = j;
        }

        if (index != i)
            std::swap(collection[i], collection[index]);
    }
}

int main()
{
    std::vector<int> vector = { 3,7,1,5,2,1,1,4,7,2,9,5 };

    std::cout << "Not sorted array:\n";
    for (const auto& value : vector)
        std::cout << value << " ";

    selectionSorting(vector, [](int a, int b) { return a > b; });

    std::cout << "\nSorted array:\n";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}