#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints digits 0 to 9 followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	i = 48;
	while (i <= 57)
	{
		write(1, &i, 1);
		i++;
	}

	write(1, "\n", 1);

	return (0);
}
