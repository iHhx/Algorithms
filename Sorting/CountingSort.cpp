#include <iostream>
#include <vector>

void countingSort(std::vector<unsigned>& vector) noexcept
{
	if (vector.size() < 2)
					return;

	std::vector<unsigned> temp(101, 0);//for 100 elements
	
	unsigned begin = 100;
	unsigned end = 0;

	for (int i = 0; i < vector.size(); i++)
	{
		begin = std::min(begin, vector[i]);
		end = std::max(end, vector[i]);
		++temp[vector[i]];
	}
	
	for (int i = begin, j = 0; i <= end; i++)
	{
		while (temp[i])
		{
			vector[j++] = i;
			--temp[i];
		}
	}
}

int main() {

	std::vector<unsigned> vector = { 57,3,91,61,2,7,3,2,17,87,7,3 };

	for (const auto& val : vector)
		std::cout << val << " ";
	std::cout << "\n";

	countingSort(vector);

	for (const auto& val : vector)
		std::cout << val << " ";

	return 0;
}