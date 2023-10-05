#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - Duplicates a string using malloc.
 * @str: The input string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL if insufficient memory.
 */
char *_strdup(char *str)
{
	int len = 0;
	char *dup;
	int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);
}
