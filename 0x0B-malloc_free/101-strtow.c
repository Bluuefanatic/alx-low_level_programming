#include "main.h"
#include <stdlib.h>

/**
 * Checks if a character is a space.
 * @param c The character to check.
 * @return 1 if it's a space, otherwise 0.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
/**
 * Counts the number of words in a string.
 * @param str The input string.
 * @return The number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (is_space(*str))
		{
			in_word = 0;
		} else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		str++;
	}

	return (count);
}

/**
 * Splits a string into an array of words.
 * @param str The input string.
 * @return An array of words. The last element is NULL.
 */
char **strtow(char *str)
{
	int num_words;
	char **words;
	int i, j, k;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	if (num_words == 0)
		return (NULL);

	words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str)
	{
		if (!is_space(*str))
		{
			j = 0;
			while (str[j] && !is_space(str[j]))
				j++;
			words[i] = (char *)malloc((j + 1) * sizeof(char));
			if (words[i] == NULL)
			{
				for (k = 0; k < i; k++)
					free(words[k]);
				free(words);
				return (NULL);
			}
			for (k = 0; k < j; k++)
				words[i][k] = str[k];
			words[i][j] = '\0';
			i++;
			str += j;
		} else
		{
			str++;
		}
	}

	words[i] = NULL;

	return (words);
}
