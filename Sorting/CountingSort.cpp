#include <iostream>
#include <vector>

template<class Collection, typename = typename Collection::value_type>
void countingSort(Collection& collection) noexcept
{
	if (collection.size() < 2)
		return;

	static_assert(std::is_unsigned<typename Collection::value_type>::value,
		"Current implementation works only with unsigned types.");

	Collection temp(101, 0);//for 100 elements
	
	std::size_t begin = 100;
	std::size_t end = 0;

	for (typename Collection::size_type i = 0; i < collection.size(); i++)
	{
		typename Collection::value_type temp_value = collection[i] > 100 ? 100 : collection[i];

		begin = std::min(begin, static_cast<std::size_t>(temp_value));
		end = std::max(end, static_cast<std::size_t>(temp_value));

		++temp[temp_value];
	}
	
	for (typename Collection::size_type i = begin, j = 0; i <= end; i++)
	{
		while (temp[i]--)
			collection[j++] = i;
	}
}

int main() {

	std::vector<uint16_t> vector = { 57,3,911,611,2,7,3,2,17,87,7,3 };

	for (const auto& value : vector)
		std::cout << value << " ";
	std::cout << "\n";

	countingSort(vector);

	for (const auto& value : vector)
		std::cout << value << " ";

	return 0;
}