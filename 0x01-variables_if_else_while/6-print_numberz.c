#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0.
 *
 * Return: Always 0 (Success}
 */

#include <unistd.h>

int main(void)
{
    int i;

    i = 48;
    while (i <= 57)
    {
        write(1, &i, 1);
        i++;
    }

    write(1, "\n", 1);

    return (0);
}
