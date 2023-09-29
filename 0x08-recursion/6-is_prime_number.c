#include "main.h"

/**
 * is_prime_recursive - Helper function for checking if a number is prime.
 * @n: The number to check.
 * @divisor: The current divisor to check against n.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_recursive(int n, int divisor)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % divisor == 0)
		return (0);

	if (divisor * divisor > n)
		return (1);

	return (is_prime_recursive(n, divisor + 1));
}

/**
 * is_prime_number - Returns 1 if the input integer is a prime number, otherwis
 * @n: The number to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	return (is_prime_recursive(n, 2));
}
