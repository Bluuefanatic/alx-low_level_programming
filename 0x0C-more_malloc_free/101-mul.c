#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Checks if a character is a digit
 * @c: Character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

/**
 * multiply - Multiplies two positive numbers represented as strings
 * @num1: First number
 * @num2: Second number
 *
 * Return: Pointer to the result of the multiplication
 */
char *multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry = 0, product;
    char *result, *temp_result;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    result = malloc(sizeof(char) * (len1 + len2 + 1));
    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = len1 + len2 - 1; i >= 0; i--)
        result[i] = '0';

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i + j + 1] = carry + '0';
    }

    temp_result = result;
    while (*temp_result == '0')
        temp_result++;

    return temp_result;
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3 || !(_isdigit(*argv[1]) && _isdigit(*argv[2])))
    {
        printf("Error\n");
        exit(98);
    }

    result = multiply(argv[1], argv[2]);
    printf("%s\n", result);
    free(result);

    return 0;
}
