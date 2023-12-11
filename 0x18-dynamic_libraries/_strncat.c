#include "main.h"

/**
 * _strncat - Concatenates n characters from two strings
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to concatenate
 *
 * Return: The pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *originalDest = dest;

	while (*dest)
		dest++;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	*dest = '\0';

	return (originalDest);
}
