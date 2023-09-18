#include "main.h"

/**
 * print_array - Prints n elements of an array of integers.
 * @a: Pointer to the array.
 * @n: Number of elements to print.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('0' + a[i]);

		if (i < n - 1)
		{
			_putchar(',');
			_putchar(' ');
		}
	}

	_putchar('\n');
}

/**
 * main - Test function to print an array.
 *
 * Return: Always 0.
 */
int main(void)
{
	int array[5] = { -198, 298, 402, -1024, 98 };
	print_array(array, 5);
	return (0);
}

