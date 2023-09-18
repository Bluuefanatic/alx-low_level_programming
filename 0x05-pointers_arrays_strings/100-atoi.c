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
    unsigned int result = 0;
    int sign = 1;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '-')
            sign *= -1;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            if (result > (UINT_MAX / 10))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            result = result * 10 + (s[i] - '0');
        }
        else if (result > 0)
            break;

        i++;
    }

    return sign * result;
}
