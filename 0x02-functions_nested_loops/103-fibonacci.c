#include "main.h"

/**
 * find_sum_of_even_fibonacci - Find the sum of even-valued terms in the Fibonacci sequence
 * up to a given limit.
 * @limit: The upper limit for Fibonacci numbers.
 *
 * Return: The sum of even-valued terms.
 */
unsigned long find_sum_of_even_fibonacci(unsigned long limit)
{
    unsigned long fib1 = 1, fib2 = 2, next, sum = 0;

    while (fib2 <= limit)
    {
        if (fib2 % 2 == 0)
            sum += fib2;

        next = fib1 + fib2;
        fib1 = fib2;
        fib2 = next;
    }

    return sum;
}
