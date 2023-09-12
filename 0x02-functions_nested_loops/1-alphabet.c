#include "main.h"

/**
 * print_alphabet - function to print alphabets in lopwercase
 * Return: 0
 */

#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

void print_alphabet(void)
{
    char letter = 'a';

    while (letter <= 'z')
    {
        _putchar(letter);
        letter++;
    }

    _putchar('\n');
}
