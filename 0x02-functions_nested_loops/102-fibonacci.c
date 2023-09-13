/* main.c */

#include "main.h"
#include <stdio.h> /* Include the necessary header file */

/**
 * print_fibonacci - Print the first n Fibonacci numbers
 * @n: The number of Fibonacci numbers to print
 *
 * Description: This function prints the first n Fibonacci numbers,
 * starting with 1 and 2, separated by comma and space.
 */
void print_fibonacci(int n)
{
    int i;
    unsigned long fib1 = 1, fib2 = 2, next;

    for (i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%lu, ", fib1); /* Use %lu for unsigned long */
        else
            printf("%lu", fib1); /* Use %lu for unsigned long */

        next = fib1 + fib2;
        fib1 = fib2;
        fib2 = next;
    }

    printf("\n");
}
