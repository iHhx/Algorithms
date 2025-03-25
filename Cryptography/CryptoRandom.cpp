#include <iostream>
#include <time.h>
#include <string>

static std::size_t next = 1u;
void srandom(std::size_t seed)
{
	next = seed;
}

int random()
{
	next = next * 1103515245 + 12345;
	return (next / 65536) % 32768;
}

uint8_t box[256] = {};
void cryptoSrandom(char* key[], const int key_size)
{
	uint8_t j = 0;
	for(int i = 0; i < 256; i++)
	{
		box[i] = i;
	}
	for (int i = 0; i < 256; i++)
	{
		j = j + box[i] + (uint8_t)key[i % key_size];
		std::swap(box[i], box[j]);
	}
}

void cryptoRandom(char* output[], const int size)
{
	uint8_t i = 1, j = 0, t = 0;

	for (int k = 0; k < size; k++,i++)
	{
		j += box[i];
		std::swap(box[i], box[j]);
		t = box[i] + box[j];
		output[k] = (char*)box[t];
	}
}

int criptoEntropy(char* output[], const int size)
{
	FILE* file = fopen("/dev/random", "rb");

	if (!file)
		return 1;

	fread(output, sizeof(char), size, file);
	fclose(file);
	return 0;
}

int main()
{
	srandom(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << random() << "\n";
	}
	std::cout << "----\n";


	char* key[256];
	//criptoEntropy(key, 256);
	cryptoSrandom(key, 256);

	char* output[BUFSIZ] = {};
	cryptoRandom(output, BUFSIZ);
	for (int i = 0; i < 10; i++)
	{
		std::cout << (int)output[i] << "\n";
	}

	return 0;
}