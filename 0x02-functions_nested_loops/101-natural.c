#include "main.h"

/**
 * sum_of_multiples - Calculates the sum of multiples of 3 or 5 below 1024.
 *
 * This function returns the sum of multiples of 3 or 5 below 1024.
 *
 * Return: The sum of multiples of 3 or 5.
 */
int sum_of_multiples(void)
{
	int sum = 0;

	for (int i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}

	return (sum);
}
