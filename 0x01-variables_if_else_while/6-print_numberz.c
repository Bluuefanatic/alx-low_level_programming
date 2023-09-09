#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0.
 *
 * Return: Always 0 (Success}
 */

int main(void)
{
    int i;

    i = 48;
    while (i <= 57)
    {
        write(1, &i, 1);
        i++;
    }

    return (0);
}
