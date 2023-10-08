#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int is_valid_number(char *str);
int _strlen(char *s);
void multiply(char *num1, char *num2);

int main(int argc, char *argv[])
{
    int len1, len2, len, i, j;
    int *result;

    if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
    {
        printf("Error\n");
        return 98;
    }

    len1 = _strlen(argv[1]);
    len2 = _strlen(argv[2]);
    len = len1 + len2;
    
    result = calloc(len, sizeof(int));

    if (!result)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            int product = (argv[1][i] - '0') * (argv[2][j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    i = 0;
    while (i < len - 1 && result[i] == 0)
    {
        i++;
    }

    for (; i < len; i++)
    {
        printf("%d", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}

int is_valid_number(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int _strlen(char *s)
{
    int len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return len;
}
