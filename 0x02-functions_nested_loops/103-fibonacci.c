#include <stdio.h>

/**
 * print_sum_of_even_fibonacci - Finds and prints the sum of even Fibonacci terms
 */
void print_sum_of_even_fibonacci(void)
{
	unsigned long int first = 1, second = 2, next, sum = 0;

	while (second <= 4000000)
	{
		if (second % 2 == 0)
			sum += second;

		next = first + second;
		first = second;
		second = next;
	}

	printf("%lu\n", sum);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_sum_of_even_fibonacci();
	return (0);
}
