#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments into a single string.
 * @ac: The number of arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0;
	int total_length = 0;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length needed for the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			total_length++;
		}
		total_length++; /* Account for the newline character */
	}

	/* Allocate memory for the result string */
	result = malloc((total_length + 1) * sizeof(char)); /* +1 for the null*/

	if (result == NULL)
		return (NULL);

	/* Copy the arguments to the result string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[k++] = av[i][j];
		}
		result[k++] = '\n'; /* Add newline character */
	}

	result[k] = '\0'; /* Add null terminator */

	return (result);
}
