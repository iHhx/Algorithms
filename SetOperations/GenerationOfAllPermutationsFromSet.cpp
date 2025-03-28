#include <iostream>
#include <vector>

std::size_t factorial(std::size_t num)
{
	if (num < 2)
		return 1;
	return num * factorial(num - 1);
}

template<class T>
void backTrack(std::vector<T>& vector, std::vector<std::vector<T>>& result, std::size_t index = 0)
{
	if (index >= vector.size())
	{
		result.push_back(vector);
		return;
	}
	for (std::size_t i = index; i < vector.size(); i++)
	{
		if (i != index && vector[i] != vector[index])
		{
			std::swap(vector[i], vector[index]);
		}
		backTrack(vector, result, index + 1);
		if (i != index && vector[i] != vector[index])
		{
			std::swap(vector[i], vector[index]);
		}
	}
}

template<class T>
std::vector<std::vector<T>> permute(std::vector<T>& vector)
{
	if (vector.empty())
		return {};

	std::vector<std::vector<T>> result;
	result.reserve(factorial(vector.size()));

	backTrack(vector, result);

	return result;
}

int main()
{
	std::vector<int> vec{ 1,2,3 };

	for (const auto value : permute(vec))
	{
		for (const auto val : value)
		{
			std::cout << val << " ";
		}
		std::cout << "\n";
	}

	return 0;
}