#include "main.h"

/**
 * print_fibonacci - Print the first n Fibonacci numbers
 * @n: The number of Fibonacci numbers to print
 *
 * Description: This function prints the first n Fibonacci numbers,
 * starting with 1 and 2, separated by comma and space.
 */
void print_fibonacci(int n)
{
	int i;
	unsigned long long fib1 = 1, fib2 = 2, next;

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%llu, ");
		else
			printf("%llu");

		next = fib1 + fib2;
		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");
}
