#include <stdio.h>

/**
 * is_multiple - Checks if a number is a multiple of 3 or 5
 * @n: The number to check
 *
 * Return: 1 if the number is a multiple, 0 otherwise
 */
int is_multiple(int n)
{
	return (n % 3 == 0 || n % 5 == 0);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 0;
	int i;

	for (i = 0; i < 1024; i++)
	{
		if (is_multiple(i))
		{
			sum += i;
		}
	}

	printf("%d\n", sum);

	return (0);
}
