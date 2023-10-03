#include "main.h"
#include <stdlib.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL if failure.
 */
char **strtow(char *str)
{
	int i, j, word_count = 0, len = 0, start = 0;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			word_count++;
		if (str[i] != ' ')
			len++;
	}

	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; j < word_count; i++)
	{
		if (str[i] != ' ')
		{
			if (i == 0 || str[i - 1] == ' ')
				start = i;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				int k;
				words[j] = malloc((len + 1) * sizeof(char));
				if (words[j] == NULL)
				{
					while (j >= 0)
						free(words[j--]);
					free(words);
					return (NULL);
				}
				for (k = 0; k < len; k++)
					words[j][k] = str[start + k];
				words[j++][k] = '\0';
			}
		}
	}

	words[j] = NULL;
	return (words);
}
