#include <stddef.h>

/**
 * _strstr - Locates a substring.
 * @haystack: The string to search in.
 * @needle: The substring to find.
 *
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *pattern = needle;

		/* Iterate through both strings while they match */
		while (*haystack != '\0' && *pattern != '\0' && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}

		/* If the pattern string is fully traversed, a match is found */
		if (*pattern == '\0')
			return (start);

		/* Reset haystack to the next character after the start position */
		haystack = start + 1;
	}

	return (NULL); /* Substring not found */
}
