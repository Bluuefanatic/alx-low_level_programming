#include "main.h"

/**
 * print_char - Writes a character to stdout
 * @c: The character to print
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_number - Prints an integer
 * @n: The integer to print
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);
	print_char(n % 10 + '0');
}

/**
 * add_numbers - Adds two numbers together and returns the result
 * @a: The first number
 * @b: The second number
 * Return: The sum of a and b
 */
int add_numbers(int a, int b)
{
	return (a + b);
}

/**
 * fibonacci - Prints the first 98 Fibonacci numbers
 */
void fibonacci(void)
{
	int i, n1, n2, sum;

	n1 = 1;
	n2 = 2;

	print_number(n1);
	print_char(',');
	print_char(' ');
	print_number(n2);

	for (i = 3; i <= 98; i++)
	{
		sum = add_numbers(n1, n2);
		print_char(',');
		print_char(' ');
		print_number(sum);
		n1 = n2;
		n2 = sum;
	}

	print_char('\n');
}
