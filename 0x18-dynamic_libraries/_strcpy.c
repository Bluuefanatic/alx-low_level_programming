#include "main.h"

/**
 * _strcpy - Copies a string
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: The pointer to the destination buffer.
 */
char *_strcpy(char *dest, char *src)
{
	char *originalDest = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (originalDest);
}
