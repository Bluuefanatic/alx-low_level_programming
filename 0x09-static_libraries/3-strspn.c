#include "main.h"

/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Alwayts 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int isAccepted[256] = {0}; /* Assuming ASCII characters */

	/* Mark characters in accept as accepted */
	while (*accept)
	{
		isAccepted[(unsigned char)*accept] = 1;
		accept++;
	}

	/* Count the number of accepted characters at the beginning of s */
	while (isAccepted[(unsigned char)*s])
	{
		count++;
		s++;
	}

	return (count);
}
