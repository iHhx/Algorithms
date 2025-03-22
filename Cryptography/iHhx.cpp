#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::string enHhx(const std::string& str, int key) noexcept
{
	std::string temp = {};
	std::string Hhs = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	//for (int i = str.size() - 1; i >= 0; i--)
	//{
	//	temp += str[i];
	//}

	std::vector<int> vec = { 1, 27, 38, 42, 50, 69, 72, 87, 99 };
	std::random_shuffle(vec.begin(), vec.end());

	for (std::size_t i = 0u; i < str.size(); i++)
	{
		//std::swap(temp[i], temp[(i + 32) % str.size()]);
		//std::cout << ((i + 3) % str.size()) << "\n";
		if(std::islower(str[i]))
		{
			temp += Hhs[(str[i] - 'a') + 1 + key];
			std::cout << ((str[i] - 'a') + 1 + key) << " ";
		}
		else
		{
			temp += (str[i] - 'A') + 1 + key;
			std::cout << ((str[i] - 'A') + 28 + key) << " ";
		}
	}
	std::string res = {};
	for (std::size_t i = 0u; i < str.size() - 1; i++)
	{
		//std::swap(temp[i], temp[(i + 32) % str.size()]);
		
		int tmp1 = (temp[i] + '0');
		int tmp2 = (temp[i + 1] + '0');
		std::cout << (temp[i] + '0') << "\n";
		if (tmp1 + tmp2 < 53)
		{
			res += Hhs[tmp1 + tmp2];
			i++;
		}
		else
		{
			res+= Hhs[tmp1];
		}
	}

	for (auto k : res)
		//std::cout << k << "\n";

	return temp;
}

int main() {

	std::string e = enHhx("Alexandr", 1);
	//enHhx(e);
	return 0;
}