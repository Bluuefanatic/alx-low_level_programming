#include "main.h"
#include <stddef.h>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to be converted
 */
void print_binary(unsigned long int n)
{
    size_t i;
    unsigned long int mask = 1UL << (sizeof(n) * 8 - 1);

    if (n == 0)
    {
        _putchar('0');
        return;
    }

    for (i = 0; i < sizeof(n) * 8; i++)
    {
        if (n & mask)
            _putchar('1');
        else
            _putchar('0');
        mask >>= 1;
    }
}
