#include "main.h"

/**
 * print_row - Prints a single row of the times table.
 * @n: The number for which times table row should be printed
 * @row: The row number to print
 */
void print_row(int n, int row)
{
	int j, result;

	for (j = 0; j <= n; j++)
	{
		result = row * j;
		/* ... (same logic as before) */
	}
	_putchar('\n');
}

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number for which times table should be printed
 */
void print_times_table(int n)
{
	int i;

	if (n > 15 || n < 0)
		return;

	for (i = 0; i <= n; i++)
	{
		print_row(n, i);
	}
}
