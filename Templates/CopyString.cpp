#include <iostream>

#define SIZE 128

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int main()
{
    char string[SIZE] = "test text for testing!";
    char copy_string[SIZE] = {};

    copy(copy_string, string);

    std::cout << copy_string << "\n";

    return 0;
}

