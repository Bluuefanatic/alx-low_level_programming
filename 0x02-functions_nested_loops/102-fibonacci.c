#include <stdio.h>

/**
 * print_fibonacci - Prints the first 50 Fibonacci numbers
 */
void print_fibonacci(void)
{
	unsigned long long int first = 1, second = 2, next;
	int i;

	for (i = 0; i < 50; i++)
	{
		if (i < 49)
			printf("%llu, ", first);
		else
			printf("%llu\n", first);

		next = first + second;
		first = second;
		second = next;
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_fibonacci();
	return (0);
}
