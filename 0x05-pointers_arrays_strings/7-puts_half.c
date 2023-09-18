#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: Pointer to the string.
 */
void puts_half(char *str)
{
	int length = 0;
	int i, start;

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	/* Calculate the starting index for printing */
	if (length % 2 == 0)
		start = length / 2;
	else
		start = (length - 1) / 2;

	/* Print the second half of the string */
	for (i = start; i < length; i++)
		_putchar(str[i]);

	_putchar('\n');
}
