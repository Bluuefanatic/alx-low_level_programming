#include <stdio.h>

/**
 * print_fibonacci - Print the first n Fibonacci numbers.
 * @n: The number of Fibonacci numbers to print.
 *
 * This function prints the first n Fibonacci numbers,
 * starting with 1 and 2, separated by comma and space.
 */
void print_fibonacci(int n)
{
	int i;
	unsigned int fib1 = 1, fib2 = 2, next;

	printf("%u, %u, ", fib1, fib2);

	for (i = 3; i <= n; i++)
	{
		next = fib1 + fib2;
		if (i != n)
			printf("%u, ", next);
		else
			printf("%u", next);

		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	print_fibonacci(98);
	return (0);
}
