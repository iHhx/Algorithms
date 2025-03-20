#include <iostream>
#include <vector>

std::size_t fibonacci_non_recursive(std::size_t value) noexcept
{
    if (value < 2)
        return value;

    std::vector<std::size_t> arr(value, 0u);
    arr.at(0) = 1u;
    arr.at(1) = 1u;

    for (std::size_t i = 2u; i < value; i++)
    {
        arr.at(i) = arr.at(i - 2u) + arr.at(i - 1u);
    }

    return arr.back();
}

int main()
{
    std::size_t number = 0u;
    while (true)
    {
        std::cout << "\nEnter count elements Fibonacci [5 - 100]:\n";
        std::cin >> number;
        std::cout << "-----------\nAnswer: ";
        number = number < 5 ? 5 : (number > 100 ? 100 : number);
        std::cout << fibonacci_non_recursive(number) << "\n";

        std::cout << "-----------\n";
    }
    

    return 0;
}