#include <vector>
#include <iostream>

template <typename Collection, typename Comparator, typename = typename Collection::iterator>
void shellSorting(Collection& collection, Comparator comparator) noexcept
{
    for (typename Collection::size_type step = collection.size() / 2; step > 0; step /= 2)
    {
        for (typename Collection::size_type i = 0; i < collection.size(); i++)
        {
            for (typename Collection::size_type j = i; (j > step - 1) && comparator(collection[j], collection[j - step]); j--)
            {
                std::swap(collection[j], collection[j - step]);
            }
        }
    }
}

template <typename Collection, typename = typename Collection::iterator>
void shellSorting(Collection& collection) noexcept
{
    for (typename Collection::size_type step = collection.size() / 2; step > 0; step /= 2)
    {
        for (typename Collection::size_type i = 0; i < collection.size(); i++)
        {
            for (typename Collection::size_type j = i; j > step - 1; j--)
            {
                if(collection[j] < collection[j - step])
                {
                    std::swap(collection[j], collection[j - step]);
                }
            }
        }
    }
}

int main()
{
    std::vector<int> vector = { 7,9,1,5,8,1,8,3,7,3 };

    std::cout << "Not sorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    shellSorting(vector, [](int a, int b) -> bool { return a > b; });

    std::cout << "\nSorted array: ";
    for (const auto& value : vector)
        std::cout << value << " ";

    return 0;
}