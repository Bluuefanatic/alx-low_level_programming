#include "main.h"

/**
 * add_digits - Add two digits along with a carry.
 * @digit1: First digit.
 * @digit2: Second digit.
 * @carry: Carry from previous addition.
 *
 * Return: Sum of the digits and carry for next addition.
 */
int add_digits(int digit1, int digit2, int *carry)
{
    int sum = digit1 + digit2 + *carry;
    *carry = sum / 10;
    return sum % 10;
}

/**
 * reverse_string - Reverse a string.
 * @str: String to be reversed.
 */
void reverse_string(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

/**
 * infinite_add - Adds two positive numbers stored as strings.
 * @n1: First number as a string.
 * @n2: Second number as a string.
 * @r: Buffer to store the result.
 * @size_r: Size of the buffer r.
 *
 * Return: Pointer to the result. If the result can't be stored in r, return 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int carry = 0;
    int i = strlen(n1) - 1;
    int j = strlen(n2) - 1;
    int k = 0;

    while (i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? n1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j--] - '0' : 0;

        r[k++] = add_digits(digit1, digit2, &carry) + '0';

        if (k >= size_r - 1)
            return 0; /* Result can't be stored in r */
    }

    if (carry)
        r[k++] = carry + '0';

    r[k] = '\0';
    reverse_string(r);

    return r;
}
