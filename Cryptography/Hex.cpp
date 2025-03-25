#include <iostream>

void hex(int mode, char* output, int osize, const char* input, int isize)
{
	int num = 0;
	if (mode)
	{
		for (int i = 0, j = 0; i < isize && j < osize - 2; i++, j += 2)
		{
			sprintf((char*)(output + j), "%02x", (uint8_t)input[i]);
		}
	}
	else {
		for (int i = 0, j = 0; j < isize - 1 && i < osize; i++, j += 2)
		{
			int x = sscanf((char*)(input + j), "%2x", &num);
			output[i] = num;
		}
	}
}
int main()
{
	char encoded[100] = {};
	char decoded[10] = {};
	char bytes[10] = { 1, -5, 20, -11, 122, 3, 6, 0, 16, -120 };

	for (int i = 0; i < 10; ++i)
		std::cout << (int)bytes[i] << " ";
	std::cout << "\n";

	hex(1, encoded, 100, bytes, 10);
	std::cout << encoded << "\n";

	hex(0, decoded, 10, encoded, strlen(encoded));

	for (int i = 0; i < 10; ++i)
		std::cout << (int)decoded[i] << " ";
	std::cout << "\n";

	return 0;
}