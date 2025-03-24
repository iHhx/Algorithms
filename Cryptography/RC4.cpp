#include <iostream>

class RC4
{
	uint8_t box[256] = {};
	char txt[512] = {};
	char byt[512] = {};

	const char* key;
	int key_size;

	const char* word;
	int word_size;

public:

	RC4(const char* w, const char* k = "it's a key!")
		: word(w)
		, word_size(strlen(w))
		, key(k)
		, key_size(strlen(k)) {

		uint8_t j = 0;

		for (int i = 0; i < 256; ++i)
		{
			box[i] = i;
		}
		for (int i = 0; i < 256; i++)
		{
			j = j + box[i] + static_cast<uint8_t>(key[i % key_size]);
			std::swap(box[i], box[j]);
		}
		for (int i = 0; i < word_size; i++)
		{
			txt[i] = word[i];
		}
		rc4_generate();
	}
	void rc4_generate()
	{
		uint8_t i = 1, j = 0;
		uint8_t t;
		int k = 0;
		for (int k = 0; k < word_size; k++,i++)
		{
			j += box[i];
			std::swap(box[i], box[j]);
			t = box[i] + box[j];
			byt[k] = (char)box[t];
		}
	}
	void xor_encrypt()
	{
		for (int i = 0; i < word_size; i++)
		{
			txt[i] = txt[i] ^ byt[i % 512];
		}
	}
	void print()
	{
		for (int i = 0; i < word_size; i++)
		{
			std::cout << txt[i] << " ";
		}
		std::cout << "\n";
	}
};

int main(void) {

	RC4 test("Test text for testing...");

	test.print();

	test.xor_encrypt();
	test.print();

	test.xor_encrypt();
	test.print();

	return 0;
}