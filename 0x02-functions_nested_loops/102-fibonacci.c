#include <stdio.h>

/**
 * print_fibonacci - Prints the first 50 Fibonacci numbers
 */
void print_fibonacci(void)
{
	unsigned int first = 0, second = 1, next;
	int i;

	for (i = 0; i < 50; i++)
	{
		if (i < 49)
			printf("%u, ", first);
		else
			printf("%u\n", first);

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
