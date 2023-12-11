#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * _strpbrk - Locates the first occurrence in s of any of the bytes in accept
 * @s: The string to be searched
 * @accept: The string containing the characters to match
 *
 * Return: The pointer to the first occurrence of any character in accept in s, or NULL if no match is found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		if (strchr(accept, *s))
			return (s);
		s++;
	}

	return (NULL);
}
