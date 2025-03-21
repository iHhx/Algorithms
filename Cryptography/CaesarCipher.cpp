#include <iostream>
#include <string>

std::string enCaesarCipher(std::string str, std::uint8_t key) noexcept
{
    for (auto& symbol : str)
    {
        if (std::islower(symbol))
        {
            symbol = static_cast<char>((symbol + key) <= 'z'
                ? (symbol + key)
                : (symbol + key) - ('z' - 'a' + 1));
        }
        else if (std::isupper(symbol))
        {
            symbol = static_cast<char>((symbol + key) <= 'Z'
                ? (symbol + key)
                : (symbol + key) - ('Z' - 'A' + 1));
        }
    }
    return str;
}

std::string deCaesarCipher(std::string str, std::uint8_t key) noexcept
{
    for (auto& symbol : str)
    {
        if (std::islower(symbol))
        {
            symbol = static_cast<char>((symbol - key) >= 'a'
                ? (symbol - key)
                : (symbol - key) + ('z' - 'a' + 1));
        }
        else if (std::isupper(symbol))
        {
            symbol = static_cast<char>((symbol - key) >= 'A'
                ? (symbol - key)
                : (symbol - key) + ('Z' - 'A' + 1));
        }
    }
    return str;
}

int main()
{
    const std::uint8_t key = 7;
    const std::string text = "Alexandr";
    const std::string encryptedText = enCaesarCipher(text, key);

    std::cout << "Source text: " << text << std::endl;
    std::cout << "Encrypted text: " << encryptedText << std::endl;
    std::cout << "Decrypted text: " << deCaesarCipher(encryptedText, key) << std::endl;

    return 0;
}