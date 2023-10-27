#include "main.h"

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to be converted
 */
void print_binary(unsigned long int n)
{
	int i;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = sizeof(n) * 8 - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1)
			_putchar('0');
	}
}
