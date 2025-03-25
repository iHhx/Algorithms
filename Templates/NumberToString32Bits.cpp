#include <iostream>
#include <string>

std::string numberToString8Bit(uint8_t num)
{
	std::string answer;

	for (short bit = 0x80; bit > 0; bit /= 2)
	{
		std::cout << (num & bit ? 1 : 0);
	}
	return answer;
}

std::string numberToString32Bit(std::size_t num)
{
	std::string answer;

	for (std::size_t i = 0u, j = 0; i < 32u; i++)
	{
		answer = ((num >> i) & 1 ? "1" : "0") + answer;
	}
	return answer;
}

int main()
{
	std::cout << numberToString8Bit(205) << "\n";
	std::cout << numberToString32Bit(std::numeric_limits<std::size_t>::max() - 555) << "\n";

	return 0;
}