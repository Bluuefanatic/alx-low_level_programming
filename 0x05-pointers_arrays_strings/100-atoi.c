#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handle leading spaces and signs */
	while (s[i] == ' ' || s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	/* Process digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		/* Check for overflow */
		if (result > (INT_MAX - (s[i] - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}

		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
