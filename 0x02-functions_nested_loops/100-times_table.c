#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the number of times to print the table
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int result = i * j;
			int tens = result / 10;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');

				if (result < 10)
					_putchar(' ');
			}

			if (tens != 0)
				_putchar(tens + '0');

			_putchar((result % 10) + '0');
		}
		_putchar('\n');
	}
}
